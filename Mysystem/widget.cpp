#include "widget.h"
#include "ui_widget.h"
#include <QSqlDatabase>
#include <QDebug>
#include <QSqlQuery>
#include <QString>
#include <QCheckBox>
#include <QDatetime>
#include <QComboBox>
#include <QObject>
#include <QTextEdit>
#include <QListWidget>
#include <QMessageBox>
#include "personal.h"
#include "mylog.h"
#include <QWidget>
Widget::Widget(QWidget *parent,QString sno) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    setWindowTitle("学生签到界面");
    this->setWindowIcon(QIcon("://1.png"));
    ui->tableWidget->setAlternatingRowColors(true);
    ui->tableWidget->setStyleSheet("alternate-background-color: yellow;background :white; color :#545fff; ");
    this->sno=sno;
    display("select * from student");
    displayClass();
    displaySno();
    //双击进入新界面
    connect(ui->tableWidget,QTableWidget::cellDoubleClicked,[=](int i,int j)
    {
       Personal *p = new Personal();
       p->init(ui->tableWidget->item(i,0)->text(),ui->tableWidget->item(i,1)->text());  //获取学号
       p->show();
    });
}
//将数据显示到表格中
void Widget::display(QString sql)
{

    QSqlQuery q;
    q.exec(QString("select sno from student where sno = '%1'").arg(sno));
    q.next();
    QString curSno=q.value(0).toString();
    if(q.exec(sql))
    {
        ui->tableWidget->setRowCount(q.size());  //使用tableWidget必须先设置setRowCount
        int i=0;
        while(q.next())
        {
            QCheckBox *c=new QCheckBox("未签到");
            QString sno=q.value(0).toString();

            QSqlQuery q3;
            q3.exec(QString("select signTime from signInfo "
                            "where sno=%1 and date(signTime)=curdate()"
                            " order by signTime desc").arg(sno));
            q3.next();

            if(sno!=curSno)
            {
                c->setDisabled(true);
            }
            if(q3.size())
            {
                c->setText("已签到");
                c->setDisabled(true);
                c->setChecked(true);
                ui->tableWidget->setItem(i,4,new QTableWidgetItem(q3.value(0).toString()));

            }
            ui->tableWidget->setItem(i,0,new QTableWidgetItem(sno));
            ui->tableWidget->setItem(i,1,new QTableWidgetItem(q.value(1).toString()));
            ui->tableWidget->setItem(i,2,new QTableWidgetItem(q.value(2).toString()));
            ui->tableWidget->setCellWidget(i,3,c);

            connect(c,QCheckBox::clicked,[=](){
                //修改控件状态
                c->setText("已签到");
                c->setDisabled(true);
                //向表格中添加签到时间
                ui->tableWidget->setItem(i,4,new QTableWidgetItem(QDateTime::currentDateTime().toString()));
                //向数据库中插入数据
                QSqlQuery q1;
                q1.exec(QString("insert into signInfo values(%1,now())").arg(sno));
                q1.exec(QString("select * from signInfo where sno='%1'").arg(sno));
                q1.next();
                ui->tableWidget->setItem(i,4,new QTableWidgetItem(q1.value(1).toString()));

            });
            i++;
        }
    }
}

void Widget::displayClass()
{
    QSqlQuery q4;
    q4.exec("select distinct class from student");
    ui->comboBox->addItem("全部班级");
    while(q4.next())
    {
        ui->comboBox->addItem(q4.value(0).toString());
    }

    connect(ui->comboBox,QComboBox::currentTextChanged,[=](QString text)
    {
        if(text=="全部班级")
        {
            display("select * from student");
        }
        else
        {
            display(QString("select * from student where class='%1'").arg(text));
        }
    });
}

void Widget::displaySno()
{
    connect(ui->pushButton,QPushButton::clicked,[=](){
        if(ui->lineEdit->text().isEmpty())
        {
            QMessageBox::warning(this,"warn","学号为空");
        }
        else
        {
            display(QString("select * from student where sno like '%1'").arg(ui->lineEdit->text()));
        }
    });
}

Widget::~Widget()
{
    delete ui;
}

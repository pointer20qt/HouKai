#include "mylog.h"
#include "ui_mylog.h"
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
#include "widget.h"
#include "regist.h"
Mylog::Mylog(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Mylog)
{
    ui->setupUi(this);
    setWindowTitle("登录");
    this->setWindowIcon(QIcon("://1.png"));
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    db.setDatabaseName("My_first");
    db.setUserName("root");
    db.setPassword("123456");
    db.open();
}

Mylog::~Mylog()
{
    delete ui;
}

void Mylog::on_pushButton_2_clicked()
{
    this->close();
}

void Mylog::on_pushButton_clicked()
{
    QString user;
    QString pwd;
    user = ui->lineEdit->text();//获取用户名
    pwd = ui->lineEdit_2->text();//获取密码
    Widget *w=new Widget(NULL,user);
    if(user == "")
    {
        QMessageBox::warning(this,"warn","用户名不能为空！");
    }
    else if(pwd == "")
    {
        QMessageBox::warning(this,"warn","密码不能为空！");
    }
    else
    {
        QString s =QString("select * from student where sno='%1' and pwd='%2'").arg(user).arg(pwd);
        QSqlQuery q;
        q.exec(s);
        if(q.first())
        {
            w->show();

            this->close();
        }
        else
        {
            QMessageBox::warning(this,"warn","用户名或密码错误！！！");
        }
    }
}

void Mylog::on_pushButton_3_clicked()
{
    Regist *R= new Regist();
    R->show();
    this->close();
}

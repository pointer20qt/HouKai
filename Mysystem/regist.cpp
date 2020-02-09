#include "regist.h"
#include "ui_regist.h"
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
#include "mylog.h"
Regist::Regist(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Regist)
{
    ui->setupUi(this);
    setWindowTitle("注册");
    this->setWindowIcon(QIcon("://1.png"));
}

Regist::~Regist()
{
    delete ui;
}

void Regist::on_pushButton_2_clicked()
{
    this->close();
}

void Regist::on_pushButton_clicked()
{
    QString user = ui->lineEdit->text();
    QString pwd= ui->lineEdit_2->text();
    QString uname = ui->lineEdit_3->text();
    QString uclass = ui->lineEdit_4->text();
    if(user == "")
        QMessageBox::warning(this,"warn","用户名不能为空!");
    else if(pwd == "")
        QMessageBox::warning(this,"warn","密码不能为空!");
    else
    {
        QString i=QString("insert into student values ('%1','%2','%3','%4')").arg(user).arg(uname).arg(uclass).arg(pwd);
        QString S =QString("select * from student where sno='%1'").arg(user);
        QSqlQuery query;

        if(query.exec(S)&&query.first())
           QMessageBox::warning(this,"warn","用户名重复!");
        else if(query.exec(i))
        {
            QMessageBox::information(this, "successful", "注册成功!");
            Mylog *M=new Mylog();
            M->show();
            this->close();
        }
        else
           QMessageBox::warning(this,"warn","注册失败，请重试!");
    }


}

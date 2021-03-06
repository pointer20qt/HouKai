#include "personal.h"
#include "ui_personal.h"
#include <QSqlQuery>
#include <QDebug>
#include <QString>
#include <QTextCharFormat>
#include <QProgressBar>
Personal::Personal(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Personal)
{
    ui->setupUi(this);
    setWindowTitle("签到统计");
    this->setWindowIcon(QIcon("://1.png"));
}


Personal::~Personal()
{
    delete ui;
}

void Personal::init(QString sno, QString sname)
{
    ui->label->setText("学号："+sno);
    ui->label_2->setText("姓名："+sname);

    QSqlQuery q;
    q.exec(QString("select signTime from signInfo where sno = %1 and date_format(signTime,'%Y-%m')=date_format(curdate(),'%Y-%m')").arg(sno));
    ui->label_3->setText("本月签到次数："+QString::number(q.size()));

    QTextCharFormat f;
    f.setForeground(Qt::blue);
    f.setBackground(Qt::yellow);

    while(q.next())
    {
        ui->calendarWidget->setDateTextFormat(q.value(0).toDate(),f);
    }

}

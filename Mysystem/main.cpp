#include "widget.h"
#include <QApplication>
#include <QSqlDatabase>
#include <QSqlQuery>
#include "mylog.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    /*Widget w;
    w.show();*/
    Mylog M;
    M.show();
    return a.exec();
}

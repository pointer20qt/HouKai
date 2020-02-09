#ifndef MYLOG_H
#define MYLOG_H

#include <QWidget>

namespace Ui {
class Mylog;
}

class Mylog : public QWidget
{
    Q_OBJECT

public:
    explicit Mylog(QWidget *parent = 0);
    ~Mylog();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::Mylog *ui;
};

#endif // MYLOG_H

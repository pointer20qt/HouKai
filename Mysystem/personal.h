#ifndef PERSONAL_H
#define PERSONAL_H

#include <QWidget>

namespace Ui {
class Personal;
}

class Personal : public QWidget
{
    Q_OBJECT

public:
    explicit Personal(QWidget *parent = 0);
    ~Personal();
    void init(QString sno,QString sname);
private:
    Ui::Personal *ui;
};

#endif // PERSONAL_H

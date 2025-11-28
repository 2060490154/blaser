#ifndef GAMMA_1_H
#define GAMMA_1_H

#include <QWidget>

namespace Ui {
class gamma_1;
}

class gamma_1 : public QWidget
{
    Q_OBJECT

public:
    explicit gamma_1(QWidget *parent = 0);
    ~gamma_1();
    int gamma_value();
    void setvalue(float i);

signals:
    void valuechange();

private:
    Ui::gamma_1 *ui;
};

#endif // GAMMA_1_H

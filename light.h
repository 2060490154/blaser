#ifndef LIGHT_H
#define LIGHT_H

#include <QWidget>

namespace Ui {
class light;
}

class light : public QWidget
{
    Q_OBJECT

public:
    explicit light(QWidget *parent = 0);
    ~light();
    int light_value();
    void setvalue(float i);

signals:
    void valuechange();

private:
    Ui::light *ui;
};

#endif // LIGHT_H

#ifndef RGB_H
#define RGB_H

#include <QWidget>

namespace Ui {
class RGB;
}

class RGB : public QWidget
{
    Q_OBJECT

public:
    explicit RGB(QWidget *parent = 0);
    ~RGB();
    int R_value();
    int G_value();
    int B_value();
    void setRGBvalue(float *colornums,int size);
signals:
    void R_change();
    void G_change();
    void B_change();
    void do_auto();


private:
    Ui::RGB *ui;
};

#endif // RGB_H

#ifndef RULERSETTINGS_H
#define RULERSETTINGS_H

#include <QWidget>

namespace Ui {
class rulersettings;
}

class rulersettings : public QWidget
{
    Q_OBJECT

public:
    explicit rulersettings(QWidget *parent = 0);
    ~rulersettings();

signals:
    void rulerparameters(QString pixe,QString height,QString longth);

private:
    Ui::rulersettings *ui;
};

#endif // RULERSETTINGS_H

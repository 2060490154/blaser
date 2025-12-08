#ifndef PFS_H
#define PFS_H

#include <QWidget>

namespace Ui {
class pfs;
}

class pfs : public QWidget
{
    Q_OBJECT

public:
    explicit pfs(QWidget *parent = 0);
    ~pfs();
    int pfs_value();
    void setvalue(float i);

signals:
    void valuechange();

private:
    Ui::pfs *ui;
};

#endif // PFS_H

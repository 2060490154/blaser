#include "dialog.h"
#include "ui_dialog.h"
#include <QSqlDatabase>
#include <QSql>
#include <QDesktopWidget>

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    setWindowTitle("数据库连接");
    QDesktopWidget *desktop = QApplication::desktop();
    move((desktop->width()-this->width())/1.2,(desktop->height()-this->height())/2);
}

Dialog::~Dialog()
{
    delete ui;
}

QString Dialog::databasename() const
{
    return ui->base_line->text();
}

QString Dialog::username() const
{
    return ui->user_line->text();
}

QString Dialog::password() const
{
    return ui->pwdd_line->text();
}

QString Dialog::hostname() const
{
    return ui->IP_line->text();
}

QString Dialog::tablename() const
{
    return ui->table_name->text();
}

int Dialog::port() const
{
    return ui->port_line->text().toInt();
}

void Dialog::on_con_btn_clicked()
{
        QString name1 = tablename();
        QString name2 = databasename();
        QString name3 = username();
        QString name4 = hostname();
        QString name5 = password();
        int name6 = port();
        emit sendtable(name1);
        emit sendSQL(name2);
        emit senduser(name3);
        emit sendhost(name4);
        emit sendpwd(name5);
        emit sendport(name6);
        this->hide();
        emit connect();
}
//QSqlError Dialog::addconnection(const QString &dbname, const QString &host, const QString &user, const QString &passwd, int port)
//{
//    QSqlError err;
//    QSqlDatabase db = QSqlDatabase::addDatabase("QTDS");
//    db.setDatabaseName(dbname);
//    db.setHostName(host);
//    db.setPort(port);
//    if(!db.open(user,passwd))
//    {
//        err = db.lastError();
//        //return err;
//    }
//    return err;
//}


void Dialog::on_cancel_btn_clicked()
{
    this->hide();
}

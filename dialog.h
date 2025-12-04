#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QMessageBox>
#include <QSqlError>


namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = 0);
    ~Dialog();
    QString databasename() const;
    QString username() const;
    QString password() const;
    QString hostname() const;
    int port() const;
//    QSqlError addconnection(const QString &dbname,const QString &host, const QString &user,
//                            const QString &passwd, int port = -1);
    QString tablename() const;

signals:
    void sendtable(QString name);
    void sendSQL(QString name);
    void sendhost(QString name);
    void senduser(QString name);
    void sendpwd(QString name);
    void sendport(int name);
    void connect();

private slots:
    void on_con_btn_clicked();

    void on_cancel_btn_clicked();

private:
    Ui::Dialog *ui;
};

#endif // DIALOG_H

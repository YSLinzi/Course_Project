#ifndef DELSTU_H
#define DELSTU_H

#include <QSqlDatabase>
#include <QSqlQuery>
#include <QDialog>

namespace Ui {
class DelStu;
}

class DelStu : public QDialog
{
    Q_OBJECT

public:
    explicit DelStu(QWidget *parent = nullptr);
    ~DelStu();

signals:
    void getInfo(QString stuClass,QString group_id);
private slots:
    void on_ok_clicked();
    void on_classId_currentTextChanged(const QString &arg1);

private:
    Ui::DelStu *ui;
    QSqlDatabase db;
    QSqlQuery sql_query;
};

#endif // DELSTU_H

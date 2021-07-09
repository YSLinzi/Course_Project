#ifndef CLASSADD_H
#define CLASSADD_H
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QDialog>


namespace Ui {
class ClassAdd;
}

class ClassAdd : public QDialog
{
    Q_OBJECT

public:
    explicit ClassAdd(QWidget *parent = nullptr);
    ClassAdd(QWidget *parent,QString oper);
    ~ClassAdd();
signals:
    void getInfo(QString oClass,QString nClass);
private slots:
    void on_ok_clicked();

private:
    Ui::ClassAdd *ui;
    QSqlDatabase db;
    QSqlQuery sql_query;
    QString Oper;
};

#endif // CLASSADD_H

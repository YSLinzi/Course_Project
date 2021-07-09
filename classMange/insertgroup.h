#ifndef INSERTGROUP_H
#define INSERTGROUP_H

#include <QSqlDatabase>
#include <QSqlQuery>
#include <QDialog>

namespace Ui {
class InsertGroup;
}

class InsertGroup : public QDialog
{
    Q_OBJECT

public:
    explicit InsertGroup(QWidget *parent = nullptr);
    InsertGroup(QWidget *parent,QString oper);
    ~InsertGroup();
    void UpdateInfo(QString txt);

private slots:
    void on_ok_clicked();

    void on_classId_currentTextChanged(const QString &arg1);


signals:
    void getInfo(QString class_id,QString group_id,QString groupOld);

private:
    Ui::InsertGroup *ui;
    QSqlDatabase db;
    QSqlQuery sql_query;
    QString Oper;
};

#endif // INSERTGROUP_H

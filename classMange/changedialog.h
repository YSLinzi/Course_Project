#ifndef CHANGEDIALOG_H
#define CHANGEDIALOG_H

#include <QSqlDatabase>
#include <QSqlQuery>
#include <QDialog>

namespace Ui {
class ChangeDialog;
}

class ChangeDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ChangeDialog(QWidget *parent = nullptr);
    // 构造函数 传值
    ChangeDialog(QWidget *parent,QString stuId,QString name,QString sex,QString stuClass,QString group_id);
    ~ChangeDialog();

private:
    Ui::ChangeDialog *ui;
    QSqlDatabase db;
    QSqlQuery sql_query;

signals:
    void getInfo(QString stuId,QString name,QString sex,QString stuClass,QString group_id);

private slots:
    void on_classId_currentTextChanged(const QString &arg1);
    void on_ok_clicked();
    void on_upClass_clicked();
    void on_upGrp_clicked();
};

#endif // CHANGEDIALOG_H

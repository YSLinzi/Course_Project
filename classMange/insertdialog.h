#ifndef INSERTDIALOG_H
#define INSERTDIALOG_H
#include <QSqlDatabase>
#include <QSqlQuery>

#include <QDialog>

namespace Ui {
class InsertDialog;
}

class InsertDialog : public QDialog
{
    Q_OBJECT

public:
    explicit InsertDialog(QWidget *parent = nullptr);
    ~InsertDialog();

private:
    Ui::InsertDialog *ui;
    QSqlDatabase db;
    QSqlQuery sql_query;

signals:
    void getInfo(QString stuId,QString name,QString sex,QString stuClass,QString group_id);

private slots:
    void on_ok_clicked();
    void on_classId_currentTextChanged(const QString &txt);
};

#endif // INSERTDIALOG_H

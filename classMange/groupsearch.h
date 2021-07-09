#ifndef GROUPSEARCH_H
#define GROUPSEARCH_H
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QDialog>

namespace Ui {
class GroupSearch;
}

class GroupSearch : public QDialog
{
    Q_OBJECT

public:
    explicit GroupSearch(QWidget *parent = nullptr);
    ~GroupSearch();

signals:
    void getInfo(QString class_id,QString group_id);

private slots:
    void on_ok_clicked();

    void on_classId_currentTextChanged(const QString &arg1);

private:
    Ui::GroupSearch *ui;
    QSqlDatabase db;
    QSqlQuery sql_query;
};

#endif // GROUPSEARCH_H

#include "groupsearch.h"
#include "ui_groupsearch.h"
#include <QMessageBox>
#include <QDebug>
#include <QSqlError>

GroupSearch::GroupSearch(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::GroupSearch)
{
    ui->setupUi(this);
    if(QSqlDatabase::contains("qt_sql_default_connection"))
      db = QSqlDatabase::database("qt_sql_default_connection");
    else
      db = QSqlDatabase::addDatabase("QSQLITE");

    QString sql = "select distinct class_id from tb_group order by class_id;";
    sql_query.exec(sql);
    int counts = 1;
    while (sql_query.next()) {
        QString tmp = sql_query.value(0).toString();
        qDebug()<<tmp;
        ui->classId->insertItem(counts,tmp);
        counts++;
    }
}

GroupSearch::~GroupSearch()
{
    delete ui;
}

void GroupSearch::on_ok_clicked()
{
    QString class_id = ui->classId->currentText();
    QString group_id = ui->groupId->currentText();
    emit getInfo(class_id,group_id);
}



void GroupSearch::on_classId_currentTextChanged(const QString &txt)
{
    QString sql= "select distinct group_id from tb_group where class_id=? order by group_id";
    QSqlQuery query;
    query.prepare(sql);
    query.addBindValue(txt);
    int atemp = ui->groupId->count();
    for (; atemp >= 0; atemp--){
        ui->groupId->removeItem (atemp);
    }
    if(query.exec()){
        int counts = 1;
        while (query.next()) {
            QString tmp = query.value(0).toString();
            qDebug()<<tmp;
            ui->groupId->insertItem(counts,tmp);
            counts++;
        }
    }
}

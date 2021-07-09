#include "delstu.h"
#include "ui_delstu.h"
#include <QMessageBox>
#include <QDebug>
#include <QSqlError>

DelStu::DelStu(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DelStu)
{
    ui->setupUi(this);
    if(QSqlDatabase::contains("qt_sql_default_connection"))
      db = QSqlDatabase::database("qt_sql_default_connection");
    else
      db = QSqlDatabase::addDatabase("QSQLITE");

    QString sql = "select distinct class_id from tb_group order by class_id;";
    sql_query.exec(sql);
    int counts = 1;
    while (sql_query.next()){
        QString tmp = sql_query.value(0).toString();
        qDebug()<<tmp;
        ui->classId->insertItem(counts,tmp);
        counts++;
    }
}

DelStu::~DelStu()
{
    delete ui;
}
void DelStu::on_classId_currentTextChanged(const QString &txt)
{
    QString sql= "select group_id from tb_group where class_id=? and group_id>0 order by group_id";
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
void DelStu::on_ok_clicked()
{
    QString class_id = ui->classId->currentText();
    QString group_id = ui->groupId->currentText();
    if(class_id==""||group_id==""){
        QMessageBox::information(NULL,"提示","请选择小组");
        return;
    }
    //删除当前分组
    QString sql = "delete from tb_group where class_id=? and group_id=?";
    sql_query.prepare(sql);
    sql_query.addBindValue(class_id);
    sql_query.addBindValue(group_id);
    if(!sql_query.exec()){
        qDebug()<<"delete error because"<<db.lastError().text();
    }else{
        QMessageBox::information(NULL,"成功","删除小组成功");
        //更新当前信息
        QString txt = ui->classId->currentText();
        QString sql= "select group_id from tb_group where class_id=? and group_id>0 order by group_id";
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
                ui->groupId->insertItem(counts,tmp);
                counts++;
            }
        }
        //将原来属于当前组的学生置为未分组
        emit getInfo(class_id,group_id);
    }
}

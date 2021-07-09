#include "insertgroup.h"
#include "ui_insertgroup.h"
#include <QMessageBox>
#include <QDebug>
#include <QSqlError>

InsertGroup::InsertGroup(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::InsertGroup)
{
    ui->setupUi(this);
}
InsertGroup::InsertGroup(QWidget *parent,QString oper) :
    QDialog(parent),
    Oper(oper),
    ui(new Ui::InsertGroup)
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
        ui->classId->insertItem(counts,tmp);
        counts++;
    }
    if(oper=="add"){
        setWindowTitle("插入班级小组");
        ui->Infolabel->setText("请点击查看班级已有小组");
        ui->Warnlabel->setText("请选择班级并输入要添加的小组组号");
    }else{
        setWindowTitle("修改班级小组");
        ui->Infolabel->setText("请点击选择要修改的班级小组");
        ui->Warnlabel->setText("请选择班级并输入要修改的小组组号");
    }
}

InsertGroup::~InsertGroup()
{
    delete ui;
}

void InsertGroup::on_ok_clicked()
{
    QString class_id = ui->classId->currentText();
    QString group_id = ui->groupId->text();
    QString groupOld = ui->groupCur->currentText();
    QRegExp reg("^[0-9]*[1-9][0-9]*$");
    bool res = reg.exactMatch(group_id);
    if(res==false){
        QMessageBox::information(NULL,"提示","输入的不是非负整数");
        return;
    }else{
        //查询当前小组是否为0，表示是第一个小组
        int s = ui->groupCur->count();
        if(s==0){
            QString sql= "update tb_group set group_id=? where class_id=?";
            QSqlQuery query;
            query.prepare(sql);
            query.addBindValue(group_id);
            query.addBindValue(class_id);
            if(!query.exec()){
               qDebug()<<"update error because "<<db.lastError().text();
            }else{
                QMessageBox::information(NULL,"成功","插入小组成功");
            }
        }else{
           emit getInfo(class_id,group_id,groupOld);
        }
    }
    UpdateInfo(class_id);
}
//更新信息
void InsertGroup::UpdateInfo(QString txt){
    QString sql= "select group_id from tb_group where class_id=? and group_id>0 order by group_id";
    QSqlQuery query;
    query.prepare(sql);
    query.addBindValue(txt);
    int atemp = ui->groupCur->count();
    for (; atemp >= 0; atemp--){
        ui->groupCur->removeItem (atemp);
    }
    if(query.exec()){
        int counts = 1;
        while (query.next()) {
            QString tmp = query.value(0).toString();
            qDebug()<<tmp;
            ui->groupCur->insertItem(counts,tmp);
            counts++;
        }
    }
}

void InsertGroup::on_classId_currentTextChanged(const QString &txt)
{
    UpdateInfo(txt);
}

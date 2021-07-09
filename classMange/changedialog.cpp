#include "changedialog.h"
#include "ui_changedialog.h"
#include <QMessageBox>
#include <QDebug>
#include <QSqlError>

ChangeDialog::ChangeDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ChangeDialog)
{
    ui->setupUi(this);

}
//重载函数
ChangeDialog::ChangeDialog(QWidget *parent,QString stuId,QString name,QString sex,QString stuClass,QString group_id) :
    QDialog(parent),
    ui(new Ui::ChangeDialog)
{
    ui->setupUi(this);
    ui->stuid->setText(stuId);
    ui->classLab->setText(stuClass);
    ui->stuName->setText(name);
    ui->groupLab->setText(group_id);
    if(sex=="男"){
        ui->sex_men->setChecked(true);
    }else{
        ui->sex_woman->setChecked(true);
    }

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

}


ChangeDialog::~ChangeDialog()
{
    delete ui;
}

void ChangeDialog::on_classId_currentTextChanged(const QString &txt)
{
    QString sql= "select group_id from tb_group where class_id=? order by group_id";
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

void ChangeDialog::on_ok_clicked()
{
    QString stuId = ui->stuid->text();
    QString name = ui->stuName->text();
    QString stuClass = ui->classLab->text();
    QString sex;
    if(ui->sex_men->isChecked()){
        sex = "男";
    }else{
        sex = "女";
    }
    QString group_id = ui->groupLab->text();
    emit getInfo(stuId,name,sex,stuClass,group_id);
    ChangeDialog::close();
}

void ChangeDialog::on_upClass_clicked()
{
    //获取当前选中的班级
    QString class_id = ui->classId->currentText();
    ui->classLab->setText(class_id);

}


void ChangeDialog::on_upGrp_clicked()
{
    //获取当前选中的小组
    QString group_id = ui->groupId->currentText();
    ui->groupLab->setText(group_id);
}

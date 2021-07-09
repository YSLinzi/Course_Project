#include "insertdialog.h"
#include "ui_insertdialog.h"
#include <QMessageBox>
#include <QDebug>
#include <QSqlError>

InsertDialog::InsertDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::InsertDialog)
{
    ui->setupUi(this);
    if(QSqlDatabase::contains("qt_sql_default_connection"))
      db = QSqlDatabase::database("qt_sql_default_connection");
    else
      db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("Myclass.db");

    bool ok = db.open();
    if (ok){
       qDebug()<<"database open success";
    }else{
        qDebug()<<"open error because"<<db.lastError().text();
    }

    QString sql = "select distinct class_id from tb_group order by class_id;";
    sql_query.exec(sql);
    int counts = 1;
    while (sql_query.next()) {
        QString tmp = sql_query.value(0).toString();
        ui->classId->insertItem(counts,tmp);
        counts++;
    }
}

InsertDialog::~InsertDialog()
{
    delete ui;
}

void InsertDialog::on_ok_clicked()
{
    QString stuId = ui->stuid->text();
    QString name = ui->stuName->text();
    QString stuClass = ui->classId->currentText();
    QString sex;
    if(stuId==""||name==""||stuClass==""){
        QMessageBox::about(this,tr("错误信息"),tr("添加失败，每一项信息均不能为空"));
        return;
    }
    QRegExp reg("^[0-9]{8,8}$");
    bool res = reg.exactMatch(stuId);
    if(res==false){
        QMessageBox::information(NULL,"提示","输入学号格式错误");
        return;
    }
    if(ui->sex_men->isChecked()){
        sex = "男";
    }else{
        sex = "女";
    }
    QString group_id = ui->groupId->currentText();
    //查询学生信息是否已经存在
    QString sql = "select * from tb_class where stuId=?";
    QSqlQuery query;
    query.prepare(sql);
    query.addBindValue(stuId);
    if(query.exec()){
        if(query.next()){
            QMessageBox::information(NULL,"插入错误","该学生学号已经存在");
        }else{
           emit getInfo(stuId,name,sex,stuClass,group_id);
        }
    }else{
        qDebug()<<"select error because"<<db.lastError().text();
    }
    ui->stuid->clear();
    ui->stuName->clear();
}

void InsertDialog::on_classId_currentTextChanged(const QString &txt)
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

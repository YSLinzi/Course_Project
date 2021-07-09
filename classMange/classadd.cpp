#include "classadd.h"
#include "ui_classadd.h"
#include <QMessageBox>
#include <QDebug>
#include <QSqlError>

ClassAdd::ClassAdd(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ClassAdd)
{
    ui->setupUi(this);
}
ClassAdd::ClassAdd(QWidget *parent,QString oper) :
    QDialog(parent),
    Oper(oper),
    ui(new Ui::ClassAdd)
{
    ui->setupUi(this);
    ui->addClass->setPlaceholderText("格式：X班");
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

    if(oper=="add"){
        setWindowTitle("添加班级");
        ui->labelOper->setText("请输入要添加的班级");
        ui->labelCheck->setText("请点击查看已有班级");
    }else{
        setWindowTitle("修改班级");
       ui->labelOper->setText("请输入新的班级名称");
       ui->labelCheck->setText("请点击选择要修改的班级");
    }
}

ClassAdd::~ClassAdd()
{
    delete ui;
}

void ClassAdd::on_ok_clicked()
{
    //获取当前信息，判断是否为空
    QString class_id = ui->addClass->text();
    if(class_id==""){
        QMessageBox::information(NULL,"提示","班级信息不能为空");
        return;
    }
    //对填写进行校验
    QRegExp reg("([1-9][0-9]|[1-9])班");
    bool res = reg.exactMatch(class_id);
    if(res==false){
        QMessageBox::information(NULL,"提示","班级格式错误");
        return;
    }

    if(Oper=="add"){
        //判断是否已经存在
        QString sql = "select * from tb_group where class_id='"+class_id+"';";
        sql_query.exec(sql);
        if(sql_query.next()){
            QMessageBox::information(NULL,"提示","插入失败，该班级已经存在");
            return;
        }

        //添加班级信息
        sql = "insert into tb_group(group_id,class_id) values(0,?)";
        sql_query.prepare(sql);
        sql_query.addBindValue(class_id);
        if(!sql_query.exec()){
            qDebug()<<"add error because "<<db.lastError().text();
        }else{
           QMessageBox::information(NULL,"成功","添加班级信息成功！");
           //更新当前班级信息
           int atemp = ui->classId->count();
           for (; atemp >= 0; atemp--){
               ui->classId->removeItem (atemp);
           }
           sql = "select distinct class_id from tb_group order by class_id;";
           sql_query.exec(sql);
           int counts = 1;
           while (sql_query.next()) {
               QString tmp = sql_query.value(0).toString();
               ui->classId->insertItem(counts,tmp);
               counts++;
           }
        }
    }else{
        //添加班级信息
        QString sql = "update tb_group set class_id=? where class_id=?";
        sql_query.prepare(sql);
        sql_query.addBindValue(class_id);
        sql_query.addBindValue(ui->classId->currentText());
        if(!sql_query.exec()){
            qDebug()<<"add error because "<<db.lastError().text();
        }else{
           QMessageBox::information(NULL,"成功","修改班级信息成功！");
           emit getInfo(ui->classId->currentText(),class_id);
           //更新当前班级信息
           int atemp = ui->classId->count();
           for (; atemp >= 0; atemp--){
               ui->classId->removeItem (atemp);
           }
           sql = "select class_id from tb_group order by class_id;";
           sql_query.exec(sql);
           int counts = 1;
           while (sql_query.next()) {
               QString tmp = sql_query.value(0).toString();
               ui->classId->insertItem(counts,tmp);
               counts++;
           }
        }
    }
}

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QMessageBox>
#include <QSqlError>
#include <QInputDialog>
#include <QSqlQueryModel>
 #include <QHeaderView>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow){
    ui->setupUi(this);
    setWindowFlags(windowFlags()&~Qt::WindowMaximizeButtonHint); // 禁止最大化按钮
    setFixedSize(this->width(),this->height());
    setWindowTitle("班级管理系统");
    //建立并打开数据库
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("Myclass.db");
    bool ok = db.open();
    if (ok){
       qDebug()<<"database open success";
       showInfo();
    }
    else {
        qDebug()<<"error open database because"<<db.lastError().text();
    }
    //执行数据库查询语句
    ui->tableWidget->setColumnCount(5);
    ui->tableWidget->setRowCount(1);
    ui->tableWidget->setHorizontalHeaderLabels(QStringList()<<"班级"<<"学号"<<"姓名"<<"性别"<<"组号");
    ui->tableWidget->horizontalHeader()->setStyleSheet("QHeaderView::section{background:white}");
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);   //禁止修改
    ui->tableWidget->setShowGrid(true);
    ui->tableWidget->verticalHeader()->setVisible(false);
    ui->tableWidget->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->tableWidget->setSelectionBehavior ( QAbstractItemView::SelectRows); //设置选择行为，以行为单位
    ui->tableWidget->setSelectionMode ( QAbstractItemView::SingleSelection); //设置选择模式，选择单行
    ui->tableWidget->setStyleSheet("selection-background-color:rgb(230,230,250)");


    TotalCount = 0;
    for(int i = 0;i<stu_table.size();i++){
        ui->tableWidget->setItem(TotalCount,0,new QTableWidgetItem( stu_table[i].class_id));
        ui->tableWidget->setItem(TotalCount,1,new QTableWidgetItem( stu_table[i].stuId));
        ui->tableWidget->setItem(TotalCount,2,new QTableWidgetItem( stu_table[i].name));
        ui->tableWidget->setItem(TotalCount,3,new QTableWidgetItem( stu_table[i].sex));
        ui->tableWidget->setItem(TotalCount,4,new QTableWidgetItem( QString("%1").arg(stu_table[i].group_id)));
        ui->tableWidget->verticalHeader()->setVisible(false);   //隐藏列表头
        TotalCount++;
        ui->tableWidget->setRowCount(TotalCount+1);
    }
    //让槽函数deal绑定下拉框切换信号，从而执行不同的功能
    connect(ui->selectBtn,SIGNAL(currentIndexChanged(int)),this,SLOT(deal(int)));
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::showInfo(){
    //插入数据
    QString sql = QString("select * from tb_class;");
    sql_query = db.exec(sql);
    while(sql_query.next()){
        //query指向下一条记录，每执行一次该函数，便指向相邻的下一条记录；
        int id = sql_query.value(0).toInt();
        QString stu_id = sql_query.value(1).toString();
        QString name = sql_query.value(2).toString();
        QString sex = sql_query.value(3).toString();
        QString class_id = sql_query.value(4).toString();
        int group_id = sql_query.value(5).toInt();
        Student* s = new Student(id,stu_id,name,sex,class_id,group_id);
        stu_table.append(*s);
    }
}
void MainWindow::deal(int s){
    //清空表
    if(s==1){
        //按照班级查询
        QString sql="select * from tb_class order by class_id;";
        sql_query.exec(sql);
        doShowTable(sql_query);
    }
    else if(s==2){
        //按照小组查询
        QString sql="select * from tb_class order by class_id,group_id;";
        sql_query.exec(sql);
        doShowTable(sql_query);
    }else{
        //按照全部查询
        QString sql="select * from tb_class;";
        sql_query.exec(sql);
        doShowTable(sql_query);
    }
}
void MainWindow::doShowTable(QSqlQuery sql){
    ui->tableWidget->clearContents();
    TotalCount = 0;
    stu_table.clear();

    while(sql.next()){
        int id = sql.value(0).toInt();
        QString stu_id = sql.value(1).toString();
        QString name = sql.value(2).toString();
        QString sex = sql.value(3).toString();
        QString class_id = sql.value(4).toString();
        int group_id = sql.value(5).toInt();
        Student* s = new Student(id,stu_id,name,sex,class_id,group_id);
        stu_table.append(*s);
    }
    for(int i = 0;i<stu_table.size();i++){
        ui->tableWidget->setItem(TotalCount,0,new QTableWidgetItem( stu_table[i].class_id));
        ui->tableWidget->setItem(TotalCount,1,new QTableWidgetItem( stu_table[i].stuId));
        ui->tableWidget->setItem(TotalCount,2,new QTableWidgetItem( stu_table[i].name));
        ui->tableWidget->setItem(TotalCount,3,new QTableWidgetItem( stu_table[i].sex));
        ui->tableWidget->setItem(TotalCount,4,new QTableWidgetItem( QString("%1").arg(stu_table[i].group_id)));
        ui->tableWidget->verticalHeader()->setVisible(false);   //隐藏列表头
        TotalCount++;
        ui->tableWidget->setRowCount(TotalCount+1);
    }
    if(TotalCount==0){
        ui->tableWidget->setRowCount(TotalCount+1);
        QMessageBox::information(NULL,"提示","暂无结果");
    }
}
/*
 * 查询小组
*/
void MainWindow::groupSearch(QString class_id,QString group_id){
    QString sql = "select * from tb_class where class_id=? and group_id=?";
    sql_query.prepare(sql);
    sql_query.addBindValue(class_id);
    sql_query.addBindValue(group_id);
    if(!sql_query.exec()){
        qDebug()<<"error because"<<db.lastError().text();
    }else{
        ui->tableWidget->clearContents();
        TotalCount = 0;
        stu_table.clear();
        while(sql_query.next()){
            int id = sql_query.value(0).toInt();
            QString stu_id = sql_query.value(1).toString();
            QString name = sql_query.value(2).toString();
            QString sex = sql_query.value(3).toString();
            QString class_id = sql_query.value(4).toString();
            int group_id = sql_query.value(5).toInt();
            Student* s = new Student(id,stu_id,name,sex,class_id,group_id);
            stu_table.append(*s);
        }
        for(int i = 0;i<stu_table.size();i++){
            ui->tableWidget->setItem(TotalCount,0,new QTableWidgetItem( stu_table[i].class_id));
            ui->tableWidget->setItem(TotalCount,1,new QTableWidgetItem( stu_table[i].stuId));
            ui->tableWidget->setItem(TotalCount,2,new QTableWidgetItem( stu_table[i].name));
            ui->tableWidget->setItem(TotalCount,3,new QTableWidgetItem( stu_table[i].sex));
            ui->tableWidget->setItem(TotalCount,4,new QTableWidgetItem( QString("%1").arg(stu_table[i].group_id)));
            ui->tableWidget->verticalHeader()->setVisible(false);   //隐藏列表头
            TotalCount++;
            ui->tableWidget->setRowCount(TotalCount+1);
        }
        if(TotalCount==0){
            ui->tableWidget->setRowCount(TotalCount+1);
            QMessageBox::information(NULL,"提示","暂无查询结果");
        }
    }
}
void MainWindow::on_searchBtn_clicked()
{
    int s = ui->selectBtn->currentIndex();
    bool ok;
    if(s==1){
        //按照班级查询
        QRegExp reg("([1-9][0-9]|[1-9])班");
        QString text = QInputDialog::getText(this,"输入班级","请输入查询的班级:",QLineEdit::Normal,tr("格式：X班"),&ok);
        if(ok){
            bool res = reg.exactMatch(text);
            if(res==false){
                QMessageBox::information(NULL,"提示","班级格式错误");
                deal(1);
            }else{
                QString sql="select * from tb_class where class_id='"+text+"';";
                sql_query.exec(sql);
                doShowTable(sql_query);
           }
        }else{
            qDebug()<<"cancle input";
        }
    }
    else if(s==2){
        //按照小组查询
        groupDlg = new GroupSearch();
        groupDlg->setModal(false);
        groupDlg->show();
        connect(groupDlg,&GroupSearch::getInfo,this,&MainWindow::groupSearch);
    }else{
        //按照 学号查询
        QRegExp reg("^[0-9]{8,8}$");
        QString text = QInputDialog::getText(this,"输入学号","请输入查询的学号:",QLineEdit::Normal,tr("格式：(8位数字)"),&ok);
        if(ok){
            bool res = reg.exactMatch(text);
            if(res==false){
                QMessageBox::information(NULL,"提示","输入学号格式错误");
                deal(0);
            }else{
                QString sql="select * from tb_class where stuId='"+text+"';";
                sql_query.exec(sql);
                doShowTable(sql_query);
           }
        }else{
            qDebug()<<"cancle input";
        }
    }
}
void MainWindow::insertStu(QString stuId,QString name,QString sex,QString stuClass,QString group_id){
    int groups = group_id.toInt();
    stuId = stuId+'#';
    QString sql = "insert into tb_class(stuId,name,sex,class_id,group_id) values(?,?,?,?,?)";
    sql_query.prepare(sql);
    sql_query.addBindValue(stuId);
    sql_query.addBindValue(name);
    sql_query.addBindValue(sex);
    sql_query.addBindValue(stuClass);
    sql_query.addBindValue(groups);
    if(!sql_query.exec()){
        qDebug()<<"insert error because "<<db.lastError().text();
    }else{
        QMessageBox::information(NULL,"成功","添加学生信息成功");
        //获取当前选择的查询选项,重新更新表格信息
        int s = ui->selectBtn->currentIndex();
        deal(s);
        qDebug()<<"insert success";
    }
}
//插入小组
void MainWindow::insertGrp(QString class_id,QString group_id,QString groupOld){
    //查询当前小组是否已经存在
    QString sql;
    sql = "select * from tb_group where group_id=? and class_id=?";
    sql_query.prepare(sql);
    sql_query.addBindValue(group_id);
    sql_query.addBindValue(class_id);
    if(!sql_query.exec()){
        qDebug()<<"insert error because "<<db.lastError().text();
    }else{
        if(!sql_query.next()){
            //不存在，则插入信息
            sql = "insert into tb_group(group_id,class_id) values(?,?)";
            sql_query.prepare(sql);
            sql_query.addBindValue(group_id);
            sql_query.addBindValue(class_id);
            if(!sql_query.exec()){
                qDebug()<<"insert error because "<<db.lastError().text();
            }else{
                QMessageBox::information(NULL,"成功","插入小组成功");
            }
        }else{
             QMessageBox::information(NULL,"错误","插入失败，该小组已经存在");
        }
    }
}
void MainWindow::on_addBtn_clicked()
{
    insertDlg = new InsertDialog();
    insertDlg->setModal(false);
    insertDlg->show();
    connect(insertDlg,&InsertDialog::getInfo,this,&MainWindow::insertStu);
}
//添加小组
void MainWindow::on_updateBtn_clicked()
{
   QString oper = "add";
   insertGrDlg = new InsertGroup(this,oper);
   insertGrDlg->setModal(false);
   insertGrDlg->show();
   connect(insertGrDlg,&InsertGroup::getInfo,this,&MainWindow::insertGrp);
}
//更新学生的信息
void MainWindow::delStu(QString stuClass,QString group_id){
    QString sql="update tb_class set group_id=0 where class_id=? and group_id=?";
    sql_query.prepare(sql);
    sql_query.addBindValue(stuClass);
    sql_query.addBindValue(group_id);
    if(!sql_query.exec()){
      qDebug()<<"update error because "<<db.lastError().text();
    }else{
        qDebug()<<"update success";
    }
    //获取当前选择的查询选项,重新更新表格信息
    for(int row=0; row<ui->tableWidget->rowCount()-1; row++)
    {
        QString classId = ui->tableWidget->item(row, 0)->text();
        QString groupId = ui->tableWidget->item(row,4)->text();
        qDebug()<<classId<<' '<<groupId;
        if(classId==stuClass&&groupId==group_id){
            ui->tableWidget->setItem(row, 4, new QTableWidgetItem("0"));
        }
    }
}
void MainWindow::on_delStu_clicked()
{
    QList<QTableWidgetItem*> items = ui->tableWidget->selectedItems();
    if(!items.empty()){

        QMessageBox::StandardButton rb = QMessageBox::question(NULL, "删除学生信息", "确定要删除吗?", QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
        if(rb == QMessageBox::Yes)
        {
            QString stuId = items.at(1)->text();
            QString name=items.at(2)->text();
            QString sex=items.at(3)->text();
            QString stuClass=items.at(0)->text();
            QString group_id = items.at(4)->text();

            QString sql;
            sql = "delete from tb_class where stuId=? and name=?";
            sql_query.prepare(sql);
            sql_query.addBindValue(stuId);
            sql_query.addBindValue(name);
            if(!sql_query.exec()){
                qDebug()<<"delete error because "<<db.lastError().text();
            }else{
                QMessageBox::information(NULL,"成功","删除成功");
                //删除当前行
                int rowIndex = ui->tableWidget->currentRow();
                if (rowIndex != -1)
                     ui->tableWidget->removeRow(rowIndex);
            }
        }
    }else{
        QMessageBox::warning(this,"警告","请先选择一行再进行删除操作");
    }
}

void MainWindow::on_delGp_clicked()
{
    delDlg = new DelStu();
    delDlg->setModal(false);
    delDlg->show();
    connect(delDlg,&DelStu::getInfo,this,&MainWindow::delStu);
}
//修改学生信息按钮
void MainWindow::on_changeBtn_clicked()
{
    QList<QTableWidgetItem*> items = ui->tableWidget->selectedItems();
    if(!items.empty()){
        QString stuId = items.at(1)->text();
        QString name=items.at(2)->text();
        QString sex=items.at(3)->text();
        QString stuClass=items.at(0)->text();
        QString group_id = items.at(4)->text();
        //传递到修改信息对话框
        changeDlg = new ChangeDialog(this,stuId,name,sex,stuClass,group_id);
        changeDlg->setModal(false);
        changeDlg->show();
        connect(changeDlg,&ChangeDialog::getInfo,this,&MainWindow::changeInfo);

    }else{
        QMessageBox::warning(this,"警告","请先选择一行再进行修改操作");
    }
}
//修改当前选中的学生信息
void MainWindow::changeInfo(QString stuId,QString name,QString sex,QString stuClass,QString group_id){
    QString sql = "update tb_class set name=?,sex=?,class_id=?,group_id=? where stuId=?";
    sql_query.prepare(sql);
    sql_query.addBindValue(name);
    sql_query.addBindValue(sex);
    sql_query.addBindValue(stuClass);
    sql_query.addBindValue(group_id);
    sql_query.addBindValue(stuId);

    if(!sql_query.exec()){
        qDebug()<<"update error because "<<db.lastError().text();
    }else{
        //更新当前表的信息
        int rowIndex = ui->tableWidget->currentRow();
        if (rowIndex != -1){
            ui->tableWidget->setItem(rowIndex, 0, new QTableWidgetItem(stuClass));
            ui->tableWidget->setItem(rowIndex, 2, new QTableWidgetItem(name));
            ui->tableWidget->setItem(rowIndex, 3, new QTableWidgetItem(sex));
            ui->tableWidget->setItem(rowIndex, 4, new QTableWidgetItem(group_id));
        }
    }
}
//添加班级
void MainWindow::on_addClass_clicked()
{
    QString oper = "add";
    classaddDlg = new ClassAdd(this,oper);
    classaddDlg->setModal(false);
    classaddDlg->show();
}
//修改班级
void MainWindow::on_changeClass_clicked()
{
    QString oper = "change";
    ClassAdd* classaddDlg1 = new ClassAdd(this,oper);
    classaddDlg1->setModal(false);
    classaddDlg1->show();
    connect(classaddDlg1,&ClassAdd::getInfo,this,&MainWindow::doChangeClass);
}
void MainWindow::doChangeClass(QString oClass,QString nClass){
    QString sql = "update tb_class set class_id=? where class_id=?";
    sql_query.prepare(sql);
    sql_query.addBindValue(nClass);
    sql_query.addBindValue(oClass);
    if(!sql_query.exec()){
        qDebug()<<"update error because "<<db.lastError().text();
    }else{
        //获取当前选择的查询选项,重新更新表格信息
        for(int row=0; row<ui->tableWidget->rowCount()-1; row++){
            QString classId = ui->tableWidget->item(row, 0)->text();
            if(classId==oClass){
                ui->tableWidget->setItem(row, 0, new QTableWidgetItem(nClass));
            }
        }
    }

}
//修改小组
void MainWindow::on_changeGpBtn_clicked()
{
    QString oper = "change";
    insertGrDlg = new InsertGroup(this,oper);
    insertGrDlg->setModal(false);
    insertGrDlg->show();
    connect(insertGrDlg,&InsertGroup::getInfo,this,&MainWindow::ChangeGrp);
}

void MainWindow::ChangeGrp(QString class_id,QString group_id,QString groupOld){
    QString sql;
    //更新小组表
    sql = "update tb_group set group_id=? where class_id=? and group_id=?";
    sql_query.prepare(sql);
    sql_query.addBindValue(group_id);
    sql_query.addBindValue(class_id);
    sql_query.addBindValue(groupOld);
    if(!sql_query.exec()){
        qDebug()<<"insert error because "<<db.lastError().text();
    }else{
        QMessageBox::information(NULL,"成功","更新小组成功");
        //更新学生表
        sql = "update tb_class set group_id=? where class_id=? and group_id=?";
        sql_query.prepare(sql);
        sql_query.addBindValue(group_id);
        sql_query.addBindValue(class_id);
        sql_query.addBindValue(groupOld);
        if(!sql_query.exec()){
            qDebug()<<"update error because "<<db.lastError().text();
        }else{
            //重新更新表格信息
            for(int row=0; row<ui->tableWidget->rowCount()-1; row++){
                QString classId = ui->tableWidget->item(row, 0)->text();
                QString grouId = ui->tableWidget->item(row,4)->text();
                if(classId==class_id&&groupOld==grouId){
                    ui->tableWidget->setItem(row, 4, new QTableWidgetItem(group_id));
                }
            }
        }
    }
}
/*
 * 删除班级按钮
*/


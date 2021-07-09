#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSqlDatabase>
#include <QSqlQuery>
#include "insertdialog.h"
#include "groupsearch.h"
#include "insertgroup.h"
#include "delstu.h"
#include "changedialog.h"
#include "classadd.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class Student{
    public:
        int id;
        QString stuId;
        QString name;
        QString sex;
        QString class_id;
        int group_id;
        Student(int id,QString stuId,QString name,QString sex,QString class_id,int group_id){
            this->id = id;
            this->stuId = stuId;
            this->name = name;
            this->sex = sex;
            this->class_id = class_id;
            this->group_id = group_id;
        }

};

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void showInfo();
    void doShowTable(QSqlQuery s);

private slots:
    void deal(int s);
    void on_searchBtn_clicked();
    void on_addBtn_clicked();
    void insertStu(QString stuId,QString name,QString sex,QString stuClass,QString group_id);
    void groupSearch(QString class_id,QString group_id);
    void on_updateBtn_clicked();
    void insertGrp(QString class_id,QString group_id,QString groupOld);
    void delStu(QString stuClass,QString group_id);
    void on_delStu_clicked();
    void on_delGp_clicked();

    void on_changeBtn_clicked();

    void changeInfo(QString stuId,QString name,QString sex,QString stuClass,QString group_id);

    void on_addClass_clicked();

    void on_changeClass_clicked();

    void doChangeClass(QString oClass,QString nClass);

    void on_changeGpBtn_clicked();
    void ChangeGrp(QString class_id,QString group_id,QString groupOld);


private:
    Ui::MainWindow *ui;
    QSqlDatabase db;
    QSqlQuery sql_query;
    QVector<Student> stu_table;
    int TotalCount;
    InsertDialog * insertDlg;
    GroupSearch * groupDlg;
    InsertGroup* insertGrDlg;
    DelStu* delDlg;
    ChangeDialog* changeDlg;
    ClassAdd* classaddDlg;
};
#endif // MAINWINDOW_H

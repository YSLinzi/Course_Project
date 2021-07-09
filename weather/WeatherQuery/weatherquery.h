#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTime>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QTimer>
#include <QGraphicsBlurEffect>

#include <QMap>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    QString WeatherType(QString intype);
private slots:
    void update_time();
    void read_cjson(QNetworkReply *repay);
    void on_pushButton_clicked();
    void on_checkButton_clicked();

private:
    Ui::MainWindow *ui;
    QNetworkAccessManager manager;
private:
    QTimer mtime;
    QString city;
    QString date;
     QString week;
    QString high;
    QString low;
    QString fengxiang;
    QString fengli;
    QString type;
    QString ganmao;
    QString temperature;
    double pm2p5;
    QString airQuality;

    QMap<QString,QString> Citys;    //QMap<name,id> Citys
};
#endif // MAINWINDOW_H

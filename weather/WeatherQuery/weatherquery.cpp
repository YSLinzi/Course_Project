#include "weatherquery.h"
#include "ui_weatherquery.h"
#include <QJsonObject>
#include <QJsonArray>
#include <QJsonValue>
#include <QJsonDocument>
#include <QJsonParseError>
#include <QTime>
#include <QDate>
#include <QFile>
#include <QPainter>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    resize(600,450);
    setWindowFlags(windowFlags()&~Qt::WindowMaximizeButtonHint);
    setFixedSize(this->width(),this->height());
    setWindowTitle(tr("天气查询"));
    setWindowIcon(QIcon(":/images/icon.ico"));

    this->setStyleSheet("QMainWindow{background-image: url(:/new/prefix1/images/UI_7.jpg)}");
    //显示系统时间
    //启动定时器
    mtime.start();
    //设置定时时间
    mtime.setInterval(1000);
    //将定时器信号与槽函数相关联，每1s依次执行槽函数
    connect(&mtime,SIGNAL(timeout()),this,SLOT(update_time()));

    //获取cJSON数据
    //发送报文
       QUrl url("http://t.weather.itboy.net/api/weather/city/101280101");

       //管理器manager发送报文后就执行槽函数
        connect(&manager,SIGNAL(finished(QNetworkReply*)),this,SLOT(read_cjson(QNetworkReply*)));
       QNetworkRequest request(url);
       manager.get(request);

       //打开文件对照表
          QFile file("citykeys.txt");
          if(!file.open(QIODevice::ReadOnly))
          {
              qDebug()<<"对照表打开失败";
          }

          qDebug()<<"对照表打开成功";

          QByteArray array;

          while(!file.atEnd())
          {
              QByteArray tmp = file.read(1024);
              array.append(tmp);
          }
          file.close();


          QString cityname = array;     //为什么QString可以等于数组
          QStringList citynamelist = cityname.split(",");  //将cityname中得数据分段，按”，“来分成一段一段


          for(int i=0;i<citynamelist.count();i++)
          {
              QString citycn = citynamelist.at(i);
              citycn.remove("\"");

              QStringList idname = citycn.split(":");

              Citys[idname.at(1)] = idname.at(0);
          }

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::update_time()
{
    //获取当前系统年月日
    QString System_Date = QDate::currentDate().toString("yyyy-MM-dd");
    ui->DateLcdNumber->display(System_Date);
    qDebug()<<System_Date;

    //获取当前系统时分秒
    QString System_Time = QTime::currentTime().toString("hh:mm:ss");
    ui->TimeLcdNumber->display(System_Time);
    qDebug()<<System_Time;
}
QString MainWindow::WeatherType(QString intype)
{
    QString typemsg;
    if(intype == "晴")
    {
       typemsg =  "image: url(:/new/prefix1/images/qing.png)";
    }

    else if(intype == "阴")
    {

        typemsg = "image: url(:/new/prefix1/images/yin.png)";
    }


    else if(intype == "霾")
    {
        typemsg = "image: url(:/new/prefix1/images/mai.png)";
    }

     else if(intype == "雾")
    {
        typemsg = "image: url(:/new/prefix1/images/wu.png)";
    }

     else if(intype == "多云")
    {
        qDebug()<<"hello";
        typemsg = "image: url(:/new/prefix1/images/duoyu.png)";
    }

     else if(intype == "浮尘")
    {
        typemsg = "image: url(:/new/prefix1/images/fuchen.png)";
    }

     else if(intype == "小雨"||"小到中雨")
    {
        typemsg = "image: url(:/new/prefix1/images/xiaoyu.png)";
    }

     else if(intype == "中雨"||"中到大雨")
    {
        typemsg = "image: url(:/new/prefix1/images/zhongyu.png)";
    }

     else if(intype == "阵雨")
    {
        typemsg = "image: url(:/new/prefix1/images/zhenyu.png)";
    }

     else if(intype == "大雨")
    {
        typemsg = "image: url(:/new/prefix1/images/dayu.png)";
    }

     else if(intype == "雷阵雨")
    {
        typemsg = "image: url(:/new/prefix1/images/leizhenyu.png)";
    }

     else if(intype == "雨夹雪")
    {
        typemsg = "image: url(:/new/prefix1/images/yujiaxue.png)";
    }

     else if(intype == "雷阵雨伴有冰雹")
    {
        typemsg = "image: url(:/new/prefix1/images/bingbao.png)";
    }

     else if(intype == "暴雨")
    {
        typemsg = "image: url(:/new/prefix1/images/baoyu.png)";
    }

     else if(intype == "冻雨")
    {
        typemsg = "image: url(:/new/prefix1/images/dongyu.png)";
    }

     else if(intype == "大暴雨")
    {
        typemsg = "image: url(:/new/prefix1/images/dabaoyu.png)";
    }

     else if(intype == "特大暴雨")
    {
        typemsg = "image: url(:/new/prefix1/images/tedabaoyu.png)";
    }

     else if(intype == "小雪")
    {
        typemsg = "image: url(:/new/prefix1/images/xiaoxue.png)";
    }

     else if(intype == "阵雪")
    {
        typemsg = "image: url(:/new/prefix1/images/zhenxue.png)";
    }

     else if(intype == "中雪")
    {
        typemsg = "image: url(:/new/prefix1/images/zhongxue.png)";
    }

     else if(intype == "大雪")
    {
        typemsg = "image: url(:/new/prefix1/images/daxue.png)";
    }

     else if(intype == "暴雪")
    {
        typemsg = "image: url(:/new/prefix1/images/baoxue.png)";
    }

     else if(intype == "扬沙")
    {
        typemsg = "image: url(:/new/prefix1/images/yangsha.png)";
    }


     else if(intype == "强沙尘暴")
    {
        typemsg = "image: url(:/new/prefix1/images/shachenbao.png)";
    }

    return typemsg;

}
void MainWindow::read_cjson(QNetworkReply *reply)
{

    QString buf = reply->readAll();    //先把cJOSN数据放入一个缓冲区buf中，定义为字符串类型

    //判断是否为cjson数据
    QJsonParseError err;
                                               //将buf中的数据转换为UTF-8供系统识别
    QJsonDocument doc = QJsonDocument::fromJson(buf.toUtf8(),&err);
    if(err.error != QJsonParseError::NoError)
    {
        qDebug()<<"格式错误";
        return ;
    }

    qDebug()<<"应答CJSON格式正确";              //接收回来的cJOSn数据格式是正确的

    QJsonObject obj = doc.object();  //用obj这个量来指向命名cJOSN数据的根，以后要找根目录，就找obj就可以了

    QJsonObject data = obj.value("data").toObject();    //在obj根目录下找到“data”第一子根，用data指向命名
    QJsonObject cityInfo = obj.value("cityInfo").toObject();

    city = cityInfo.value("city").toString();   //在data第一子根中找到“city”，用city来指向命名
                                            //toString()的作用就是把city中的数据用字符串类型提取出来

    //显示城市
    ui->CityLabel->setText(city);     //将字符串city中的城市信息在ui界面上的Label控件中显示出来

    QJsonArray forecast = data.value("forecast").toArray();  //用一个数组来指向命名“forecast”第二子根

    QJsonObject zero = forecast.at(0).toObject();       //在“forecast”中找到第0号元素

    date = zero.value("date").toString();       //在第0号元素中提示“date”中字符串出来，将日期字符串放在data变量中

    ganmao = data.value("ganmao").toString();

    temperature = data.value("wendu").toString();
    temperature += "℃";

    //显示温度
    ui->TemperatureLabel->setText(temperature);

    ui->IndexLabel->setText("感冒指数");
    ui->IndexLabel->setWordWrap(1);      //自动换行
    //显示PM2.5
    pm2p5 = data.value("pm25").toDouble();   //在data第一子根中找到“city”，用city来指向命名
     ui->aqi->setNum(pm2p5);
     qDebug()<<pm2p5;

     //空气质量
     airQuality = data.value("quality").toString();
     ui->airQuality->setText(airQuality);
    //温馨提示
    ui->GanmaoLabel->setText(ganmao);
    ui->GanmaoLabel->setWordWrap(1);                //开启自动换行
    ui->GanmaoLabel->setAlignment(Qt::AlignLeft);    //设置对齐方式

//今天的天气
    high = zero.value("high").toString();
    low = zero.value("low").toString();
    fengxiang = zero.value("fx").toString();
    type = zero.value("type").toString();
    qDebug()<<type;
    fengli = zero.value("fl").toString();
    fengli.remove("<![CDATA[");
    fengli.remove("]]>");

    ui->FengxiangLabel->setText(fengxiang);
    ui->TodayLabel->setText("今天");
    ui->TodayHIghLabel->setText(high);
    ui->TodayLowLabel->setText(low);
    ui->TodayTypeText->setText(type);
    ui->FengliLabel->setText(fengli);

    QString typemsg = WeatherType(type);
    qDebug()<<typemsg;
    ui->TodayTypeLabel->setStyleSheet(typemsg);


//昨天的天气
    QJsonObject yesterday = data.value("yesterday").toObject();
    date = yesterday.value("date").toString();
    week = yesterday.value("week").toString();
    high = yesterday.value("high").toString();
    low = yesterday.value("low").toString();
    type = yesterday.value("type").toString();
    qDebug()<<type;
    ui->YesterdayLabel->setText(date);
     ui->YesterdayWeek->setText(week);
    ui->YesterdayHighLabel->setText(high);
    ui->YesterdayLowLabel->setText(low);
    ui->YesterdayTypeText->setText(type);

    typemsg = MainWindow::WeatherType(type);
    qDebug()<<typemsg;
    ui->YesterdayTypeLabel->setStyleSheet(typemsg);

//明天的天气
    QJsonObject one = forecast.at(1).toObject();
    date = one.value("date").toString();
    week = one.value("week").toString();
    high = one.value("high").toString();
    low = one.value("low").toString();
    type = one.value("type").toString();

    ui->TomorrowLabel->setText(date);
    ui->TomorrowHIghLabel->setText(high);
    ui->TomorrowWeek->setText(week);
    ui->TomorrowLowLabel->setText(low);
    ui->TomorrowTypeText->setText(type);

    typemsg = MainWindow::WeatherType(type);
    ui->TomorrowTypeLabel->setStyleSheet(typemsg);


//后天天气
    QJsonObject two = forecast.at(2).toObject();
    date = two.value("date").toString();
    high = two.value("high").toString();
    week = two.value("week").toString();
    low = two.value("low").toString();
    type = two.value("type").toString();

    ui->AfterTomorrowLabel->setText(date);
    ui->AfterTomorrowHIghLabel->setText(high);
    ui->AfterTomorrowLowLabel->setText(low);
    ui->AfterTomorrowWeek->setText(week);
    ui->AfterTomorrowTypeText->setText(type);

    typemsg = MainWindow::WeatherType(type);
    ui->AfterTomorrowTypeLabel->setStyleSheet(typemsg);


}
void MainWindow::on_pushButton_clicked()
{
    static int num = 0;
        num++;

        if(num == 6)
            num = 1;

        switch(num%9)
        {
        case 1:
                this->setStyleSheet("QMainWindow{background-image: url(:/new/prefix1/images/UI1.png)}");
                break;
        case 2:
                this->setStyleSheet("QMainWindow{background-image: url(:/new/prefix1/images/UI_8.jpg)}");
                break;
        case 3:
                this->setStyleSheet("QMainWindow{background-image: url(:/new/prefix1/images/UI_9.jpg)}");
                break;
        case 4:
                this->setStyleSheet("QMainWindow{background-image: url(:/new/prefix1/images/UI_7.jpg)}");
                break;
        case 5:
                this->setStyleSheet("QMainWindow{background-image: url(:/new/prefix1/images/UI5.jpg)}");
                break;
       }
}

void MainWindow::on_checkButton_clicked()
{
        QString cityname = ui->InputLineEdit->text();  //获取我们在输入框中的内容
        qDebug()<<cityname;     //可打印出来，看看我们在输入框输入的城市名字有没有被获取到
        QString cityid = Citys[cityname];//可根据获取到的城市名字得到对应的城市ID
        qDebug()<<"城市id:"<<cityid;

        QString requesttion = "http://t.weather.itboy.net/api/weather/city/";
        requesttion += cityid;   //在上面的网址中追加一个城市ID号
        qDebug()<<requesttion;   //可将要发出去的网址信息打印出来看看对不对

        //发送报文
        QUrl url(requesttion);     //当一发送报文，就会产生finished()信号，
                                   //执行read_cjson(QNetworkReply*)函数
                                   //解析CJOSON数据，更新ui界面天气指数信息

        QNetworkRequest request(url);
        manager.get(request);
}






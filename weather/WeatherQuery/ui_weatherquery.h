/********************************************************************************
** Form generated from reading UI file 'weatherquery.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WEATHERQUERY_H
#define UI_WEATHERQUERY_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QToolButton *checkButton;
    QLCDNumber *DateLcdNumber;
    QLCDNumber *TimeLcdNumber;
    QLabel *IndexLabel;
    QLabel *YesterdayLabel;
    QLabel *YesterdayHighLabel;
    QLabel *TodayLabel;
    QLabel *TodayHIghLabel;
    QLabel *TomorrowLabel;
    QLabel *TomorrowHIghLabel;
    QLabel *AfterTomorrowLabel;
    QLabel *AfterTomorrowHIghLabel;
    QLabel *CityLabel;
    QLabel *TemperatureLabel;
    QLabel *GanmaoLabel;
    QLabel *YesterdayTypeText;
    QLabel *TodayTypeText;
    QLabel *TomorrowTypeText;
    QLabel *AfterTomorrowTypeText;
    QLabel *YesterdayLowLabel;
    QLabel *TodayLowLabel;
    QLabel *TomorrowLowLabel;
    QLabel *AfterTomorrowLowLabel;
    QLabel *YesterdayTypeLabel;
    QLabel *TodayTypeLabel;
    QLabel *AfterTomorrowTypeLabel;
    QLabel *TomorrowTypeLabel;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QLabel *FengxiangLabel;
    QLabel *FengliLabel;
    QPushButton *pushButton;
    QPushButton *minpushButton;
    QPushButton *closepushButton;
    QLineEdit *InputLineEdit;
    QLabel *aqi;
    QLabel *pm25Text;
    QLabel *airQualityTextlabel;
    QLabel *airQuality;
    QLabel *YesterdayWeek;
    QLabel *TomorrowWeek;
    QLabel *AfterTomorrowWeek;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(595, 546);
        MainWindow->setStyleSheet(QString::fromUtf8("background-color: rgba(255, 255, 255, 0);"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        checkButton = new QToolButton(centralwidget);
        checkButton->setObjectName(QString::fromUtf8("checkButton"));
        checkButton->setGeometry(QRect(330, 10, 31, 31));
        checkButton->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/chaozhao.png);\n"
"background-color: rgba(255, 255, 255, 0);"));
        DateLcdNumber = new QLCDNumber(centralwidget);
        DateLcdNumber->setObjectName(QString::fromUtf8("DateLcdNumber"));
        DateLcdNumber->setGeometry(QRect(10, 10, 61, 23));
        DateLcdNumber->setStyleSheet(QString::fromUtf8("QLCDNumber{\n"
"	font: 75 9pt \"Arial\";\n"
"border-radius:20px;\n"
"}"));
        TimeLcdNumber = new QLCDNumber(centralwidget);
        TimeLcdNumber->setObjectName(QString::fromUtf8("TimeLcdNumber"));
        TimeLcdNumber->setGeometry(QRect(90, 10, 101, 23));
        QFont font;
        font.setFamily(QString::fromUtf8("Arial Unicode MS"));
        font.setPointSize(10);
        TimeLcdNumber->setFont(font);
        TimeLcdNumber->setStyleSheet(QString::fromUtf8("QLCDNumber{\n"
"	border-radius:30px;\n"
"}"));
        TimeLcdNumber->setDigitCount(10);
        IndexLabel = new QLabel(centralwidget);
        IndexLabel->setObjectName(QString::fromUtf8("IndexLabel"));
        IndexLabel->setGeometry(QRect(240, 60, 81, 61));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Arial Rounded MT Bold"));
        font1.setPointSize(10);
        font1.setBold(false);
        font1.setItalic(false);
        font1.setWeight(50);
        IndexLabel->setFont(font1);
        IndexLabel->setStyleSheet(QString::fromUtf8("font: 10pt \"Arial Rounded MT Bold\";"));
        YesterdayLabel = new QLabel(centralwidget);
        YesterdayLabel->setObjectName(QString::fromUtf8("YesterdayLabel"));
        YesterdayLabel->setGeometry(QRect(20, 130, 31, 31));
        YesterdayHighLabel = new QLabel(centralwidget);
        YesterdayHighLabel->setObjectName(QString::fromUtf8("YesterdayHighLabel"));
        YesterdayHighLabel->setGeometry(QRect(30, 270, 81, 16));
        TodayLabel = new QLabel(centralwidget);
        TodayLabel->setObjectName(QString::fromUtf8("TodayLabel"));
        TodayLabel->setGeometry(QRect(170, 130, 111, 31));
        TodayHIghLabel = new QLabel(centralwidget);
        TodayHIghLabel->setObjectName(QString::fromUtf8("TodayHIghLabel"));
        TodayHIghLabel->setGeometry(QRect(170, 270, 81, 16));
        TomorrowLabel = new QLabel(centralwidget);
        TomorrowLabel->setObjectName(QString::fromUtf8("TomorrowLabel"));
        TomorrowLabel->setGeometry(QRect(270, 130, 41, 31));
        TomorrowHIghLabel = new QLabel(centralwidget);
        TomorrowHIghLabel->setObjectName(QString::fromUtf8("TomorrowHIghLabel"));
        TomorrowHIghLabel->setGeometry(QRect(290, 270, 81, 16));
        AfterTomorrowLabel = new QLabel(centralwidget);
        AfterTomorrowLabel->setObjectName(QString::fromUtf8("AfterTomorrowLabel"));
        AfterTomorrowLabel->setGeometry(QRect(400, 120, 31, 51));
        AfterTomorrowHIghLabel = new QLabel(centralwidget);
        AfterTomorrowHIghLabel->setObjectName(QString::fromUtf8("AfterTomorrowHIghLabel"));
        AfterTomorrowHIghLabel->setGeometry(QRect(400, 270, 81, 16));
        CityLabel = new QLabel(centralwidget);
        CityLabel->setObjectName(QString::fromUtf8("CityLabel"));
        CityLabel->setGeometry(QRect(110, 50, 61, 31));
        QFont font2;
        font2.setPointSize(15);
        CityLabel->setFont(font2);
        TemperatureLabel = new QLabel(centralwidget);
        TemperatureLabel->setObjectName(QString::fromUtf8("TemperatureLabel"));
        TemperatureLabel->setGeometry(QRect(10, 50, 81, 31));
        QPalette palette;
        QBrush brush(QColor(35, 35, 35, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        QBrush brush1(QColor(255, 255, 255, 0));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        QBrush brush2(QColor(120, 120, 120, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        TemperatureLabel->setPalette(palette);
        QFont font3;
        font3.setPointSize(20);
        font3.setBold(true);
        font3.setWeight(75);
        TemperatureLabel->setFont(font3);
        TemperatureLabel->setTextFormat(Qt::AutoText);
        GanmaoLabel = new QLabel(centralwidget);
        GanmaoLabel->setObjectName(QString::fromUtf8("GanmaoLabel"));
        GanmaoLabel->setGeometry(QRect(330, 80, 231, 41));
        YesterdayTypeText = new QLabel(centralwidget);
        YesterdayTypeText->setObjectName(QString::fromUtf8("YesterdayTypeText"));
        YesterdayTypeText->setGeometry(QRect(50, 170, 91, 16));
        TodayTypeText = new QLabel(centralwidget);
        TodayTypeText->setObjectName(QString::fromUtf8("TodayTypeText"));
        TodayTypeText->setGeometry(QRect(160, 170, 91, 16));
        TomorrowTypeText = new QLabel(centralwidget);
        TomorrowTypeText->setObjectName(QString::fromUtf8("TomorrowTypeText"));
        TomorrowTypeText->setGeometry(QRect(290, 170, 91, 16));
        AfterTomorrowTypeText = new QLabel(centralwidget);
        AfterTomorrowTypeText->setObjectName(QString::fromUtf8("AfterTomorrowTypeText"));
        AfterTomorrowTypeText->setGeometry(QRect(420, 170, 71, 16));
        YesterdayLowLabel = new QLabel(centralwidget);
        YesterdayLowLabel->setObjectName(QString::fromUtf8("YesterdayLowLabel"));
        YesterdayLowLabel->setGeometry(QRect(30, 310, 81, 21));
        TodayLowLabel = new QLabel(centralwidget);
        TodayLowLabel->setObjectName(QString::fromUtf8("TodayLowLabel"));
        TodayLowLabel->setGeometry(QRect(170, 310, 81, 21));
        TomorrowLowLabel = new QLabel(centralwidget);
        TomorrowLowLabel->setObjectName(QString::fromUtf8("TomorrowLowLabel"));
        TomorrowLowLabel->setGeometry(QRect(290, 310, 81, 21));
        AfterTomorrowLowLabel = new QLabel(centralwidget);
        AfterTomorrowLowLabel->setObjectName(QString::fromUtf8("AfterTomorrowLowLabel"));
        AfterTomorrowLowLabel->setGeometry(QRect(400, 310, 91, 21));
        YesterdayTypeLabel = new QLabel(centralwidget);
        YesterdayTypeLabel->setObjectName(QString::fromUtf8("YesterdayTypeLabel"));
        YesterdayTypeLabel->setGeometry(QRect(20, 200, 101, 61));
        TodayTypeLabel = new QLabel(centralwidget);
        TodayTypeLabel->setObjectName(QString::fromUtf8("TodayTypeLabel"));
        TodayTypeLabel->setGeometry(QRect(160, 200, 91, 61));
        AfterTomorrowTypeLabel = new QLabel(centralwidget);
        AfterTomorrowTypeLabel->setObjectName(QString::fromUtf8("AfterTomorrowTypeLabel"));
        AfterTomorrowTypeLabel->setGeometry(QRect(400, 200, 81, 61));
        TomorrowTypeLabel = new QLabel(centralwidget);
        TomorrowTypeLabel->setObjectName(QString::fromUtf8("TomorrowTypeLabel"));
        TomorrowTypeLabel->setGeometry(QRect(290, 200, 81, 61));
        layoutWidget = new QWidget(centralwidget);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(80, 90, 141, 22));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        FengxiangLabel = new QLabel(layoutWidget);
        FengxiangLabel->setObjectName(QString::fromUtf8("FengxiangLabel"));
        FengxiangLabel->setFont(font2);

        horizontalLayout->addWidget(FengxiangLabel);

        FengliLabel = new QLabel(layoutWidget);
        FengliLabel->setObjectName(QString::fromUtf8("FengliLabel"));
        FengliLabel->setFont(font2);

        horizontalLayout->addWidget(FengliLabel);

        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(460, 0, 31, 31));
        pushButton->setMaximumSize(QSize(16777215, 31));
        pushButton->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	border-color: rgb(73, 164, 212);\n"
"	background-color: rgba(255, 255, 255, 0);\n"
"	background-image: url(:/new/prefix1/images/update.png);\n"
"	border-style:solid;\n"
"	border-top-left-radius:1px;\n"
"	border-top-right-radius:1px;\n"
"}\n"
"QPushButton:Pressed{\n"
"	background-image: url(:/new/prefix1/images/update_on.png);\n"
"}"));
        pushButton->setIconSize(QSize(18, 18));
        minpushButton = new QPushButton(centralwidget);
        minpushButton->setObjectName(QString::fromUtf8("minpushButton"));
        minpushButton->setGeometry(QRect(510, 0, 21, 31));
        minpushButton->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/min.png);\n"
"background-color: rgba(255, 255, 255, 0);\n"
"border-top-color: rgba(255, 255, 255, 0);\n"
"border-style:solid;\n"
"	border-top-left-radius:1px;\n"
"	border-top-right-radius:1px;"));
        closepushButton = new QPushButton(centralwidget);
        closepushButton->setObjectName(QString::fromUtf8("closepushButton"));
        closepushButton->setGeometry(QRect(550, 0, 31, 31));
        closepushButton->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/close.png);\n"
"background-color: rgba(255, 255, 255, 0);\n"
"background-color: rgba(255, 255, 255, 0);\n"
"border-style:solid;\n"
"	border-top-left-radius:1px;\n"
"	border-top-right-radius:1px;"));
        InputLineEdit = new QLineEdit(centralwidget);
        InputLineEdit->setObjectName(QString::fromUtf8("InputLineEdit"));
        InputLineEdit->setGeometry(QRect(240, 10, 131, 31));
        InputLineEdit->setStyleSheet(QString::fromUtf8("QLineEdit\n"
"{\n"
"border:1px solid rgb(180, 180, 180);\n"
"background: rgb(230,230,230);\n"
"\n"
"border-radius: 4px;\n"
"\n"
"}\n"
"QLineEdit::hover\n"
"{\n"
"\n"
" //\345\255\227\344\275\223\347\232\204\351\242\234\350\211\262\n"
"\n"
"  color:green\n"
"  border-color:rgb(50,480,40);\n"
"  background-color:green;\n"
"}"));
        aqi = new QLabel(centralwidget);
        aqi->setObjectName(QString::fromUtf8("aqi"));
        aqi->setGeometry(QRect(190, 350, 31, 51));
        QFont font4;
        font4.setPointSize(13);
        font4.setBold(true);
        font4.setWeight(75);
        aqi->setFont(font4);
        pm25Text = new QLabel(centralwidget);
        pm25Text->setObjectName(QString::fromUtf8("pm25Text"));
        pm25Text->setGeometry(QRect(20, 350, 161, 51));
        pm25Text->setFont(font4);
        airQualityTextlabel = new QLabel(centralwidget);
        airQualityTextlabel->setObjectName(QString::fromUtf8("airQualityTextlabel"));
        airQualityTextlabel->setGeometry(QRect(260, 350, 131, 51));
        QFont font5;
        font5.setPointSize(12);
        font5.setBold(true);
        font5.setWeight(75);
        airQualityTextlabel->setFont(font5);
        airQuality = new QLabel(centralwidget);
        airQuality->setObjectName(QString::fromUtf8("airQuality"));
        airQuality->setGeometry(QRect(380, 350, 81, 51));
        QFont font6;
        font6.setPointSize(12);
        airQuality->setFont(font6);
        YesterdayWeek = new QLabel(centralwidget);
        YesterdayWeek->setObjectName(QString::fromUtf8("YesterdayWeek"));
        YesterdayWeek->setGeometry(QRect(60, 130, 81, 31));
        TomorrowWeek = new QLabel(centralwidget);
        TomorrowWeek->setObjectName(QString::fromUtf8("TomorrowWeek"));
        TomorrowWeek->setGeometry(QRect(310, 130, 71, 31));
        AfterTomorrowWeek = new QLabel(centralwidget);
        AfterTomorrowWeek->setObjectName(QString::fromUtf8("AfterTomorrowWeek"));
        AfterTomorrowWeek->setGeometry(QRect(440, 121, 81, 51));
        MainWindow->setCentralWidget(centralwidget);
        DateLcdNumber->raise();
        TimeLcdNumber->raise();
        IndexLabel->raise();
        YesterdayLabel->raise();
        YesterdayHighLabel->raise();
        TodayLabel->raise();
        TodayHIghLabel->raise();
        TomorrowLabel->raise();
        TomorrowHIghLabel->raise();
        AfterTomorrowLabel->raise();
        AfterTomorrowHIghLabel->raise();
        CityLabel->raise();
        TemperatureLabel->raise();
        GanmaoLabel->raise();
        YesterdayTypeText->raise();
        TodayTypeText->raise();
        TomorrowTypeText->raise();
        AfterTomorrowTypeText->raise();
        YesterdayLowLabel->raise();
        TodayLowLabel->raise();
        TomorrowLowLabel->raise();
        AfterTomorrowLowLabel->raise();
        YesterdayTypeLabel->raise();
        TodayTypeLabel->raise();
        AfterTomorrowTypeLabel->raise();
        TomorrowTypeLabel->raise();
        layoutWidget->raise();
        pushButton->raise();
        minpushButton->raise();
        closepushButton->raise();
        InputLineEdit->raise();
        checkButton->raise();
        aqi->raise();
        pm25Text->raise();
        airQualityTextlabel->raise();
        airQuality->raise();
        YesterdayWeek->raise();
        TomorrowWeek->raise();
        AfterTomorrowWeek->raise();
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 595, 21));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);
        QObject::connect(minpushButton, SIGNAL(clicked()), MainWindow, SLOT(showMinimized()));
        QObject::connect(closepushButton, SIGNAL(clicked()), MainWindow, SLOT(close()));

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        checkButton->setText(QString());
        IndexLabel->setText(QString());
        YesterdayLabel->setText(QCoreApplication::translate("MainWindow", "\346\230\250\345\244\251", nullptr));
        YesterdayHighLabel->setText(QCoreApplication::translate("MainWindow", "high", nullptr));
        TodayLabel->setText(QCoreApplication::translate("MainWindow", "\344\273\212\345\244\251", nullptr));
        TodayHIghLabel->setText(QCoreApplication::translate("MainWindow", "high", nullptr));
        TomorrowLabel->setText(QCoreApplication::translate("MainWindow", "\346\230\216\345\244\251", nullptr));
        TomorrowHIghLabel->setText(QCoreApplication::translate("MainWindow", "high", nullptr));
        AfterTomorrowLabel->setText(QCoreApplication::translate("MainWindow", "\345\220\216\345\244\251", nullptr));
        AfterTomorrowHIghLabel->setText(QCoreApplication::translate("MainWindow", "high", nullptr));
        CityLabel->setText(QString());
        TemperatureLabel->setText(QString());
        GanmaoLabel->setText(QCoreApplication::translate("MainWindow", "\346\204\237\345\206\222\346\214\207\346\225\260", nullptr));
        YesterdayTypeText->setText(QCoreApplication::translate("MainWindow", "\345\244\251\346\260\224\347\261\273\345\236\213", nullptr));
        TodayTypeText->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        TomorrowTypeText->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        AfterTomorrowTypeText->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        YesterdayLowLabel->setText(QCoreApplication::translate("MainWindow", "low", nullptr));
        TodayLowLabel->setText(QCoreApplication::translate("MainWindow", "low", nullptr));
        TomorrowLowLabel->setText(QCoreApplication::translate("MainWindow", "low", nullptr));
        AfterTomorrowLowLabel->setText(QCoreApplication::translate("MainWindow", "low", nullptr));
        YesterdayTypeLabel->setText(QString());
        TodayTypeLabel->setText(QString());
        AfterTomorrowTypeLabel->setText(QString());
        TomorrowTypeLabel->setText(QString());
        FengxiangLabel->setText(QCoreApplication::translate("MainWindow", "\351\243\216\345\220\221", nullptr));
        FengliLabel->setText(QCoreApplication::translate("MainWindow", "\351\243\216\345\212\233", nullptr));
        pushButton->setText(QString());
        minpushButton->setText(QString());
        closepushButton->setText(QString());
        aqi->setText(QString());
        pm25Text->setText(QCoreApplication::translate("MainWindow", "PM2.5\346\214\207\346\225\260:", nullptr));
        airQualityTextlabel->setText(QCoreApplication::translate("MainWindow", "\347\251\272\346\260\224\350\264\250\351\207\217", nullptr));
        airQuality->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        YesterdayWeek->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        TomorrowWeek->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        AfterTomorrowWeek->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WEATHERQUERY_H

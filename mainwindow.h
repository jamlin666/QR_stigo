#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSerialPort>
#include <QtDebug>
#include <QtSerialPort/QSerialPortInfo>
#include <QTextCodec>
#include <QTimer>
#include <QMessageBox>
#include <QPainter>
#include <QBitmap>
#include <QBrush>
#include "hmac.h"
#include "md5.h"
#include <QBrush>
#include <QAxObject>
#include <QFile>
#include <QFileDialog>
#include <QMessageBox>
#include <QTime>
#include <QtMath>
#include "admin.h"
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);

    ~MainWindow();
private slots:
    void on_openButton_2_clicked();
    void on_portBox_currentIndexChanged(const QString &arg1);
    void on_openButton_toggled(bool checked);
    void on_lineEdit_textChanged(const QString &arg1);
    void ReciveDate();//数据接收槽函数
    void DealclearSignalsFromAdmin(bool Error,QString str);
    void DealAdminClose();
    void on_openButton_3_clicked();
    void on_openButton_clicked();
    void timer_out();
    void timer2_out();

private:
    void systemInit();//初始化
    QStringList scanSerial();//遍历串口号
    QStringList compiler_port(QStringList staticList,int len);//按照串口号排序
    QByteArray serialport_send(QString str);//数据发送
    void deal_receive(QString str);//数据接收处理 
    void NewExcel(QString filePath);//新建EXCEL表
    void FillExcel(QString data,int rows);//EXCEL表填充
    void CloseAndSave(QString filePath);//保存与释放
    double BitCalculation(QByteArray byteData);//byte to
    int SendError();
    void traversalControl(const QObjectList& q);

private:
       Admin *admin;
       QSerialPort globlePort;
       QStringList serialStrList;
       QString portName;
       hmac *acm;
       const int textEdit_length=32;
       const int textStart_pos=11;
       const int textSend_length=10;
       const int SequenceCode=4;
       const uint8_t head[11]={0x5a,0xa5,0x10,0x02,0x02,0x34,0x12,0x0a,0x00,0x0a,0x00};
       const uint8_t OverRide[11]={0x5a,0xa5,0x10,0x02,0x02,0x78,0x56,0x0a,0x00,0x0a,0x00};
       bool serialPortNameOpen=false;
       QString receiveData,admin_str;
       bool receiveFlag=false;
       QAxObject *excel;
       QAxObject *workbooks;
       QAxObject *workbook;
       QString SaveWord;
       int rows=0,CachCount=0;
       bool Serialsjudge=false;
       double CodeCach[3];
       bool MissError=false,RepetError=false,TransfromFlag=false;
       QByteArray TransfromData;
       QTimer *timer,*timer2;
       QByteArray buffer;
       QString buffer_str;

protected:
      void closeEvent(QCloseEvent *event);//监听页面关闭事件 虚函数override
private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H

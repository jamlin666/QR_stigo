#include "mainwindow.h"
#include "ui_mainwindow.h"
void Delay_MSec(unsigned int msec)
{
    QEventLoop loop;//定义一个新的事件循环
    QTimer::singleShot(msec, &loop, SLOT(quit()));//创建单次定时器，槽函数为事件循环的退出函数
    loop.exec();//事件循环开始执行，程序会卡在这里，直到定时时间到，本循环被退出
}
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    systemInit();
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::closeEvent(QCloseEvent *event)
{
    globlePort.close();
    QDateTime current_date_time =QDateTime::currentDateTime();
    QString current_date =current_date_time.toString("yyyy_MM_dd_hh_mm");
    QString filePath = QCoreApplication::applicationDirPath();
    CloseAndSave(filePath+"/"+current_date+".xlsx");
    admin->close();

}

void MainWindow::systemInit()
{
    acm=new hmac;
    admin=new Admin;
    timer=new QTimer(this);
    timer2=new QTimer(this);
    //端口设定
    globlePort.setParity(QSerialPort::NoParity);
    globlePort.setDataBits(QSerialPort::Data8);
    globlePort.setStopBits(QSerialPort::OneStop);
    globlePort.setFlowControl(QSerialPort::NoFlowControl);
    globlePort.setBaudRate(QSerialPort::Baud115200);
    serialStrList.clear();
    serialStrList = scanSerial();
    ui->portBox->clear();
    serialStrList=compiler_port(serialStrList,serialStrList.size());
    for (int i=0; i<serialStrList.size(); i++)
    {
        if(serialStrList[i] != "")
        ui->portBox->addItem(serialStrList[i]); // 在comboBox那添加串口号
    }
    connect(&globlePort,&QSerialPort::readyRead,this,&MainWindow::ReciveDate);//串口打开就接收消息
    connect(admin,SIGNAL(QR_codeEmit(bool,QString)),this,SLOT(DealclearSignalsFromAdmin(bool,QString)));
    connect(timer, SIGNAL(timeout()), this, SLOT(timer_out()));
    connect(timer2, SIGNAL(timeout()), this, SLOT(timer2_out()));
    connect(admin,SIGNAL(AdminClose()),this,SLOT(DealAdminClose()));
    QDateTime current_date_time =QDateTime::currentDateTime();//可优化，与程序关闭监听文件命名抢占
    QString current_date =current_date_time.toString("yyyy_MM_dd_hh_mm");
    QString filePath = QCoreApplication::applicationDirPath();
    NewExcel(filePath+"/"+current_date+".xlsx");
    traversalControl(ui->centralWidget->children());


}

QStringList MainWindow::scanSerial()
{
    foreach(const QSerialPortInfo &info, QSerialPortInfo::availablePorts())
    {
        int judge = 0;//标志位；
        //1.利用portBox->count()统计portBox里标签的数量
        //2.利用for(i=0;count;)循环，以此判定标签里有没有重复
        //3.若没有重复则 标志位为0，否则为1.只有为0才会append()
        globlePort.setPort(info);
        for(int i=0;i<ui->portBox->count();i++)
           if(globlePort.portName() == ui->portBox->itemText(i)) judge++;
        if(judge == 0)
           serialStrList.append(globlePort.portName());
    }
    return serialStrList;
}

QStringList MainWindow::compiler_port(QStringList staticList,int len)
{
    int i,j;
    QString temp = "";
    for(i = 0;i < len-1 ; i++)
    {
        for(j = 0;j < len-1-i; j++)
        {
            if((staticList[j].compare(staticList[j+1]))>0)
            {
                temp = staticList[j];
                staticList[j] = staticList[j+1];
                staticList[j+1] = temp;
            }
        }
    }
    return staticList;
}

void MainWindow::on_openButton_2_clicked()//刷新串口按钮
{
//    serialStrList = scanSerial();
//    ui->portBox->clear();
//    serialStrList=compiler_port(serialStrList,serialStrList.size());
//    for (int i=0; i<serialStrList.size(); i++)
//    {
//        if(serialStrList[i] != "")
//        ui->portBox->addItem(serialStrList[i]); // 在comboBox那添加串口号
//    }
    ui->portBox->clear();
    QList<QSerialPortInfo> serialPortInfo =QSerialPortInfo::availablePorts();
    int count=serialPortInfo.count();
    for(int i=0;i<count;i++)
    {
      ui->portBox->addItem(serialPortInfo.at(i).portName());
    }
}

QByteArray MainWindow::serialport_send(QString str)
{
  if(str==nullptr) return nullptr;
  else
  {
    QByteArray byte=str.toUtf8();
    QByteArray sendData;
    uint8_t result[str.length()+11];
    uint8_t mac[16];
    const uint8_t key[]={NULL};
     if(TransfromFlag)
     {
         for(int i=0;i<11;i++)
             result[i]=OverRide[i];
      //   TransfromFlag=false;
     }
     else {
           for(int i=0;i<11;i++)
             result[i]=head[i];
     }
    for(int i=0;i<str.length();i++) result[i+11]= uint8_t(byte.at(i));
    acm->hmac_md5(key,0,result,str.length()+11,mac);
    for(int i=0;i<str.length()+11;i++) sendData.append(result[i]);
    for(int i=0;i<16;i++) sendData.append(mac[i]);
    return sendData;
  }
}

void MainWindow::on_portBox_currentIndexChanged(const QString &arg1)
{

    portName=arg1;
}

void MainWindow::on_openButton_toggled(bool checked)
{
    globlePort.setPortName(portName);
    QByteArray sendData;
     if(checked)
     {
         if(globlePort.open(QIODevice::ReadWrite)==true)
       {
            qDebug()<<"串口打开成功";

            serialPortNameOpen=true;
       }
         else
         {
             qDebug()<<"出现问题"<<portName;
             QMessageBox::warning(nullptr, "Warning", portName+"串口打开失败", QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
             serialPortNameOpen=false;
         }
           ui->openButton->setText("关闭串口");
     }
     else
     {
          ui->openButton->setText("打开串口");
          globlePort.close();
     }
}



void MainWindow::on_lineEdit_textChanged(const QString &arg1)
{
    ui->label_2->setStyleSheet("QLabel{background-color:rgb(255,0,0,0%);}");
    ui->label_3->setStyleSheet("QLabel{background-color:rgb(255,0,0,0%);}");

    QByteArray sendData;
    QMessageBox::StandardButton rb;
    if(arg1.length()==textEdit_length)
    {
        if(serialPortNameOpen)  
        {

            QByteArray temp;
            temp=ui->lineEdit->text().mid(textStart_pos,textSend_length).toUtf8();
            if(Serialsjudge==false)
                CodeCach[0]=BitCalculation(temp);
            else
            {
                if(RepetError)
                {
                   CodeCach[1]=CodeCach[2];
                   CodeCach[0]=BitCalculation(temp);
                   RepetError=false;
                   ui->label_3->setStyleSheet("QLabel{background-color:rgb(255,0,0,0%);}");
                }
                else if(MissError)
                {
                   CodeCach[1]=CodeCach[2];
                   CodeCach[0]=BitCalculation(temp);
                   MissError=false;
                   ui->label_2->setStyleSheet("QLabel{background-color:rgb(255,0,0,0%);}");
                }
                else
                {
                    CodeCach[1]=CodeCach[0];
                    CodeCach[0]=BitCalculation(temp);
                }

                if(((CodeCach[0]-CodeCach[1])==0.0) || ((CodeCach[0]-CodeCach[1])<-1.0))
                {
                   RepetError=true;
                   CodeCach[2]=CodeCach[1];
                   qDebug()<<"重复";
                   CachCount++;
                   ui->label_3->setStyleSheet("QLabel{background-color:rgb(255,0,0,);}");
                }
                if((CodeCach[0]-CodeCach[1])>1.0 )
                {
                   MissError=true;
                   CodeCach[2]=CodeCach[1];
                   qDebug()<<"漏码";
                   ui->label_2->setStyleSheet("QLabel{background-color:rgb(255,0,0,);}");
                }
            }
           Serialsjudge=true;
           if(receiveFlag ){ CachCount=0; Serialsjudge=true;}
            if(CachCount>=2)
            {
                admin->setWindowTitle("管理员页面");
                admin->setFixedSize(800,300);
                admin->show();
                CachCount=0;
                Serialsjudge=true;
            }
            sendData= serialport_send(ui->lineEdit->text().mid(textStart_pos,textSend_length));
            if(RepetError==false && MissError==false)
            globlePort.write(sendData);
        }
    }

    if(arg1.length()>textEdit_length)
    {
        QString temp;
        temp=ui->lineEdit->text().mid(32,1);
        ui->lineEdit->clear();
        ui->lineEdit->setText(temp);
    }
    if(receiveFlag)
    {
         ui->lineEdit->clear();
         //receiveFlag=false;
    }

}

void MainWindow::ReciveDate()
{
     static QByteArray Receive_buff;
     QByteArray temp_buf;
     ui->label_4->setStyleSheet("QLabel{background-color:rgb(200,101,102,0%);}");
     ui->label->setStyleSheet("QLabel{background-color:rgb(0,255,0,0%);}");
     Delay_MSec(10);
     temp_buf=globlePort.readAll();
     if((temp_buf.data()[0]==0x5A) || (Receive_buff.data()[0]==0x5A))
     {

         if(temp_buf.data()[temp_buf.length() - 1] == 0x47 || temp_buf.data()[temp_buf.length() - 1] == 0x33)
         {
             Receive_buff+=temp_buf;
        if(Receive_buff.data()[11]==0x01)
           {
             receiveFlag=true;
             timer->start(1000);
             ui->textEdit->append(ui->lineEdit->text());
             if(TransfromFlag)
             {
               SaveWord=admin_str;
               TransfromFlag=false;
             }
             else
              SaveWord=ui->lineEdit->text().mid(textStart_pos,textSend_length);
             ui->lineEdit->clear();
             FillExcel(SaveWord,rows);
             ui->label->setStyleSheet("QLabel{background-color:rgb(0,255,0,);}");
             ui->label_4->setStyleSheet("QLabel{background-color:rgb(0,255,0,0%);}");
             rows++;
             ui->label_12->setText(SaveWord);
           }
         if(Receive_buff.data()[11]==0x07)
           {
             receiveFlag=false;
             timer2->start(1000);
             ui->label_4->setStyleSheet("QLabel{background-color:rgb(255,0,0,);}");
             ui->label->setStyleSheet("QLabel{background-color:rgb(0,255,0,0%);}");
           }

             receiveData=QString(Receive_buff.toHex());
             buffer_str.append(receiveData);
           //  ui->textEdit->append(buffer_str);
             Receive_buff.clear();
             temp_buf.clear();
             receiveData.clear();
             buffer_str.clear();
         }
         else {
             Receive_buff+=temp_buf;
         }
     }
//     else if (temp_buf==nullptr) {
//         receiveFlag=false;
//         ui->label_4->setStyleSheet("QLabel{background-color:rgb(255,0,0,);}");
//         ui->label->setStyleSheet("QLabel{background-color:rgb(0,255,0,0%);}");
//     }
     else {
//         receiveFlag=false;
//         ui->label_4->setStyleSheet("QLabel{background-color:rgb(255,0,0,);}");
//         ui->label->setStyleSheet("QLabel{background-color:rgb(0,255,0,0%);}");
         temp_buf.clear();
         Receive_buff.clear();
     }


}

void MainWindow::NewExcel(QString filePath)
{
    if(!filePath.isEmpty())
        {
            excel = new QAxObject(this);
            excel->setControl("Excel.Application");//连接Excel控件
            excel->dynamicCall("SetVisible (bool Visible)","false");//不显示窗体
            excel->setProperty("DisplayAlerts", false);//不显示任何警告信息。如果为true那么在关闭是会出现类似“文件已修改，是否保存”的提示
            workbooks = excel->querySubObject("WorkBooks");//获取工作簿集合
            workbooks->dynamicCall("Add");//新建一个工作簿
            workbook = excel->querySubObject("ActiveWorkBook");//获取当前工作簿
       }
       else
        {
            QMessageBox::warning(nullptr, "Warning", "EXCEL打开错误", QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
        }
}

void MainWindow::FillExcel(QString data, int rows)
{
    QAxObject *worksheets = workbook->querySubObject("Sheets");//获取工作表集合
    QAxObject *worksheet = worksheets->querySubObject("Item(int)",1);//获取工作表集合的工作表1，即sheet1
    QAxObject *cellX;
    QString X="A"+QString::number(rows+1);//设置要操作的单元格，如A1
    cellX = worksheet->querySubObject("Range(QVariant, QVariant)",X);//获取单元格
    cellX->dynamicCall("SetValue(const QVariant&)",QVariant(data));

}

void MainWindow::CloseAndSave(QString filePath)
{
    workbook->dynamicCall("SaveAs(const QString&)",QDir::toNativeSeparators(filePath));//保存至filepath，注意一定要用QDir::toNativeSeparators将路径中的"/"转换为"\"，不然一定保存不了。
    workbook->dynamicCall("Close()");//关闭工作簿
    excel->dynamicCall("Quit()");//关闭excel
    delete excel;
    excel=nullptr;
}

double MainWindow::BitCalculation(QByteArray byteData)
{
    double CalResult=0;
    for(int i=0;i<byteData.size()-SequenceCode;i++)
       CalResult+=qPow(10,byteData.size()-SequenceCode-i-1)*(byteData.at(i+SequenceCode)-0x30);
    return CalResult;
}

void MainWindow::traversalControl(const QObjectList& q)
{

   QFont font ("楷体",15,75);
   for(int i=0;i<q.length();i++)
    {
    if(!q.at(i)->children().empty())
    {
        traversalControl(q.at(i)->children());
    }
        else
        {
            QObject* o = q.at(i);
            if (o->inherits("QLabel"))
            {
            QLabel* b = qobject_cast<QLabel*>(o);
            b->setFont(font);
            }
        }
    }
}
void MainWindow::DealclearSignalsFromAdmin(bool flag,QString str)
{
    if(flag)
    {
        MissError=false;
        RepetError=false;
        TransfromFlag=true;
        admin_str=str.mid(textStart_pos,textSend_length);
        TransfromData=serialport_send(str.mid(textStart_pos,textSend_length));
        globlePort.write(TransfromData);
        ui->label_3->setStyleSheet("QLabel{background-color:rgb(255,0,0,0%);}");
        ui->label_2->setStyleSheet("QLabel{background-color:rgb(255,0,0,0%);}");
        admin->ParameterClear();
        admin->close();

    }
    else {
     QMessageBox::StandardButton rb =
             QMessageBox::warning(nullptr, "Warning", "密码错误", QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
     if(rb == QMessageBox::Yes)
     {
         admin->ParameterClear();
        admin->close();

     }
    }
}

void MainWindow::on_openButton_3_clicked()
{
    MissError=false;
    RepetError=false;
    ui->label_3->setStyleSheet("QLabel{background-color:rgb(255,0,0,0%);}");
    ui->label_2->setStyleSheet("QLabel{background-color:rgb(255,0,0,0%);}");
    ui->label_4->setStyleSheet("QLabel{background-color:rgb(255,0,0,0%);}");
    ui->label->setStyleSheet("QLabel{background-color:rgb(255,0,0,0%);}");
    ui->lineEdit->clear();
    ui->textEdit->clear();
    for (int i=0;i<3;i++)
    {
        CodeCach[i]=0;
    }
}

void MainWindow::DealAdminClose()
{
    admin->ParameterClear();
    admin->close();

}

void MainWindow::timer_out()
{
    if(timer->isActive()){
          timer->stop();
          receiveFlag=false;
          ui->label->setStyleSheet("QLabel{background-color:rgb(0,255,0,0%);}");
    }
}

void MainWindow::timer2_out()
{
    if(timer2->isActive()){
          timer2->stop();
          ui->label_4->setStyleSheet("QLabel{background-color:rgb(0,255,0,0%);}");
    }
}

void MainWindow::on_openButton_clicked()
{

}


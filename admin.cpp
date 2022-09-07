#include "admin.h"
#include "ui_admin.h"

Admin::Admin(QWidget *parent):
    QMainWindow(parent),
    ui(new Ui::Admin)
{
    ui->setupUi(this);
    QFont font ("楷体",15,75);
     ui->label_3->setStyleSheet("QLabel{background-color:rgb(255,0,0,80%);}");
     ui->label_3->setFont(font);
     ui->lineEdit->setEchoMode( QLineEdit::Password );
}

Admin::~Admin()
{
    delete ui;

}

void Admin::on_pushButton_clicked()
{
    if(ui->lineEdit->text()==PassWord)
    {
        emit QR_codeEmit(true,ui->lineEdit_2->text());
    }
    else
    {
        emit QR_codeEmit(false,nullptr);
    }
}

void Admin::on_pushButton_2_clicked()
{
    emit AdminClose();
}
void Admin::ParameterClear()
{
    ui->lineEdit->clear();
    ui->lineEdit_2->clear();
}

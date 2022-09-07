#ifndef ADMIN_H
#define ADMIN_H

#include <QMainWindow>
#include <QDebug>
namespace Ui {
class Admin;
}

class Admin : public QMainWindow
{
    Q_OBJECT

public:
    explicit Admin(QWidget *parent = nullptr);
    ~Admin();
      void ParameterClear();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::Admin *ui;
    const QString PassWord="123";
signals:
   void QR_codeEmit(bool ClearFlag,QString str);
   void AdminClose();

};

#endif // ADMIN_H

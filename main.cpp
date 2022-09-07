#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    w.setWindowTitle("QR_Code_STIGO_Input");
    w.setFixedSize(1000,600);
    return a.exec();
}

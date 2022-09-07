/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout_2;
    QGroupBox *groupBox_2;
    QVBoxLayout *verticalLayout;
    QLabel *label_9;
    QLineEdit *lineEdit;
    QLabel *label_10;
    QTextEdit *textEdit;
    QLabel *label_8;
    QGroupBox *groupBox;
    QGridLayout *gridLayout;
    QSpacerItem *horizontalSpacer;
    QLabel *label_12;
    QLabel *label;
    QPushButton *openButton_3;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_2;
    QLabel *label_7;
    QPushButton *openButton_2;
    QLabel *label_5;
    QLabel *label_6;
    QPushButton *openButton;
    QComboBox *portBox;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1043, 662);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        gridLayout_2 = new QGridLayout(centralWidget);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        groupBox_2 = new QGroupBox(centralWidget);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setStyleSheet(QString::fromUtf8("QGroupBox{\n"
"background-color: rgb(240, 240, 240);\n"
"\n"
"border-width:2px;\n"
"\n"
"border-style:solid;\n"
"\n"
"border-radius: 10px;\n"
"\n"
"border-color:rgb(207, 207, 207);\n"
"\n"
"margin-top:0ex;\n"
"\n"
"}\n"
"\n"
"QGroupBox::title{\n"
"\n"
"subcontrol-origin:margin;\n"
"\n"
"subcontrol-position:top left;\n"
"\n"
"left:10px;\n"
"\n"
"margin-left:0px;\n"
"\n"
"padding:0 1px;\n"
"\n"
"}"));
        verticalLayout = new QVBoxLayout(groupBox_2);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label_9 = new QLabel(groupBox_2);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        verticalLayout->addWidget(label_9);

        lineEdit = new QLineEdit(groupBox_2);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(lineEdit->sizePolicy().hasHeightForWidth());
        lineEdit->setSizePolicy(sizePolicy);
        lineEdit->setMinimumSize(QSize(0, 20));
        QFont font;
        font.setFamily(QString::fromUtf8("Times New Roman"));
        font.setPointSize(12);
        font.setBold(false);
        font.setItalic(false);
        font.setWeight(50);
        lineEdit->setFont(font);
        lineEdit->setStyleSheet(QString::fromUtf8("font: 12pt \"Times New Roman\";"));

        verticalLayout->addWidget(lineEdit);

        label_10 = new QLabel(groupBox_2);
        label_10->setObjectName(QString::fromUtf8("label_10"));

        verticalLayout->addWidget(label_10);

        textEdit = new QTextEdit(groupBox_2);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));
        textEdit->setStyleSheet(QString::fromUtf8("font: 12pt \"Times New Roman\";"));

        verticalLayout->addWidget(textEdit);

        label_8 = new QLabel(groupBox_2);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setStyleSheet(QString::fromUtf8("QComboBox{background-color: rgb(225, 225, 225);border:2px groove gray;border-radius:4px;padding:2px 4px;border-style: outset;}\n"
"                                       QComboBox:hover{background-color:rgb(229, 241, 251); color: black;}\n"
"                                       QComboBox:pressed{background-color:rgb(204, 228, 247);border-style: inset;};"));

        verticalLayout->addWidget(label_8);


        gridLayout_2->addWidget(groupBox_2, 0, 0, 1, 1);

        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setStyleSheet(QString::fromUtf8("QGroupBox{\n"
"background-color: rgb(240, 240, 240);\n"
"\n"
"border-width:2px;\n"
"\n"
"border-style:solid;\n"
"\n"
"border-radius: 10px;\n"
"\n"
"border-color:rgb(207, 207, 207);\n"
"\n"
"margin-top:0ex;\n"
"\n"
"}\n"
"\n"
"QGroupBox::title{\n"
"\n"
"subcontrol-origin:margin;\n"
"\n"
"subcontrol-position:top left;\n"
"\n"
"left:10px;\n"
"\n"
"margin-left:0px;\n"
"\n"
"padding:0 1px;\n"
"\n"
"}"));
        gridLayout = new QGridLayout(groupBox);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        horizontalSpacer = new QSpacerItem(348, 398, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 2, 1, 4, 3);

        label_12 = new QLabel(groupBox);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setStyleSheet(QString::fromUtf8("font: 16pt \"\346\245\267\344\275\223\";"));

        gridLayout->addWidget(label_12, 6, 1, 1, 2);

        label = new QLabel(groupBox);
        label->setObjectName(QString::fromUtf8("label"));
        label->setStyleSheet(QString::fromUtf8("font: 16pt \"\346\245\267\344\275\223\";"));

        gridLayout->addWidget(label, 2, 0, 1, 1);

        openButton_3 = new QPushButton(groupBox);
        openButton_3->setObjectName(QString::fromUtf8("openButton_3"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(openButton_3->sizePolicy().hasHeightForWidth());
        openButton_3->setSizePolicy(sizePolicy1);
        QFont font1;
        font1.setBold(true);
        font1.setWeight(75);
        openButton_3->setFont(font1);
        openButton_3->setStyleSheet(QString::fromUtf8("QPushButton{background-color: rgb(225, 225, 225);border:1px groove gray;border-radius:4px;padding:1px 4px;border-style: outset;}\n"
"                                       QPushButton:hover{background-color:rgb(229, 241, 251); color: black;}\n"
"                                       QPushButton:pressed{background-color:rgb(204, 228, 247);border-style: inset;}"));

        gridLayout->addWidget(openButton_3, 1, 3, 1, 1);

        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setStyleSheet(QString::fromUtf8("font: 16pt \"\346\245\267\344\275\223\";"));

        gridLayout->addWidget(label_3, 5, 0, 1, 1);

        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setStyleSheet(QString::fromUtf8("font: 16pt \"\346\245\267\344\275\223\";"));

        gridLayout->addWidget(label_4, 3, 0, 1, 1);

        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setStyleSheet(QString::fromUtf8("font: 16pt \"\346\245\267\344\275\223\";"));

        gridLayout->addWidget(label_2, 4, 0, 1, 1);

        label_7 = new QLabel(groupBox);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        gridLayout->addWidget(label_7, 0, 0, 1, 1);

        openButton_2 = new QPushButton(groupBox);
        openButton_2->setObjectName(QString::fromUtf8("openButton_2"));
        sizePolicy1.setHeightForWidth(openButton_2->sizePolicy().hasHeightForWidth());
        openButton_2->setSizePolicy(sizePolicy1);
        openButton_2->setFont(font1);
        openButton_2->setStyleSheet(QString::fromUtf8("QPushButton{background-color: rgb(225, 225, 225);border:1px groove gray;border-radius:4px;padding:1px 4px;border-style: outset;}\n"
"                                       QPushButton:hover{background-color:rgb(229, 241, 251); color: black;}\n"
"                                       QPushButton:pressed{background-color:rgb(204, 228, 247);border-style: inset;}"));

        gridLayout->addWidget(openButton_2, 1, 1, 1, 1);

        label_5 = new QLabel(groupBox);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setStyleSheet(QString::fromUtf8("font: 16pt \"\346\245\267\344\275\223\";"));

        gridLayout->addWidget(label_5, 6, 0, 1, 1);

        label_6 = new QLabel(groupBox);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setStyleSheet(QString::fromUtf8("QComboBox{background-color: rgb(225, 225, 225);border:2px groove gray;border-radius:4px;padding:2px 4px;border-style: outset;}\n"
"                                       QComboBox:hover{background-color:rgb(229, 241, 251); color: black;}\n"
"                                       QComboBox:pressed{background-color:rgb(204, 228, 247);border-style: inset;};"));

        gridLayout->addWidget(label_6, 7, 0, 1, 1);

        openButton = new QPushButton(groupBox);
        openButton->setObjectName(QString::fromUtf8("openButton"));
        sizePolicy1.setHeightForWidth(openButton->sizePolicy().hasHeightForWidth());
        openButton->setSizePolicy(sizePolicy1);
        openButton->setFont(font1);
        openButton->setFocusPolicy(Qt::WheelFocus);
        openButton->setStyleSheet(QString::fromUtf8("QPushButton{background-color: rgb(225, 225, 225);border:1px groove gray;border-radius:4px;padding:1px 4px;border-style: outset;}\n"
"                                       QPushButton:hover{background-color:rgb(229, 241, 251); color: black;}\n"
"                                       QPushButton:pressed{background-color:rgb(204, 228, 247);border-style: inset;}"));
        openButton->setCheckable(true);
        openButton->setChecked(false);

        gridLayout->addWidget(openButton, 1, 2, 1, 1);

        portBox = new QComboBox(groupBox);
        portBox->setObjectName(QString::fromUtf8("portBox"));
        portBox->setFont(font1);
        portBox->setStyleSheet(QString::fromUtf8("QComboBox{background-color: rgb(225, 225, 225);border:2px groove gray;border-radius:4px;padding:2px 4px;border-style: outset;}\n"
"                                       QComboBox:hover{background-color:rgb(229, 241, 251); color: black;}\n"
"                                       QComboBox:pressed{background-color:rgb(204, 228, 247);border-style: inset;};"));

        gridLayout->addWidget(portBox, 0, 1, 1, 3);


        gridLayout_2->addWidget(groupBox, 0, 1, 1, 1);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1043, 25));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        openButton->setDefault(false);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        groupBox_2->setTitle(QString());
        label_9->setText(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:12pt; font-weight:600;\">\346\211\253\347\240\201\346\236\252\350\276\223\345\205\245</span></p></body></html>", nullptr));
        label_10->setText(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:12pt; font-weight:600;\">\344\270\262\345\217\243\350\276\223\345\207\272</span></p></body></html>", nullptr));
        label_8->setText(QString());
        groupBox->setTitle(QString());
        label_12->setText(QApplication::translate("MainWindow", "000000", nullptr));
        label->setText(QApplication::translate("MainWindow", "\345\206\231\345\205\245\346\210\220\345\212\237", nullptr));
        openButton_3->setText(QApplication::translate("MainWindow", "\346\270\205\351\231\244\346\230\276\347\244\272", nullptr));
        label_3->setText(QApplication::translate("MainWindow", "\351\207\215\345\244\215\346\225\205\351\232\234", nullptr));
        label_4->setText(QApplication::translate("MainWindow", "\345\206\231\345\205\245\345\244\261\350\264\245", nullptr));
        label_2->setText(QApplication::translate("MainWindow", "\346\274\217\347\240\201\346\225\205\351\232\234", nullptr));
        label_7->setText(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:12pt; font-weight:600;\">\344\270\262\345\217\243\345\217\267</span></p></body></html>", nullptr));
        openButton_2->setText(QApplication::translate("MainWindow", "\345\210\267\346\226\260\344\270\262\345\217\243", nullptr));
        label_5->setText(QApplication::translate("MainWindow", "\344\270\212\344\270\200\344\270\252", nullptr));
        label_6->setText(QString());
        openButton->setText(QApplication::translate("MainWindow", "\346\211\223\345\274\200\344\270\262\345\217\243", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H

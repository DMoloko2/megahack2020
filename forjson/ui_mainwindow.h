/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QPushButton *pushButton;
    QComboBox *comboBox;
    QFrame *frame_3;
    QWidget *widget;
    QVBoxLayout *verticalLayout_5;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout_4;
    QLabel *label_5;
    QLineEdit *lineEdit_2;
    QVBoxLayout *verticalLayout;
    QLabel *label_6;
    QSpinBox *spinBox_2;
    QLabel *label_7;
    QWidget *widget1;
    QHBoxLayout *horizontalLayout_5;
    QFrame *frame_2;
    QWidget *widget2;
    QVBoxLayout *verticalLayout_6;
    QHBoxLayout *horizontalLayout_2;
    QGridLayout *gridLayout_2;
    QLabel *label;
    QLineEdit *lineEdit;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_2;
    QSpinBox *spinBox;
    QHBoxLayout *horizontalLayout_3;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_3;
    QLineEdit *lineEdit_3;
    QGridLayout *gridLayout;
    QLabel *label_4;
    QLineEdit *lineEdit_4;
    QLabel *label_8;
    QFrame *frame;
    QWidget *widget3;
    QVBoxLayout *verticalLayout_11;
    QVBoxLayout *verticalLayout_10;
    QVBoxLayout *verticalLayout_7;
    QLabel *label_9;
    QLineEdit *lineEdit_5;
    QHBoxLayout *horizontalLayout_4;
    QVBoxLayout *verticalLayout_8;
    QLabel *label_10;
    QLineEdit *lineEdit_6;
    QVBoxLayout *verticalLayout_9;
    QLabel *label_11;
    QLineEdit *lineEdit_7;
    QLabel *label_12;
    QWidget *widget4;
    QVBoxLayout *verticalLayout_12;
    QLabel *label_13;
    QSpinBox *spinBox_3;
    QWidget *widget5;
    QVBoxLayout *verticalLayout_13;
    QLabel *label_14;
    QLabel *label_15;
    QLabel *label_16;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(725, 414);
        MainWindow->setStyleSheet(QString::fromUtf8(""));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(540, 250, 141, 61));
        QFont font;
        font.setPointSize(15);
        pushButton->setFont(font);
        pushButton->setAutoFillBackground(true);
        pushButton->setStyleSheet(QString::fromUtf8("background rgb(0, 85, 255)"));
        comboBox = new QComboBox(centralWidget);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        comboBox->setGeometry(QRect(540, 200, 151, 31));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Calibri"));
        font1.setPointSize(14);
        font1.setBold(false);
        font1.setItalic(false);
        font1.setWeight(9);
        comboBox->setFont(font1);
        comboBox->setStyleSheet(QString::fromUtf8("font: 75 14pt \"Calibri\";"));
        frame_3 = new QFrame(centralWidget);
        frame_3->setObjectName(QString::fromUtf8("frame_3"));
        frame_3->setGeometry(QRect(10, 200, 341, 141));
        frame_3->setFrameShape(QFrame::Box);
        frame_3->setFrameShadow(QFrame::Raised);
        frame_3->setLineWidth(5);
        frame_3->setMidLineWidth(2);
        widget = new QWidget(frame_3);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(60, 60, 184, 50));
        verticalLayout_5 = new QVBoxLayout(widget);
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setContentsMargins(11, 11, 11, 11);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        verticalLayout_5->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        label_5 = new QLabel(widget);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        verticalLayout_4->addWidget(label_5);

        lineEdit_2 = new QLineEdit(widget);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));

        verticalLayout_4->addWidget(lineEdit_2);


        horizontalLayout->addLayout(verticalLayout_4);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label_6 = new QLabel(widget);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        verticalLayout->addWidget(label_6);

        spinBox_2 = new QSpinBox(widget);
        spinBox_2->setObjectName(QString::fromUtf8("spinBox_2"));
        spinBox_2->setMaximum(99999);
        spinBox_2->setValue(8888);

        verticalLayout->addWidget(spinBox_2);


        horizontalLayout->addLayout(verticalLayout);


        verticalLayout_5->addLayout(horizontalLayout);

        label_7 = new QLabel(frame_3);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(20, 10, 182, 25));
        widget1 = new QWidget(centralWidget);
        widget1->setObjectName(QString::fromUtf8("widget1"));
        widget1->setGeometry(QRect(10, 10, 681, 181));
        horizontalLayout_5 = new QHBoxLayout(widget1);
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        horizontalLayout_5->setContentsMargins(0, 0, 0, 0);
        frame_2 = new QFrame(widget1);
        frame_2->setObjectName(QString::fromUtf8("frame_2"));
        frame_2->setFrameShape(QFrame::Box);
        frame_2->setFrameShadow(QFrame::Raised);
        frame_2->setLineWidth(5);
        frame_2->setMidLineWidth(2);
        widget2 = new QWidget(frame_2);
        widget2->setObjectName(QString::fromUtf8("widget2"));
        widget2->setGeometry(QRect(20, 40, 280, 121));
        verticalLayout_6 = new QVBoxLayout(widget2);
        verticalLayout_6->setSpacing(6);
        verticalLayout_6->setContentsMargins(11, 11, 11, 11);
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        verticalLayout_6->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        gridLayout_2 = new QGridLayout();
        gridLayout_2->setSpacing(6);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        label = new QLabel(widget2);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout_2->addWidget(label, 0, 0, 1, 1);

        lineEdit = new QLineEdit(widget2);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));

        gridLayout_2->addWidget(lineEdit, 1, 0, 1, 1);


        horizontalLayout_2->addLayout(gridLayout_2);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        label_2 = new QLabel(widget2);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        verticalLayout_2->addWidget(label_2);

        spinBox = new QSpinBox(widget2);
        spinBox->setObjectName(QString::fromUtf8("spinBox"));
        spinBox->setMaximum(99999);
        spinBox->setValue(8123);

        verticalLayout_2->addWidget(spinBox);


        horizontalLayout_2->addLayout(verticalLayout_2);


        verticalLayout_6->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        label_3 = new QLabel(widget2);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        verticalLayout_3->addWidget(label_3);

        lineEdit_3 = new QLineEdit(widget2);
        lineEdit_3->setObjectName(QString::fromUtf8("lineEdit_3"));

        verticalLayout_3->addWidget(lineEdit_3);


        horizontalLayout_3->addLayout(verticalLayout_3);

        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label_4 = new QLabel(widget2);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout->addWidget(label_4, 0, 0, 1, 1);

        lineEdit_4 = new QLineEdit(widget2);
        lineEdit_4->setObjectName(QString::fromUtf8("lineEdit_4"));

        gridLayout->addWidget(lineEdit_4, 1, 0, 1, 1);


        horizontalLayout_3->addLayout(gridLayout);


        verticalLayout_6->addLayout(horizontalLayout_3);

        label_8 = new QLabel(frame_2);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(20, 0, 278, 36));

        horizontalLayout_5->addWidget(frame_2);

        frame = new QFrame(widget1);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setFrameShape(QFrame::Box);
        frame->setFrameShadow(QFrame::Raised);
        frame->setLineWidth(5);
        frame->setMidLineWidth(2);
        widget3 = new QWidget(frame);
        widget3->setObjectName(QString::fromUtf8("widget3"));
        widget3->setGeometry(QRect(20, 40, 282, 121));
        verticalLayout_11 = new QVBoxLayout(widget3);
        verticalLayout_11->setSpacing(6);
        verticalLayout_11->setContentsMargins(11, 11, 11, 11);
        verticalLayout_11->setObjectName(QString::fromUtf8("verticalLayout_11"));
        verticalLayout_11->setContentsMargins(0, 0, 0, 0);
        verticalLayout_10 = new QVBoxLayout();
        verticalLayout_10->setSpacing(6);
        verticalLayout_10->setObjectName(QString::fromUtf8("verticalLayout_10"));
        verticalLayout_7 = new QVBoxLayout();
        verticalLayout_7->setSpacing(6);
        verticalLayout_7->setObjectName(QString::fromUtf8("verticalLayout_7"));
        label_9 = new QLabel(widget3);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        verticalLayout_7->addWidget(label_9);

        lineEdit_5 = new QLineEdit(widget3);
        lineEdit_5->setObjectName(QString::fromUtf8("lineEdit_5"));

        verticalLayout_7->addWidget(lineEdit_5);


        verticalLayout_10->addLayout(verticalLayout_7);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        verticalLayout_8 = new QVBoxLayout();
        verticalLayout_8->setSpacing(6);
        verticalLayout_8->setObjectName(QString::fromUtf8("verticalLayout_8"));
        label_10 = new QLabel(widget3);
        label_10->setObjectName(QString::fromUtf8("label_10"));

        verticalLayout_8->addWidget(label_10);

        lineEdit_6 = new QLineEdit(widget3);
        lineEdit_6->setObjectName(QString::fromUtf8("lineEdit_6"));

        verticalLayout_8->addWidget(lineEdit_6);


        horizontalLayout_4->addLayout(verticalLayout_8);

        verticalLayout_9 = new QVBoxLayout();
        verticalLayout_9->setSpacing(6);
        verticalLayout_9->setObjectName(QString::fromUtf8("verticalLayout_9"));
        label_11 = new QLabel(widget3);
        label_11->setObjectName(QString::fromUtf8("label_11"));

        verticalLayout_9->addWidget(label_11);

        lineEdit_7 = new QLineEdit(widget3);
        lineEdit_7->setObjectName(QString::fromUtf8("lineEdit_7"));

        verticalLayout_9->addWidget(lineEdit_7);


        horizontalLayout_4->addLayout(verticalLayout_9);


        verticalLayout_10->addLayout(horizontalLayout_4);


        verticalLayout_11->addLayout(verticalLayout_10);

        label_12 = new QLabel(frame);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setGeometry(QRect(20, 0, 280, 41));

        horizontalLayout_5->addWidget(frame);

        widget4 = new QWidget(centralWidget);
        widget4->setObjectName(QString::fromUtf8("widget4"));
        widget4->setGeometry(QRect(380, 200, 111, 41));
        verticalLayout_12 = new QVBoxLayout(widget4);
        verticalLayout_12->setSpacing(6);
        verticalLayout_12->setContentsMargins(11, 11, 11, 11);
        verticalLayout_12->setObjectName(QString::fromUtf8("verticalLayout_12"));
        verticalLayout_12->setContentsMargins(0, 0, 0, 0);
        label_13 = new QLabel(widget4);
        label_13->setObjectName(QString::fromUtf8("label_13"));

        verticalLayout_12->addWidget(label_13);

        spinBox_3 = new QSpinBox(widget4);
        spinBox_3->setObjectName(QString::fromUtf8("spinBox_3"));
        spinBox_3->setMaximum(99999);
        spinBox_3->setValue(7139);

        verticalLayout_12->addWidget(spinBox_3);

        widget5 = new QWidget(centralWidget);
        widget5->setObjectName(QString::fromUtf8("widget5"));
        widget5->setGeometry(QRect(360, 260, 161, 81));
        verticalLayout_13 = new QVBoxLayout(widget5);
        verticalLayout_13->setSpacing(6);
        verticalLayout_13->setContentsMargins(11, 11, 11, 11);
        verticalLayout_13->setObjectName(QString::fromUtf8("verticalLayout_13"));
        verticalLayout_13->setContentsMargins(0, 0, 0, 0);
        label_14 = new QLabel(widget5);
        label_14->setObjectName(QString::fromUtf8("label_14"));

        verticalLayout_13->addWidget(label_14);

        label_15 = new QLabel(widget5);
        label_15->setObjectName(QString::fromUtf8("label_15"));

        verticalLayout_13->addWidget(label_15);

        label_16 = new QLabel(widget5);
        label_16->setObjectName(QString::fromUtf8("label_16"));

        verticalLayout_13->addWidget(label_16);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 725, 21));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        pushButton->setText(QApplication::translate("MainWindow", "Start", nullptr));
        comboBox->setItemText(0, QApplication::translate("MainWindow", "\320\224\320\260\320\262\320\273\320\265\320\275\320\270\320\265", nullptr));
        comboBox->setItemText(1, QApplication::translate("MainWindow", "\320\222\320\273\320\260\320\266\320\275\320\276\321\201\321\202\321\214", nullptr));
        comboBox->setItemText(2, QApplication::translate("MainWindow", "\320\242\320\265\320\274\320\277\320\265\321\200\320\260\321\202\321\203\321\200\320\260 \320\277\320\276\320\274\320\265\321\211\320\265\320\275\320\270\321\217", nullptr));
        comboBox->setItemText(3, QApplication::translate("MainWindow", "\320\242\320\265\320\274\320\277\320\265\321\200\320\260\321\202\321\203\321\200\320\260 \321\200\320\260\320\261\320\276\321\207\320\265\320\271 \320\267\320\276\320\275\321\213", nullptr));
        comboBox->setItemText(4, QApplication::translate("MainWindow", "\320\243\321\200\320\276\320\262\320\265\320\275\321\214 pH", nullptr));
        comboBox->setItemText(5, QApplication::translate("MainWindow", "\320\234\320\260\321\201\321\201\320\260", nullptr));
        comboBox->setItemText(6, QApplication::translate("MainWindow", "\320\240\320\260\321\201\321\205\320\276\320\264 \320\266\320\270\320\264\320\272\320\276\321\201\321\202\320\270", nullptr));
        comboBox->setItemText(7, QApplication::translate("MainWindow", "\320\243\321\200\320\276\320\262\320\265\320\275\321\214 \320\241\320\2362", nullptr));

        label_5->setText(QApplication::translate("MainWindow", "IP", nullptr));
        lineEdit_2->setText(QApplication::translate("MainWindow", "172.20.10.4", nullptr));
        label_6->setText(QApplication::translate("MainWindow", "Port", nullptr));
        label_7->setText(QApplication::translate("MainWindow", "Telgramm", nullptr));
        label->setText(QApplication::translate("MainWindow", "IP adress DataBase", nullptr));
        lineEdit->setText(QApplication::translate("MainWindow", "172.20.10.10", nullptr));
        label_2->setText(QApplication::translate("MainWindow", "Port", nullptr));
        label_3->setText(QApplication::translate("MainWindow", "User", nullptr));
        lineEdit_3->setText(QApplication::translate("MainWindow", "default", nullptr));
        label_4->setText(QApplication::translate("MainWindow", "Password", nullptr));
        lineEdit_4->setText(QApplication::translate("MainWindow", "0000", nullptr));
        label_8->setText(QApplication::translate("MainWindow", "ClickHouse Database", nullptr));
        label_9->setText(QApplication::translate("MainWindow", "IP", nullptr));
        lineEdit_5->setText(QApplication::translate("MainWindow", "172.20.10.10", nullptr));
        label_10->setText(QApplication::translate("MainWindow", "User", nullptr));
        lineEdit_6->setText(QApplication::translate("MainWindow", "root", nullptr));
        label_11->setText(QApplication::translate("MainWindow", "Password", nullptr));
        lineEdit_7->setText(QApplication::translate("MainWindow", "0000", nullptr));
        label_12->setText(QApplication::translate("MainWindow", "SQL Database", nullptr));
        label_13->setText(QApplication::translate("MainWindow", "\320\237\320\276\321\200\321\202", nullptr));
        label_14->setText(QString());
        label_15->setText(QString());
        label_16->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H

#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);


    MainWindow w;
    w.show();

    QFile file("qss/comboBox.qss");
      file.open(QFile::ReadOnly);
      a.setStyleSheet(file.readAll());

    return a.exec();
}

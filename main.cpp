#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
       MainWindow window;
       window.setWindowTitle("Auto CAD Software by Shashank & Udit");

       window.show();
       return app.exec();
}

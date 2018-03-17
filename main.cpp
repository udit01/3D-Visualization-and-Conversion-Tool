#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    int currentExitCode = 0;
    do
    {
        QApplication app(argc, argv);
        MainWindow window;
        window.setWindowTitle("Auto CAD Software");
        window.show();
        currentExitCode = app.exec();
    } while(currentExitCode == MainWindow::EXIT_CODE_REBOOT);

    return currentExitCode;
}

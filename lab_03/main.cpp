#include <QApplication>

#include "mainwindow.hpp"
#include "facade.hpp"
#include "command.hpp"

int main(int argc, char* argv[]) {
    QApplication application(argc, argv);
    MainWindow window;
    window.show();

    return application.exec();
}

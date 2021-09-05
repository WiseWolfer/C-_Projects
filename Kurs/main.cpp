#include "mainwindow.hpp"

#include <QApplication>

///
/// В мейне создается объект на главное окно и запускается приложение
///

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    MainWindow w;
    w.show();

    return app.exec();
}

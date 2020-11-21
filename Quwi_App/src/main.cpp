#include "QuwiMainwindow.h"
#include <QFile>
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    QuwiMainWindow win;
    win.show();

    return app.exec();
}

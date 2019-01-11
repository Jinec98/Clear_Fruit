#include "gamewindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    a.setWindowIcon(QIcon("://resource/icon.ico"));
    gameWindow w;
    w.show();

    return a.exec();
}

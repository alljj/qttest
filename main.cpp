#include "widget.h"
#include "window.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;

    w.desktopWnd = findDesktopIconWnd();

    SendMessageToDesktop();

      w.show();


//      m.show();
    return a.exec();
}

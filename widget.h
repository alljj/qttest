#ifndef WIDGET_H
#define WIDGET_H
#include <QWidget>
#include <windows.h>
//#include <gif.h>
#include <media.h>
#include <QCloseEvent>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
     HWND desktopWnd;
     void dealsig();

private slots:
     void on_pushButton_clicked();

     void on_pushButton_2_clicked();
     void closeEvent(QCloseEvent *event);
     void on_pushButton_3_clicked();

private:
    Ui::Widget *ui;
//    QSettings *wallpaper;
     QString paths;
//      gif v;
      Media m;


};
#endif // WIDGET_H

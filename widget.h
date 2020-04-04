#ifndef WIDGET_H
#define WIDGET_H
#include <QWidget>
#include <windows.h>
//#include <gif.h>
#include <media.h>
#include <QCloseEvent>
#include <QStringList>
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
     QString getfileNames(const QString &path);
private slots:
     void on_pushButton_clicked();

     void on_pushButton_2_clicked();
     void closeEvent(QCloseEvent *event);
     void on_pushButton_3_clicked();

     void on_pushButton_jpg1_clicked();

private:
    Ui::Widget *ui;
//    QSettings *wallpaper;
     QString paths;
     QString jpg1;
     QString last_1;
//      gif v;
      Media m;



};
#endif // WIDGET_H

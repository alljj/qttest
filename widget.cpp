#include "widget.h"
#include "ui_widget.h"
#include <QMovie>
#include <QLabel>
#include <QFileDialog>
Widget::Widget(QWidget *parent)
    : QWidget(parent),
    ui(new Ui::Widget)
{

    ui->setupUi(this);

   connect(&m,&Media::sendmes,this,&Widget::dealsig);

//    QMovie *movie = new QMovie("C:/Users/Administrator/Desktop/qt/img/s.gif");
//    label->setMovie(movie);
//    movie->start();





     //给桌面设置背景
//    wallpaper= new QSettings("HKEY_CURRENT_USER\\Control Panel\\Desktop",QSettings::NativeFormat);
//    QString path ("C:/Users/Administrator/Desktop/qt/smu.jpg");
//    wallpaper->setValue("Wallpaper",path);
//    QByteArray byte = path.toLocal8Bit();
//    SystemParametersInfoA(SPI_SETDESKWALLPAPER,0,byte.data(),SPIF_UPDATEINIFILE | SPIF_SENDWININICHANGE);
}

Widget::~Widget()
{

    delete ui;
}


void Widget::on_pushButton_clicked()
{
    if(desktopWnd) //设置父窗体为桌面
    {
////      SetParent((HWND)v.winId(),desktopWnd);
      SetParent((HWND)m.videowidget.winId(),desktopWnd);
    }
//   m.player->stop();
   paths = QFileDialog::getOpenFileName(this,"open","../","Vdieo(*.mp4)");
//    v.setWindowFlags(Qt::FramelessWindowHint);
//    v.setAttribute(Qt::WA_TranslucentBackground);
//    v.setWindowFlag(Qt::Dialog);
//    v.showFullScreen();
//    v.StartPlay();
//    showMinimized();


}

void Widget::on_pushButton_2_clicked()
{
   m.startplay(paths);
   showMinimized();
}
void Widget::closeEvent(QCloseEvent *event)
{
    m.videowidget.close();
//    m.player->stop();
//    m.~Media();
    event->accept();
}
void Widget::dealsig()
{
    m.hide();
    this->show();
}

void Widget::on_pushButton_3_clicked()
{
    m.show();
    this->hide();
}

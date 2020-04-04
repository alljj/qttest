#include "widget.h"
#include "ui_widget.h"
#include <QMovie>
#include <QLabel>
#include <QFileDialog>
#include <QMessageBox>
#include <QDir>
#include <QFileInfo>
Widget::Widget(QWidget *parent)
    : QWidget(parent),
    ui(new Ui::Widget)
{

    ui->setupUi(this);

   connect(&m,&Media::sendmes,this,&Widget::dealsig);

   last_1 = "D:/UpupooResource/1800010625/preview.jpg";
   ui->pushButton_jpg1->setStyleSheet(QString("QPushButton{border-image:url(%1)}").arg(last_1));

  if(paths==NULL)
  {
      ui->pushButton_2->setEnabled(false);
  }

//   getfileNames("D:/UpupooResource/1800010625/preview.jpg");
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

   paths = QFileDialog::getOpenFileName(this,"open","../","Vdieo(*.mp4)");
   qDebug()<<paths;
   if(paths!=NULL)
   ui->pushButton_2->setEnabled(true);



}

void Widget::on_pushButton_2_clicked()
{
    if(desktopWnd) //设置父窗体为桌面
    {

      SetParent((HWND)m.videowidget.winId(),desktopWnd);
    }
   m.videowidget.hide();
   m.startplay(paths);
   showMinimized();
}
void Widget::closeEvent(QCloseEvent *event)
{
    m.videowidget.close();

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


void Widget::on_pushButton_jpg1_clicked()
{

  QMessageBox *Msgbox   = new QMessageBox(QMessageBox::Question,"提示","是否采用该壁纸或者更改为其他壁纸",QMessageBox::Yes|QMessageBox::No|QMessageBox::Cancel);

  Msgbox->button(QMessageBox::Yes)->setText("采用");
  Msgbox->button(QMessageBox::No)->setText("更改");
  Msgbox->button(QMessageBox::Cancel)->setText("取消");

  int res = Msgbox->exec();

   if(res == QMessageBox::Yes)
   {
      paths = getfileNames(last_1);
      ui->pushButton_2->setEnabled(true);
      qDebug()<<paths;
      return ;
   }
  if(res == QMessageBox::No)
  {
   jpg1 = QFileDialog::getOpenFileName(this,"open","../","picture(*.jpg *.png)");

   qDebug()<<jpg1;

      if(jpg1 != NULL)
     {
      last_1 = jpg1;

      ui->pushButton_jpg1->setStyleSheet(QString("QPushButton{border-image:url(%1)}").arg(last_1));
     }
      ui->pushButton_jpg1->setStyleSheet(QString("QPushButton{border-image:url(%1)}").arg(last_1));

   }
   if(res == QMessageBox::Cancel)
   {
       return;
   }

}
QString Widget::getfileNames(const QString &path)
{

       QDir dir(path);
       dir.cdUp( );
       QStringList nameFilters;
       nameFilters << "*.MP4";
       qDebug() << "dir start " << dir << "dir end";

       QStringList infolist = dir.entryList(nameFilters,QDir::NoDotAndDotDot | QDir::AllEntries);

       qDebug()<<infolist;

       QString str1 = infolist.join("");

       qDebug()<<str1;

       QString str = dir.canonicalPath();

       qDebug()<<str;

       QString pathav = QString("%1/%2").arg(str).arg(str1);

       qDebug()<<pathav;

       return pathav;
}

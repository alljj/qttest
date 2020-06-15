#include "drawing.h"
#include <QFileDialog>
drawing::drawing(QWidget *parent) : QMainWindow(parent),is_start(true)
{
    qDebug()<<"drawing config";
     send_sec = 0;
     time_ck  = 0;
     max_x= 15;
     max_y = 15;
     series = new QLineSeries();
     chart = new QChart();
     chart->legend()->setVisible(true);
     chart->addSeries(series);
     chartview = new QChartView(chart);
     this->setCentralWidget(chartview);
     axisX = new QValueAxis;
     axisX->setRange(0,max_x);
     axisX->setTitleText("t/ms"); //����X��������

     axisY = new QValueAxis;
     axisY->setRange(0,max_y);  //����Y���귶Χ
     axisY->setTitleText("au/mV");  //����Y��������
     axisY->setLabelFormat("%u");
     axisY->setTickCount(4);
     axisY->setMinorTickCount(4);

     chart->addAxis(axisX, Qt::AlignBottom);  //����XY���λ�����º���
     chart->addAxis(axisY, Qt::AlignLeft);

     series->attachAxis(axisX);
     series->attachAxis(axisY);

      QScreen * screen = QGuiApplication::primaryScreen();

      save = new QxtGlobalShortcut(this);
      if(save->setShortcut((QKeySequence("Ctrl+S"))))
      {
//        qDebug()<<"����ͼ��";
        connect(save, &QxtGlobalShortcut::activated,[=]()
        {
            QString path =QFileDialog::getSaveFileName(this,"save","../","img(*.png)");
            QPixmap p = screen->grabWindow(chartview->winId());
            QImage image = p.toImage();
            image.save(path);
        });
      }

}

void drawing::updata_value(QString data)
{
    series->clear();
    qDebug()<<"start paint";
    qDebug()<<data.toInt();
    if(is_start)
    {
        time_ck = startTimer(10);
    }
    is_start = false;
    mydata.append(QPointF(send_sec,data.toInt()));
    qDebug()<<mydata;
    if(mydata.last().x()>max_x)
    {
        max_x =  mydata.last().x();
      axisX->setRange(0,max_x);
    }
    if(mydata.last().y()>max_y)
    {
        max_y = mydata.last().y();
        axisY->setRange(0,max_y);
    }
    series->append(mydata);
}

void drawing::timerEvent(QTimerEvent *event)
{
   if(event->timerId()==time_ck)
   {
       send_sec+=10;
   }
}

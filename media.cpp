#include "media.h"
#include "ui_media.h"
#include <QThread>
Media::Media(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Media)
{
    ui->setupUi(this);
    player=new QMediaPlayer();
    playlist=new QMediaPlaylist();
    videowidget.setAspectRatioMode(Qt::KeepAspectRatioByExpanding);
    player->setPlaylist(playlist);
    player->setVolume(0);
    player->setVideoOutput(&videowidget);
    ui->label->setNum(0);
    ui->horizontalSlider->setMaximum(100);
    connect(player,SIGNAL(durationChanged(qint64)),this,SLOT(setD(qint64)));//获取视频时长
    connect(player,SIGNAL(positionChanged(qint64)),this,SLOT(ResetVideo(qint64)));//获取播放位
//    controlvoice();
    connect(ui->pushButton,&QPushButton::clicked,this,&Media::returnparent);
//    connect(ui->horizontalSlider,&QSlider::valueChanged,player,&QMediaPlayer::setVolume);
    connect(ui->horizontalSlider,&QSlider::valueChanged,
            [=](int i)
    {

      ui->label->setNum(i);
      player->setVolume(i);
    }
    );
}

Media::~Media()
{
    delete ui;
}
void Media::startplay(QString path)
{
//    playlist->clear();
//    playlist->addMedia(QUrl::fromLocalFile(path));

    player->setMedia(QUrl::fromLocalFile(path));
    player->play();
    QThread::sleep(2);
    videowidget.showFullScreen();



}
void Media::setD(qint64 d)
{
    duration=d;

}

void Media::ResetVideo(qint64 currentInfo)
{
        if(currentInfo==duration)
        {//如果播放完了

            player->setPosition(0);//设置当前进度为0
            player->play();//重新播放
        }

}

void Media::controlvoice()
{


}

void  Media::returnparent()
{

    emit sendmes();
    qDebug()<<"切换主窗口";
}

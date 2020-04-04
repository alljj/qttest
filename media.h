#ifndef MEDIA_H
#define MEDIA_H
#include <QSpinBox>
#include <QSlider>
#include <QWidget>
#include <QMediaPlayer>
#include <QMediaPlaylist>
#include <QVideoWidget>
#include <QSlider>
namespace Ui {
class Media;
}

class Media : public QWidget
{
    Q_OBJECT

public:
    explicit Media(QWidget *parent = nullptr);
    ~Media();
    QMediaPlayer *player;
    QMediaPlaylist *playlist;
    QVideoWidget videowidget;
    void startplay(QString path);
    void controlvoice();
    void returnparent();
private:
    Ui::Media *ui;
    qint64 duration;
signals:
      void sendmes();
private slots:
    void setD(qint64 d);//获取持续时间的槽
    void ResetVideo(qint64 currentTime);//获取当前时间，用来进行循环播放的槽

};

#endif // MEDIA_H

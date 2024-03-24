#ifndef PLAYER_H
#define PLAYER_H
#include <QGraphicsItem>
#include <QObject>
#include <QGraphicsTextItem>
#include <QApplication>
#include <QMediaPlayer>

class Player: public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Player();
public:
    void keyPressEvent(QKeyEvent * event);
    void increase();
    void decrease();
    QGraphicsTextItem* scoreMsg;
    QGraphicsTextItem* healthMsg;
    QGraphicsTextItem* endMsg;
public slots:
    void createEnemy();
private:
    int score;
    int health;
    QMediaPlayer* bulletSound;

};

#endif // PLAYER_H

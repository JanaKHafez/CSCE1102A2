#ifndef BULLET_H
#define BULLET_H
#include <QGraphicsItem>
#include "player.h"
#include <QObject>
#include <QMediaPlayer>


class Bullet: public QObject, public QGraphicsPixmapItem
{

    Q_OBJECT
public:
    Bullet(Player* p);

public slots:
    void move();
private:
    Player* player;
    QMediaPlayer* killSound;

};

#endif // BULLET_H

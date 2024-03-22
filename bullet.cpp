#include"bullet.h"
#include <QGraphicsScene>
#include <QTimer>
#include <QList>
#include <enemy.h>
#include <player.h>
//#include <QMediaPlayer>


Bullet::Bullet(Player* p):QObject(), QGraphicsPixmapItem() {

    setPixmap(QPixmap(":/img/img/red_laser.png"));

        // *******  Generating the Bullets automatically ********
    QTimer * timer = new QTimer();
    connect(timer, SIGNAL(timeout()),this,SLOT (move()));
    timer->start(50);
    player = p;

    //killSound = new QMediaPlayer();
    //killSound->setMedia(QUrl(":/sounds/sounds/invaderkilled.wav"))

}

// Move function is used to 1-  move the bullet upwards
                         // 2- Handle the collision of the bullets with enemies
void Bullet:: move()
{
        // *******  Getting the colliding items with the Bullet ********
    QList collidingItems = this->collidingItems();
    for(int i = 0; i < collidingItems.size(); i++)
    {
        if(typeid(*(collidingItems[i])) == typeid(Enemy))
        {
            scene()->removeItem(collidingItems[i]);
            delete collidingItems[i];
            scene()->removeItem(this);
            delete this;
            player->increase();

            /*
            if (killSound->state() == QMediaPlayer::PlayingState) {
                killSound->setPosition(0);
            }
            else if (killSound->state() == QMediaPlayer::StoppedState) {
                killSound->play();
            }
            */

            return;
        }
    }
    // *******  Moving the bullets upward ********
    setPos(x(),y()-20);
    if(y()>800)
    {
        scene()->removeItem(this);
        delete this;
    }

}

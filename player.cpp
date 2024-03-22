#include <QKeyEvent>
#include "bullet.h"
#include <QGraphicsScene>
#include <QGraphicsTextItem>
#include <QDebug>
#include "enemy.h"
//#include <QMediaPlayer>


Player::Player():QObject(), QGraphicsPixmapItem() {
    score = 0;
    health = 3;
    QFont font;
    font.setPointSize(16);
    QColor color1(Qt::blue);
    scoreMsg = new QGraphicsTextItem(QString("Score: ") + QString::number(score));
    scoreMsg->setFont(font);
    scoreMsg->setDefaultTextColor(color1);
    scoreMsg->setPos(10, 40);
    QColor color2(Qt::red);
    healthMsg = new QGraphicsTextItem(QString("Health: ") + QString::number(health));
    healthMsg->setFont(font);
    healthMsg->setDefaultTextColor(color2);
    healthMsg->setPos(10, 10);

    //bulletSound = new QMediaPlayer();
    //bulletSound->setMedia(QUrl(":/sounds/sounds/shoot.wav"))
}

void Player::keyPressEvent(QKeyEvent *event)
{
        // *******  Event Handling for the Player ********
    if(event->key()== Qt::Key_Left)
    {
        if(x()>0) // to prevent the player from getting out of the screen
        {
        setPos(x()-10,y());
        }
    }
    else if(event->key()== Qt::Key_Right)

    { if(x()+100<800) // to prevent the player from getting out of the screen
        setPos(x()+10,y());
    }
    else if(event->key()== Qt::Key_Space)
    {
        Bullet * bullet = new Bullet(this);
        bullet->setPos(x()+30,y());
        scene()->addItem(bullet);

        /*
        if (bulletSound->state() == QMediaPlayer::PlayingState) {
            bulletSound->setPosition(0);
        }
        else if (bulletSound->state() == QMediaPlayer::StoppedState) {
            bulletSound->play();

        }
        */
    }
}

 // CreateEnemy function used to create the eneimes
void Player::createEnemy()
{
  Enemy* enemy = new Enemy();
  //! Doesn't work (doesn't show enemy):
  scene()->addItem(enemy);

}

void Player::increase()
{
    scene()->removeItem(scoreMsg);
    score++;
    scoreMsg->setPlainText((QString("Score: ") + QString::number(score)));
    scene()->addItem(scoreMsg);
}

void Player::decrease()
{
    scene()->removeItem(healthMsg);
    health--;
    healthMsg->setPlainText((QString("Health: ") + QString::number(health)));
    scene()->addItem(healthMsg);
    if(health < 1)
    {
        QApplication::quit();
    }
}

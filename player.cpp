#include <QKeyEvent>
#include "bullet.h"
#include <QGraphicsScene>
#include <QGraphicsTextItem>
#include <QDebug>
#include "enemy.h"
#include <qtimer.h>
#include <QMediaPlayer>
#include <QAudioOutput>
#include <QThread>


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
    font.setPointSize(72);
    endMsg = new QGraphicsTextItem(QString("GAME OVER"));
    endMsg->setFont(font);
    endMsg->setDefaultTextColor(color2);
    endMsg->setPos(130, 150);

    bulletSoundOutput = new QAudioOutput();
    bulletSoundOutput->setVolume(50);
    bulletSound = new QMediaPlayer();
    bulletSound->setAudioOutput(bulletSoundOutput);
    bulletSound->setSource(QUrl("qrc:/sounds/sounds/shoot.wav"));
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

        bulletSound->play();
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
        QFont font;
        font.setPointSize(72);
        QGraphicsTextItem* sMsg = new QGraphicsTextItem(QString("Score: ") + QString::number(score));
        sMsg->setFont(font);
        sMsg->setDefaultTextColor(Qt::blue);
        sMsg->setPos(130, 250);
        scene()->addItem(sMsg);
        scene()->addItem(endMsg);
        QTimer::singleShot(5000, qApp, &QApplication::quit);
    }
}

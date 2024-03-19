#ifndef PLAYER_H
#define PLAYER_H
#include <QGraphicsItem>
#include <QObject>
#include <QGraphicsTextItem>

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
public slots:
    void createEnemy();
private:
    int score;
    int health;

};

#endif // PLAYER_H

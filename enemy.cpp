#include "enemy.h"
#include "player.h"
#include <QGraphicsScene>
#include <stdlib.h> // rand() -> to generate really large integer
#include <QTimer>
#include <QDebug>

Enemy::Enemy() {

    //! Change to relative path:
    setPixmap(QPixmap("C:/Users/janak/OneDrive/Documents/Computing/QT/session 5 - game - Exercise/chicken.png"));

        // *******  Setting the postion of the enemy within the view dimensions ********
    int random_number = rand() % 700;
    setPos(random_number,0);

        // *******  Moving the enemies downwards automatically every 50 milli second ********
    QTimer * timer = new QTimer();
    connect(timer, SIGNAL(timeout()),this,SLOT (move()));
    timer->start(50);

}
// Function move: move the enemy downwards untill the end of the scene then remove it and delete it
void Enemy:: move()
{
    QList collidingItems = this->collidingItems();
    for(int i = 0; i < collidingItems.size(); i++)
    {
        if(typeid(*(collidingItems[i])) == typeid(Player))
        {
            scene()->removeItem(this);
            delete this;
            Player *player = dynamic_cast<Player*>(collidingItems[i]);
            if (player)
                player->decrease();
            return;
        }
    }
    setPos(x(),y()+5);
    if(y()+100>800)
    {
        scene()->removeItem(this);
            delete this;
    }
}

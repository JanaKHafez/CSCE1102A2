
#include <QApplication>
#include <QGraphicsRectItem>
#include <QGraphicsScene>
#include<QGraphicsView>
#include "player.h"
#include <QTimer>
#include <QDebug>
#include <QBrush>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // *******  Create the View ********
    QGraphicsView *view=new QGraphicsView();
    view->setFixedSize(800, 600);
    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    // ******* Create the Scene ********
    QGraphicsScene *scene = new QGraphicsScene();
    scene->setSceneRect(0, 0, 800, 600);

    // *******   Assign scene to the view   ***************
    view->setScene(scene);
    view->show();

    // *******  Create the Player ********
    Player *player = new  Player();

    // *******  Setting the foucs to the Player ********
    //! Change to relative path:
    player->setPixmap(QPixmap("C:/Users/janak/OneDrive/Documents/Computing/QT/session 5 - game - Exercise/ship.png"));
    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();
    // *******  Adjust the location of the Player (middle of the screen) ********
    player->setPos(view->width()/2, view->height() - 100);
    scene->addItem(player);

    scene->addItem(player->healthMsg);
    scene->addItem(player->scoreMsg);
    // *******  Create the Enemies automatically ********
    QTimer * time = new QTimer();
    QObject::connect(time, SIGNAL(timeout()),player,SLOT(createEnemy()));
    time->start(2000);

    return a.exec();

    //! Bonus step missing
}

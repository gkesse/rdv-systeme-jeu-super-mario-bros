#pragma once

#include <QGraphicsScene>
#include <QTimer>

class QScrollBar;

class BackgroundItem;
class Coin;
class Player;

class MyScene : public QGraphicsScene
{
    Q_OBJECT

public:
    explicit MyScene(QScrollBar *s, QObject *parent = 0);
    ~MyScene();

protected:
    void keyPressEvent(QKeyEvent *event);
    void timerEvent(QTimerEvent *);

private:
    void initPlayField();
    void checkTimer();

private slots:
    void movePlayer();

private:
    qreal m_groundLevel;
    QScrollBar *scroll;
    QTimer m_timer;

    BackgroundItem *m_sky;
    BackgroundItem *m_ground;
    BackgroundItem *m_Scene;
    BackgroundItem *m_countLogo;
    BackgroundItem *m_scoreLogo;
    BackgroundItem *m_timerLogo;
    BackgroundItem *m_wall2;
    BackgroundItem *m_wall;
    BackgroundItem *m_wall3;
    BackgroundItem *m_flag;
    BackgroundItem *m_castle;

    Coin *m_coins;

    Player *m_player;
};

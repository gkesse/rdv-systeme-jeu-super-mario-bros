#pragma once

#include <QGraphicsScene>
#include <QTimer>

class QScrollBar;

class BackgroundItem;
class Coin;
class Player;
class SmallMario;

class MyScene : public QGraphicsScene
{
    Q_OBJECT

public:
    explicit MyScene(QScrollBar *s, QObject *parent = 0);
    ~MyScene();

protected:
    void keyPressEvent(QKeyEvent *event);
    void keyReleaseEvent(QKeyEvent *event);
    void timerEvent(QTimerEvent *);

private:
    void initPlayField();
    void checkTimer();

private slots:
    void movePlayer();

private:
    qreal m_groundLevel;
    bool littleMario;
    int m_velocity;

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
    Coin *m_coins2;
    Coin *m_coins3;
    Coin *m_coins4;
    Coin *m_coins5;
    Coin *m_coins6;
    Coin *m_coins7;
    Coin *m_coins8;
    Coin *m_coins9;
    Coin *m_coins10;
    Coin *m_coins11;
    Coin *m_coins12;
    Coin *m_coins13;
    Coin *m_coins14;
    Coin *m_coins15;
    Coin *m_coins16;
    Coin *m_coins17;
    Coin *m_coins18;
    Coin *m_coins19;
    Coin *m_coins20;
    Coin *m_coins21;
    Coin *m_coins22;
    Coin *m_coins23;
    Coin *m_coins24;
    Coin *m_coins25;
    Coin *m_coins26;

    Coin *m_coins27;
    Coin *m_coins28;
    Coin *m_coins29;
    Coin *m_coins30;

    Coin *m_coins32;
    Coin *m_coins33;
    Coin *m_coins34;
    Coin *m_coins35;
    Coin *m_coins36;

    Coin *m_coins37;
    Coin *m_coins38;
    Coin *m_coins39;
    Coin *m_coins40;
    Coin *m_coins41;

    Coin *m_coins42;
    Coin *m_coins43;
    Coin *m_coins44;
    Coin *m_coins45;
    Coin *m_coins46;
    Coin *m_coins47;

    Coin *m_coins48;
    Coin *m_coins49;
    Coin *m_coins50;
    Coin *m_coins51;
    Coin *m_coins52;

    Coin *m_coins53;
    Coin *m_coins54;
    Coin *m_coins55;
    Coin *m_coins56;

    Coin *m_coins57;
    Coin *m_coins58;
    Coin *m_coins59;
    Coin *m_coins60;

    Coin *m_coins61;
    Coin *m_coins62;
    Coin *m_coins63;
    Coin *m_coins64;
    Coin *m_coins65;
    Coin *m_coins66;
    Coin *m_coins67;
    Coin *m_coins68;

    Coin *m_coins69;
    Coin *m_coins70;
    Coin *m_coins71;

    Coin *m_coins72;
    Coin *m_coins73;
    Coin *m_coins74;

    Coin *m_coins75;
    Coin *m_coins76;
    Coin *m_coins77;
    Coin *m_coins78;
    Coin *m_coins79;
    Coin *m_coins80;

    Coin *m_coins81;
    Coin *m_coins82;
    Coin *m_coins83;
    Coin *m_coins84;
    Coin *m_coins85;
    Coin *m_coins86;

    Coin *m_coins87;
    Coin *m_coins88;
    Coin *m_coins89;
    Coin *m_coins90;
    Coin *m_coins91;
    Coin *m_coins92;
    Coin *m_coins93;
    Coin *m_coins94;
    Coin *m_coins95;
    Coin *m_coins96;
    Coin *m_coins97;
    Coin *m_coins98;
    Coin *m_coins99;
    Coin *m_coins100;

    Player *m_player;
    SmallMario *m_smallPlayer;
    QGraphicsItem *m_platform;
};

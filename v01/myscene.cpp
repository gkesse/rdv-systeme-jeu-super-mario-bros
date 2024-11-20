#include "myscene.h"
#include "backgrounditem.h"
#include "coin.h"

#include <QScrollBar>
#include <QKeyEvent>
#include <QDebug>

MyScene::MyScene(QScrollBar *s, QObject *parent)
    : QGraphicsScene(0, 0, 8000, 720, parent),
      scroll(s)
{
    initPlayField();

    m_timer.setInterval(20);
    connect(&m_timer, &QTimer::timeout, this, &MyScene::movePlayer);
}

MyScene::~MyScene()
{
}

void MyScene::keyPressEvent(QKeyEvent *event)
{
    if (event->isAutoRepeat())
        return;

    switch (event->key())
    {
    case Qt::Key_Right:
        qDebug() << "MyScene::keyPressEvent...Qt::Key_Right...";
        break;
    case Qt::Key_Left:
        qDebug() << "MyScene::keyPressEvent...Qt::Key_Left...";
        break;
    case Qt::Key_F:
        qDebug() << "MyScene::keyPressEvent...Qt::Key_F...";
        break;
    case Qt::Key_Space:
        qDebug() << "MyScene::keyPressEvent...Qt::Key_Space...";
        break;
    default:
        break;
    }
}

void MyScene::timerEvent(QTimerEvent *)
{
    m_coins->nextFrame2();
}

void MyScene::initPlayField()
{
    setSceneRect(0, 0, 8000, 720);

    m_sky = new BackgroundItem(QPixmap(":/images/sky"));
    m_sky->setPos(0, 0);
    addItem(m_sky);

    m_groundLevel = 660;

    m_ground = new BackgroundItem(QPixmap(":/images/ground"));
    m_ground->setPos(0, m_groundLevel);
    addItem(m_ground);

    m_Scene = new BackgroundItem(QPixmap(":/images/Scene"));
    m_Scene->setPos(0, m_groundLevel - m_Scene->boundingRect().height());
    addItem(m_Scene);

    m_countLogo = new BackgroundItem(QPixmap(":/images/count"));
    m_countLogo->setPos(30, m_groundLevel - 652);
    addItem(m_countLogo);

    m_scoreLogo = new BackgroundItem(QPixmap(":/images/scoretext"));
    m_scoreLogo->setPos(900, m_groundLevel - 647);
    addItem(m_scoreLogo);

    m_timerLogo = new BackgroundItem(QPixmap(":/images/clock"));
    m_timerLogo->setPos(1100, m_groundLevel - 654);
    addItem(m_timerLogo);

    m_wall2 = new BackgroundItem(QPixmap(":/images/wallg.png"));
    m_wall2->setPos(3100, m_groundLevel - m_wall2->boundingRect().height());
    addItem(m_wall2);

    m_wall = new BackgroundItem(QPixmap(":/images/wallf2.png"));
    m_wall->setPos(2900, m_groundLevel - m_wall->boundingRect().height());
    addItem(m_wall);

    m_flag = new BackgroundItem(QPixmap(":/images/flag"));
    m_flag->setPos(7234, m_groundLevel - m_flag->boundingRect().height());
    addItem(m_flag);

    m_castle = new BackgroundItem(QPixmap(":/images/castle"));
    m_castle->setPos(7637, m_groundLevel - m_castle->boundingRect().height());
    addItem(m_castle);

    m_coins = new Coin();
    m_coins->setPos(1300, m_groundLevel - m_coins->boundingRect().height() - 200);
    addItem(m_coins);

    startTimer(100);
}

void MyScene::checkTimer()
{
}

void MyScene::movePlayer()
{
    qDebug() << "MyScene::movePlayer...";
}
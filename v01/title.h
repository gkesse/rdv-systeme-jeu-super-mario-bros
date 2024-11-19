#pragma once

#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QRegularExpression>

#include "database.h"

class QScrollBar;
class QPropertyAnimation;
class QPushButton;
class QLineEdit;
class QLabel;
class QRadioButton;

class View;
class AnimatedGraphicsItem;

class Title : public QGraphicsScene
{
    Q_OBJECT

public:
    explicit Title(View *view, QWidget *parent = 0);
    ~Title();

private:
    bool regExUserTest();

private slots:
    void on_radioButton_toggled(bool checked);
    void login();
    void newUser();
    void developerLogin();
    void quitProgram();

private:
    const int width = 1280;
    const int height = 720;

    View *viewer;

    AnimatedGraphicsItem *background;
    QPropertyAnimation *animation;
    QGraphicsPixmapItem *foreground;
    QGraphicsPixmapItem *logo;

    QLabel *userName;
    QLineEdit *userLine;
    QLabel *password;
    QLineEdit *passLine;
    QLabel *radioText;
    QRadioButton *radioButton;

    QPushButton *loginButton;
    QPushButton *developerButton;
    QPushButton *quitButton;
    QPushButton *newUserButton;

    Connection DBase;

    QRegularExpression *usernameRegEx;
    QRegularExpressionMatch *usernamenameMatch;
    QRegularExpression *passwordRegEx;
    QRegularExpressionMatch *passwordMatch;
};

class AnimatedGraphicsItem : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
    Q_PROPERTY(QPointF pos READ pos WRITE setPos)
};

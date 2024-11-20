#include "title.h"
#include "view.h"
#include "loginwindow.h"
#include "myscene.h"
#include "soundmanager.h"

#include <QScrollBar>
#include <QPropertyAnimation>
#include <QPushButton>
#include <QLineEdit>
#include <QLabel>
#include <QRadioButton>
#include <QFontDatabase>
#include <QApplication>
#include <QMessageBox>
#include <QDebug>

Title::Title(View *view, QWidget *parent)
    : QGraphicsScene(parent)
{
    setFocus();
    setSceneRect(0, 0, 1280, 720);

    viewer = view;

    viewer->setViewportUpdateMode(QGraphicsView::SmartViewportUpdate);

    background = new AnimatedGraphicsItem;
    background->setPixmap(QPixmap(":/images/background.png"));
    animation = new QPropertyAnimation(background, "pos");
    animation->setLoopCount(-1);
    animation->setDuration(150000);
    animation->setStartValue(QPoint(-width, 0));
    animation->setEndValue(QPoint(0, 0));
    animation->start();
    addItem(background);

    foreground = new QGraphicsPixmapItem(QPixmap(":/images/title.png"));
    addItem(foreground);

    logo = new QGraphicsPixmapItem(QPixmap(":/images/logo.png"));
    logo->setPos((width - logo->boundingRect().width()) / 2, height / 12);
    addItem(logo);

    viewer->sceneSet(this);

    int id = QFontDatabase::addApplicationFont(":/font/mvboli.ttf");
    QFontDatabase::applicationFontFamilies(id);

    QFont font("MV Boli", 15, QFont::Bold);

    userName = new QLabel(viewer);
    userName->setFont(font);
    userName->setText("Username");
    userName->setObjectName(QString("username"));
    userName->setGeometry(QRect(430, 420, 100, 25));

    userLine = new QLineEdit(viewer);
    userLine->setToolTip("Enter an email address");
    userLine->setGeometry(QRect(540, 420, 200, 25));

    password = new QLabel(viewer);
    password->setFont(font);
    password->setText("Password");
    password->setObjectName(QString("password"));
    password->setGeometry(QRect(430, 450, 100, 25));

    passLine = new QLineEdit(viewer);
    passLine->setEchoMode(QLineEdit::Password);
    passLine->setObjectName(QString("passLine"));
    passLine->setToolTip("Enter password");
    passLine->setGeometry(QRect(540, 450, 200, 25));

    radioButton = new QRadioButton(viewer);
    radioButton->setObjectName(QString("radioButton"));
    radioButton->setToolTip("Click to show password text");
    radioButton->setGeometry(QRect(760, 450, 100, 25));
    connect(radioButton, SIGNAL(toggled(bool)), this, SLOT(on_radioButton_toggled(bool)));

    radioText = new QLabel(viewer);
    radioText->setText("Show Password");
    radioText->setToolTip("Click to show password text");
    radioText->setGeometry(QRect(780, 450, 100, 25));

    loginButton = new QPushButton(viewer);
    loginButton->setText("Login");
    loginButton->setObjectName(QString("loginButton"));
    loginButton->setToolTip("Click to login");
    loginButton->setGeometry(QRect(540, 500, 100, 32));
    connect(loginButton, SIGNAL(clicked()), this, SLOT(login()));

    newUserButton = new QPushButton(viewer);
    newUserButton->setText("New User");
    newUserButton->setObjectName(QString("newUserButton"));
    newUserButton->setToolTip("Click to create a login");
    newUserButton->setGeometry(QRect(642, 500, 100, 32));
    connect(newUserButton, SIGNAL(clicked()), this, SLOT(newUser()));

    developerButton = new QPushButton(viewer);
    developerButton->setText("Guest Login");
    developerButton->setObjectName(QString("developerButton"));
    developerButton->setToolTip("Login as a guest");
    developerButton->setGeometry(QRect(540, 535, 100, 32));
    connect(developerButton, SIGNAL(clicked()), this, SLOT(developerLogin()));

    quitButton = new QPushButton(viewer);
    quitButton->setText("Quit");
    quitButton->setObjectName(QString("quitButton"));
    quitButton->setToolTip("Quit program");
    quitButton->setGeometry(QRect(642, 535, 100, 32));
    connect(quitButton, SIGNAL(clicked()), this, SLOT(quitProgram()));

    soundManager = new SoundManager(view);
    connect(this, &Title::playSound, soundManager, &SoundManager::playSoundEffect);
    emit playSound("theme");

    scroll = viewer->horizontalScrollBar();
}

Title::~Title()
{
}

bool Title::regExUserTest()
{
    bool accessGranted = false;
    usernameRegEx = new QRegularExpression("^([a-z0-9_\\.-]+)@([\\da-z\\.-]+)\\.([a-z\\.]{2,6})$");
    usernamenameMatch = new QRegularExpressionMatch(usernameRegEx->match(userLine->text()));
    accessGranted = usernamenameMatch->hasMatch();

    if (accessGranted)
        return true;
    else
        return false;
}

void Title::on_radioButton_toggled(bool checked)
{
    if (checked)
    {
        passLine->setEchoMode(QLineEdit::Normal);
    }
    else
    {
        passLine->setEchoMode(QLineEdit::Password);
    }
}

void Title::login()
{
    if (userLine->text().isEmpty())
    {
        QMessageBox msgBox;
        msgBox.setText("You must enter a username.");
        msgBox.setWindowTitle("Warning");
        msgBox.exec();
        return;
    }
    if (regExUserTest() == false)
    {
        QMessageBox msgBoxFail;
        msgBoxFail.setText("That is not a valid email address.");
        msgBoxFail.setWindowTitle("Warning");
        msgBoxFail.exec();
        return;
    }
    if (passLine->text().isEmpty())
    {
        QMessageBox msgBox2;
        msgBox2.setText("You must enter a password.  ");
        msgBox2.setWindowTitle("Warning");
        msgBox2.exec();
        return;
    }

    Query uInput;
    uInput.uName = userLine->text();
    uInput.pass = passLine->text();

    qDebug() << "La récupération des données de l'utilisateur a réussi."
             << "|username=" << uInput.uName
             << "|password=" << uInput.pass;

    DataB::DBConnect(DBase);

    if (DataB::cUsrPas(uInput, DBase.db))
    {
        loginButton->close();
        newUserButton->close();
        passLine->close();
        userLine->close();
        userName->close();
        password->close();
        radioButton->close();
        radioText->close();
        developerButton->close();
        quitButton->close();

        scene = new MyScene(scroll, this);
        viewer->sceneSet(scene);
        emit playSound("stopMusic");
    }
    else
    {
        QMessageBox msgBox3(viewer);
        msgBox3.setText(" Combination of username and/or password incorrect.");
        msgBox3.setWindowTitle("Warning");
        msgBox3.exec();
        return;
    }
}

void Title::newUser()
{
    loginWindow = new LoginWindow();
    loginWindow->exec();
}

void Title::developerLogin()
{
    loginButton->close();
    newUserButton->close();
    passLine->close();
    userLine->close();
    userName->close();
    password->close();
    radioButton->close();
    radioText->close();
    developerButton->close();
    quitButton->close();

    scene = new MyScene(scroll, this);
    viewer->sceneSet(scene);
    emit playSound("stopMusic");
}

void Title::quitProgram()
{
    qApp->quit();
}

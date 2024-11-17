#include "mainwindow.h"
#include "settings.h"
#include "view.h"
#include "title.h"
#include "about_dialog.h"
#include "weatherstation.h"

#include <QAction>
#include <QMenu>
#include <QMenuBar>
#include <QDebug>
#include <QApplication>
#include <QGuiApplication>
#include <QScreen>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    createActions();
    createMenus();
    createScene();
    setCentralWidget(view);
    setWindowTitle("ReadyMario™ - Super Mario Bros Game");
}

MainWindow::~MainWindow()
{
}

void MainWindow::setSize()
{
    this->setFixedSize(1280, 740);
    int x = ((QGuiApplication::primaryScreen()->geometry().width() - width()) / 2);
    int y = ((QGuiApplication::primaryScreen()->geometry().height() - height()) / 2);
    this->move(x, y);
}

void MainWindow::closeEvent(QCloseEvent *event)
{
    setting->writeSettings();
    qApp->quit();
}

void MainWindow::createActions()
{
    returnAction = new QAction(tr("&Return to Title"), this);
    returnAction->setShortcut(tr("Ctrl+R"));
    returnAction->setStatusTip(tr("Return to the title screen"));

    for (int i = 0; i < maxState; ++i)
    {
        saveStateAction[i] = new QAction("-Empty-", this);
        loadStateAction[i] = new QAction("-Empty-", this);
    }

    quitAction = new QAction(tr("&Quit"), this);
    quitAction->setShortcut(tr("Ctrl+Q"));
    quitAction->setStatusTip(tr("Quit"));
    connect(quitAction, SIGNAL(triggered()), this, SLOT(close()));

    fullScreenAction = new QAction(tr("Full Screen"), this);
    fullScreenAction->setShortcut(tr("F11"));
    fullScreenAction->setStatusTip(tr("Fullscreen View"));
    connect(fullScreenAction, SIGNAL(triggered()), this, SLOT(alterScreen()));

    settingsAction = new QAction(tr("&Settings"), this);
    settingsAction->setStatusTip(tr("Change Game Settings"));
    connect(settingsAction, SIGNAL(triggered()), this, SLOT(settings()));

    aboutAction = new QAction(tr("&About"), this);
    connect(aboutAction, SIGNAL(triggered()), this, SLOT(showAbout()));

    weatherStationAction = new QAction(tr("&Date and Time"), this);
    weatherStationAction->setShortcut(tr("Ctrl+w"));
    weatherStationAction->setStatusTip(tr("Date and Time"));
    connect(weatherStationAction, SIGNAL(triggered()), this, SLOT(showWeather()));

    setting = new Settings(this);
    setting->readSettings();
}

void MainWindow::createMenus()
{
    fileMenu = menuBar()->addMenu(tr("&File"));
    fileMenu->addAction(returnAction);

    saveSubMenu = fileMenu->addMenu(tr("&Save"));
    loadSubMenu = fileMenu->addMenu(tr("&Load"));

    for (int i = 0; i < maxState; i++)
    {
        saveSubMenu->addAction(saveStateAction[i]);
        loadSubMenu->addAction(loadStateAction[i]);
    }

    fileMenu->addAction(quitAction);

    viewMenu = menuBar()->addMenu(tr("&View"));
    viewMenu->addAction(fullScreenAction);

    toolMenu = menuBar()->addMenu(tr("&Tools"));
    toolMenu->setToolTip("Game Settings");
    toolMenu->addAction(settingsAction);

    helpMenu = menuBar()->addMenu(tr("&Help"));
    helpMenu->setToolTip("Developer Info");
    helpMenu->addAction(aboutAction);

    weatherMenu = menuBar()->addMenu(tr("&UDP"));
    weatherMenu->setToolTip("UDP ");
    weatherMenu->addAction(weatherStationAction);
}

void MainWindow::createScene()
{
    view = new View;
    title = new Title(view);
}

void MainWindow::alterScreen()
{
    setting->alterState();
}

void MainWindow::settings()
{
    setting->show();
}

void MainWindow::showAbout()
{
    about = new About_Dialog;
    about->exec();
}

void MainWindow::showWeather()
{
    weatherStation = new WeatherStation();
    weatherStation->exec();
}

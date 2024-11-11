#include "mainwindow.h"

#include <QAction>
#include <QMenu>
#include <QMenuBar>
#include <QDebug>
#include <QApplication>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    createActions();
    createMenus();
}

MainWindow::~MainWindow()
{
}

void MainWindow::closeEvent(QCloseEvent *event)
{
    qDebug() << "MainWindow::closeEvent...";
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

void MainWindow::alterScreen()
{
    qDebug() << "MainWindow::alterScreen...";
}

void MainWindow::settings()
{
    qDebug() << "MainWindow::settings...";
}

void MainWindow::showAbout()
{
    qDebug() << "MainWindow::showAbout...";
}

void MainWindow::showWeather()
{
    qDebug() << "MainWindow::showWeather...";
}

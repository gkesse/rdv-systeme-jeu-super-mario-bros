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
}

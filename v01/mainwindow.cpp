#include "mainwindow.h"

#include <QAction>
#include <QMenu>
#include <QMenuBar>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    createActions();
    createMenus();
}

MainWindow::~MainWindow()
{
}

void MainWindow::createActions()
{
    returnAction = new QAction(tr("&Return to Title"), this);
    returnAction->setShortcut(tr("Ctrl+R"));
    returnAction->setStatusTip(tr("Return to the title screen"));

    for (int i = 0; i < maxState; ++i)
    {
        saveStateAction[i] = new QAction("-Empty-", this);
    }
}

void MainWindow::createMenus()
{
    fileMenu = menuBar()->addMenu(tr("&File"));
    fileMenu->addAction(returnAction);

    saveSubMenu = fileMenu->addMenu(tr("&Save"));

    for (int i = 0; i < maxState; i++)
    {
        saveSubMenu->addAction(saveStateAction[i]);
    }
}

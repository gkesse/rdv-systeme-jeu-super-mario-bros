#include "loginwindow.h"
#include "ui_loginwindow.h"

#include <QDebug>

LoginWindow::LoginWindow(QWidget *parent)
    : QDialog(parent),
      ui(new Ui::LoginWindow)
{
    ui->setupUi(this);
}

LoginWindow::~LoginWindow()
{
    delete ui;
}

void LoginWindow::on_btnSubmit_clicked()
{
    qDebug() << "LoginWindow::on_btnSubmit_clicked...";
}

void LoginWindow::on_btnCancel_clicked()
{
    qDebug() << "LoginWindow::on_btnCancel_clicked...";
}

void LoginWindow::on_radShowPassword_clicked(bool checked)
{
    qDebug() << "LoginWindow::on_radShowPassword_clicked...";
}

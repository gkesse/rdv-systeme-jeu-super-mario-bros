#include "loginwindow.h"
#include "ui_loginwindow.h"
#include "database.h"

#include <QMessageBox>
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

bool LoginWindow::regExUsernameTest()
{
    bool emailAddress = false;
    userRegEx = new QRegularExpression("^([a-z0-9_\\.-]+)@([\\da-z\\.-]+)\\.([a-z\\.]{2,6})$");
    userMatch = new QRegularExpressionMatch(userRegEx->match(ui->edtUsername->text()));
    emailAddress = userMatch->hasMatch();

    if (emailAddress)
        return true;
    else
        return false;
}

bool LoginWindow::regExPasswordTest()
{
    bool passSatisfied = false;
    passRegEx = new QRegularExpression("^[a-zA-Z0-9_-]{7,20}$");
    passMatch = new QRegularExpressionMatch(passRegEx->match(ui->edtPassword->text()));
    passSatisfied = passMatch->hasMatch();

    if (passSatisfied)
        return true;
    else
        return false;
}

void LoginWindow::on_btnSubmit_clicked()
{
    if (ui->edtUsername->text().isEmpty())
    {
        QMessageBox::warning(this, "Warning", "You must enter a username to register");
        return;
    }
    if (regExUsernameTest() == false)
    {
        QMessageBox::warning(this, "Warning", "That is not a valid email address");
        return;
    }
    if (ui->edtPassword->text().isEmpty())
    {
        QMessageBox::warning(this, "Warning", "You must enter a password to register");
        return;
    }
    if (regExPasswordTest() == false)
    {
        QMessageBox::warning(this, "Warning", "Password may contain A-Z upper or lowercase, 0-9, _underscore, and -hyphen. Max length is 20. Minimum length is 7.Please try again.");
        return;
    }

    Query uInput;
    uInput.uName = ui->edtUsername->text();
    uInput.pass = ui->edtPassword->text();

    qDebug() << "La récupération des données de l'utilisateur a réussi."
             << "|username=" << uInput.uName
             << "|password=" << uInput.pass;

    DataB::DBConnect(DBase);

    if (DataB::regUsr(uInput, DBase.db))
    {
        QMessageBox::information(this, "Success", " Registration was successful. You may now login");
        reject();
    }
    else
    {
        QMessageBox::warning(this, "Warning", " Username is already taken. Please try again.");
    }
}

void LoginWindow::on_btnCancel_clicked()
{
    reject();
}

void LoginWindow::on_radShowPassword_clicked(bool checked)
{
    if (checked)
    {
        ui->edtPassword->setEchoMode(QLineEdit::Normal);
    }
    else
    {
        ui->edtPassword->setEchoMode(QLineEdit::Password);
    }
}

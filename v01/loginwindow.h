#pragma once

#include <QDialog>
#include <QRegularExpression>

#include "database.h"

namespace Ui
{
    class LoginWindow;
}

class LoginWindow : public QDialog
{
    Q_OBJECT

public:
    explicit LoginWindow(QWidget *parent = 0);
    ~LoginWindow();

private:
    bool regExUsernameTest();
    bool regExPasswordTest();

private slots:
    void on_btnSubmit_clicked();
    void on_btnCancel_clicked();
    void on_radShowPassword_clicked(bool checked);

private:
    Ui::LoginWindow *ui;

    QRegularExpression *userRegEx;
    QRegularExpressionMatch *userMatch;
    QRegularExpression *passRegEx;
    QRegularExpressionMatch *passMatch;

    Connection DBase;
};

#pragma once

#include <QDialog>

class QVBoxLayout;
class QPixmap;
class QLabel;

namespace Ui
{
    class About_Dialog;
}

class About_Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit About_Dialog(QWidget *parent = 0);
    ~About_Dialog();

private:
    Ui::About_Dialog *ui;
    QVBoxLayout *mainVBox;
    QPixmap *logo;
    QLabel *logoLbl;
    QLabel *schoolInfo;
    QLabel *classInfo;
    QLabel *groupMember1;
};
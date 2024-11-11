#include "settings.h"

#include <QLabel>
#include <QLineEdit>
#include <QHBoxLayout>
#include <QVBoxLayout>

Settings::Settings(QWidget *parent)
    : QDialog(parent)
{
    label = new QLabel(tr("Developer Login: "));
    lineEdit = new QLineEdit;
    lineEdit->setObjectName(QString("lineEdit"));
    label->setBuddy(lineEdit);

    QHBoxLayout *firstLayout = new QHBoxLayout;
    firstLayout->addWidget(label);
    firstLayout->addWidget(lineEdit);

    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->addLayout(firstLayout);

    setLayout(mainLayout);
    setWindowModality(Qt::WindowModal);
    setWindowTitle("Settings");
}

Settings::~Settings()
{
}

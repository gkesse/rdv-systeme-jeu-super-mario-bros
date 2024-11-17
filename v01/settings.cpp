#include "settings.h"

#include <QLabel>
#include <QLineEdit>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QSlider>
#include <QSpinBox>
#include <QRadioButton>
#include <QPushButton>
#include <QSettings>

Settings::Settings(QWidget *parent)
    : QDialog(parent)
{
    setWindowModality(Qt::WindowModal);
    setWindowTitle("ReadyMario™ - Settings");

    label = new QLabel(tr("Developer Login: "));
    lineEdit = new QLineEdit;
    lineEdit->setObjectName(QString("lineEdit"));
    label->setBuddy(lineEdit);

    screenSize = new QLabel(tr("Full Screen"));
    fullScreenView = new QRadioButton("On");
    windowedView = new QRadioButton("Off");
    windowedView->setChecked(true);

    bgmLabel = new QLabel(tr("Music"));
    bgmSlider = new QSlider(Qt::Horizontal);
    bgmSpinBox = new QSpinBox;
    bgmSlider->setRange(0, 100);
    bgmSpinBox->setRange(0, 100);

    sfxLabel = new QLabel(tr("Sound Effects"));
    sfxSlider = new QSlider(Qt::Horizontal);
    sfxSpinBox = new QSpinBox;
    sfxSlider->setRange(0, 100);
    sfxSpinBox->setRange(0, 100);

    confirmButton = new QPushButton(tr("Confirm"));
    cancelButton = new QPushButton(tr("Cancel"));

    QHBoxLayout *firstLayout = new QHBoxLayout;
    firstLayout->addWidget(label);
    firstLayout->addWidget(lineEdit);

    QHBoxLayout *secondLayout = new QHBoxLayout;
    secondLayout->addWidget(screenSize);
    secondLayout->addStretch();
    secondLayout->addWidget(fullScreenView);
    secondLayout->addWidget(windowedView);
    secondLayout->addStretch();

    QHBoxLayout *thirdLayout = new QHBoxLayout;
    thirdLayout->addWidget(bgmLabel);
    thirdLayout->addStretch();
    thirdLayout->addWidget((bgmSlider));
    thirdLayout->addWidget(bgmSpinBox);

    QHBoxLayout *fourthLayout = new QHBoxLayout;
    fourthLayout->addWidget(sfxLabel);
    fourthLayout->addWidget((sfxSlider));
    fourthLayout->addWidget(sfxSpinBox);

    QHBoxLayout *fifthLayout = new QHBoxLayout;
    fifthLayout->addWidget(confirmButton);
    fifthLayout->addWidget(cancelButton);

    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->addLayout(firstLayout);
    mainLayout->addLayout(secondLayout);
    mainLayout->addLayout(thirdLayout);
    mainLayout->addLayout(fourthLayout);
    mainLayout->addLayout(fifthLayout);
    setLayout(mainLayout);

    connect(bgmSpinBox, SIGNAL(valueChanged(int)), bgmSlider, SLOT(setValue(int)));
    connect(bgmSlider, SIGNAL(valueChanged(int)), bgmSpinBox, SLOT(setValue(int)));
    connect(bgmSlider, SIGNAL(valueChanged(int)), this, SLOT(bgmChanged()));
    connect(sfxSpinBox, SIGNAL(valueChanged(int)), sfxSlider, SLOT(setValue(int)));
    connect(sfxSlider, SIGNAL(valueChanged(int)), sfxSpinBox, SLOT(setValue(int)));
    connect(sfxSlider, SIGNAL(valueChanged(int)), this, SLOT(sfxChanged()));
    connect(confirmButton, SIGNAL(clicked(bool)), this, SLOT(confirm()));
    connect(cancelButton, SIGNAL(clicked(bool)), this, SLOT(reject()));
}

Settings::~Settings()
{
}

void Settings::setState()
{
    full = fullScreenView->isChecked();
    window = windowedView->isChecked();
    bgm = bgmSlider->value();
    sfx = sfxSlider->value();
}

void Settings::revertState()
{
    fullScreenView->setChecked(full);
    windowedView->setChecked(window);
    bgmSlider->setValue(bgm);
    sfxSlider->setValue(sfx);
}

void Settings::readSettings()
{
    QSettings settings("ReadyDev-Group", "Ready-Mario-Game");
    fullScreenView->setChecked(settings.value("fullscreen", false).toBool());
    bgmSlider->setValue(settings.value("bgm", 50).toInt());
    sfxSlider->setValue(settings.value("sfx", 50).toInt());
    confirm();
}

void Settings::writeSettings()
{
    QSettings settings("ReadyDev-Group", "Ready-Mario-Game");
    settings.setValue("fullscreen", fullScreenView->isChecked());
    settings.setValue("bgm", bgmSlider->value());
    settings.setValue("sfx", sfxSlider->value());
}

void Settings::alterState()
{
    if (full)
    {
        windowedView->setChecked(true);
    }
    else
    {
        fullScreenView->setChecked(true);
    }
    show();
    confirm();
}

void Settings::confirm()
{
    emit fullScreen(fullScreenView->isChecked());
    emit bgmAdjust(bgmSlider->value());
    emit sfxAdjust(sfxSlider->value());
    setState();
    close();
}

void Settings::reject()
{
    revertState();
    QDialog::reject();
}

void Settings::bgmChanged()
{
    emit bgmAdjust(bgmSlider->value());
}

void Settings::sfxChanged()
{
    emit sfxAdjust(sfxSlider->value());
}

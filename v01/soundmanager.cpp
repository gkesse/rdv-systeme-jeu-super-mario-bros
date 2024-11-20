#include "soundmanager.h"
#include "ui_soundmanager.h"

#include <QSoundEffect>
#include <QMediaPlayer>
#include <QDebug>

SoundManager::SoundManager(QWidget *parent)
    : QDialog(parent),
      ui(new Ui::SoundManager)
{
    ui->setupUi(this);

    mario_jump = new QSoundEffect(this);
    mario_jump->setSource(QUrl("qrc:/audio/jump.wav"));
    mario_jump->setLoopCount(0);
    mario_jump->setVolume(.25f);

    soundPlayer = new QMediaPlayer(this);
    soundPlayer->setMedia(QUrl("qrc:/audio/ThemeSong.mp3"));
}

SoundManager::~SoundManager()
{
    delete ui;
}

void SoundManager::playSoundEffect(QString which)
{
    if (which == "mario_jump")
    {
        mario_jump->play();
    }
    else if (which == "theme")
    {
        soundPlayer->play();
    }
}
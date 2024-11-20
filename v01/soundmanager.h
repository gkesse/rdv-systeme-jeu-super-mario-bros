#pragma once

#include <QDialog>

class QSoundEffect;
class QMediaPlayer;

namespace Ui
{
    class SoundManager;
}

class SoundManager : public QDialog
{
    Q_OBJECT

public:
    explicit SoundManager(QWidget *parent = 0);
    ~SoundManager();

public slots:
    void playSoundEffect(QString);

private:
    Ui::SoundManager *ui;
    QSoundEffect *mario_jump;
    QMediaPlayer *soundPlayer;
};

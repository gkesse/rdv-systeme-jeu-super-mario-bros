#pragma once

#include <QDialog>

class QLabel;
class QLineEdit;
class QSlider;
class QSpinBox;
class QRadioButton;
class QPushButton;

class Settings : public QDialog
{
    Q_OBJECT

public:
    explicit Settings(QWidget *parent = 0);
    ~Settings();
    void setState();
    void revertState();
    void readSettings();
    void writeSettings();
    void alterState();

private slots:
    void confirm();
    void reject();
    void bgmChanged();
    void sfxChanged();

signals:
    void fullScreen(bool);
    void bgmAdjust(int);
    void sfxAdjust(int);

private:
    QLabel *label;
    QLineEdit *lineEdit;

    QLabel *screenSize;
    QRadioButton *fullScreenView;
    QRadioButton *windowedView;

    QLabel *bgmLabel;
    QSlider *bgmSlider;
    QSpinBox *bgmSpinBox;

    QLabel *sfxLabel;
    QSlider *sfxSlider;
    QSpinBox *sfxSpinBox;

    QPushButton *confirmButton;
    QPushButton *cancelButton;

    bool full;
    bool window;
    int bgm;
    int sfx;
};

#include <QDialog>

class QLabel;
class QLineEdit;
class QSlider;
class QSpinBox;
class QRadioButton;

class Settings : public QDialog
{
    Q_OBJECT

public:
    explicit Settings(QWidget *parent = 0);
    ~Settings();

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
};

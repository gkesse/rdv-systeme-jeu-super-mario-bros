#include <QDialog>

class QLabel;
class QLineEdit;

class Settings : public QDialog
{
    Q_OBJECT

public:
    explicit Settings(QWidget *parent = 0);
    ~Settings();

private:
    QLabel *label;
    QLineEdit *lineEdit;
};

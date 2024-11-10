#include <QApplication>
#include <QMainWindow>
#include <QSplashScreen>
#include <QTimer>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    a.setWindowIcon(QIcon(":/images/icon"));

    QSplashScreen splash;
    splash.setPixmap(QPixmap(":/images/mariosplash.png"));
    splash.show();

    QMainWindow mainWin;

    QTimer::singleShot(500, &splash, SLOT(close()));
    QTimer::singleShot(500, &mainWin, SLOT(show()));

    return a.exec();
}

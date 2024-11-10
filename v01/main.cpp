#include <QApplication>
#include <QMainWindow>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    a.setWindowIcon(QIcon(":/images/icon"));
    QMainWindow mainWin;
    mainWin.show();
    return a.exec();
}

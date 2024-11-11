#include <QMainWindow>

class QMenu;
class QAction;

class MainWindow : public QMainWindow
{
    Q_OBJECT

private:
    enum
    {
        maxState = 10
    };

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

protected:
    void closeEvent(QCloseEvent *event);

private:
    void createActions();
    void createMenus();

private slots:
    void alterScreen();
    void settings();
    void showAbout();

private:
    QMenu *fileMenu;
    QAction *returnAction;

    QMenu *saveSubMenu;
    QAction *saveStateAction[maxState];

    QMenu *loadSubMenu;
    QAction *loadStateAction[maxState];

    QAction *quitAction;

    QMenu *viewMenu;
    QAction *fullScreenAction;

    QMenu *toolMenu;
    QAction *settingsAction;

    QMenu *helpMenu;
    QAction *aboutAction;
};
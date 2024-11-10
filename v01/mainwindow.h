#include <QMainWindow>

class QMenu;
class QAction;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    void createActions();
    void createMenus();

private:
    QMenu *fileMenu;
    QAction *returnAction;
};
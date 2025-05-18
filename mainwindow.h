#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

//We use forward declarations with imported classes
class ModuleTester;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);

    ~MainWindow();
    //as usual, we can use a forward-declared class in a method
    void useModule(const ModuleTester &mtester);
public slots:
    void resetFirstLabel();

private:
    //or store a pointer
    ModuleTester *mt;
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H

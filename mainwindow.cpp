#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "pure_cpp.h" //traditional header for comparison
import TestModule;    //exports ModuleTester

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , mt(nullptr)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->label->setText(Pure_cpp().name());
    mt = new ModuleTester{}; //it works!
    ui->label_2->setText(mt->name());
    connect(ui->pushButton, &QPushButton::clicked, this, &MainWindow::resetFirstLabel);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete mt;
}

void MainWindow::useModule(const ModuleTester &mtester)
{
    ui->label->setText(mtester.name());
}

void MainWindow::resetFirstLabel()
{
    ModuleTester modTester{"Changed through module-defined class"};
    useModule(modTester);
}

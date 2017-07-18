#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    if (QDir::setCurrent(PLEXE_EXAMPLE_DIR)){
        std::cout << "PATH IS SET !" << std::endl;
    }
    else {
        std::cout << "CANNOT SET PATH !!!!" << std::endl;
    }
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    QProcess process;


    process.startDetached("./run", QStringList() << "-u" << "Cmdenv"
                          << "-c" << ui->configurationDropdown->currentText()
                          << "-r" << ui->controllerDropdown->currentText());
    process.waitForFinished(-1);
}

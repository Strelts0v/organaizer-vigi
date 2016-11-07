#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_addButton_clicked()
{

}

void MainWindow::on_businessButton_clicked()
{

}

void MainWindow::on_contactsButton_clicked()
{

}

void MainWindow::on_deleteButton_clicked()
{

}

void MainWindow::on_exitButton_clicked()
{

}

void MainWindow::on_notesButton_clicked()
{

}

void MainWindow::on_updateButton_clicked()
{

}

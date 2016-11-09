#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "blankforbusinessitem.h"
#include "blankforcontactsitem.h"
#include "blankfornotesitem.h"
#include <QDialog>
#include <QWidget>
#include <QObject>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    context = new ApplicationContext();
    table = new Table(ui->tableWidget);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_addButton_clicked()
{
    if(QString::compare(table->getTopic()->getTopicName(), "business") == 0){
        BlankForBusinessItem* blank = new BlankForBusinessItem();
        blank->show();
    } else if (QString::compare(table->getTopic()->getTopicName(), "contacts") == 0){
        BlankForContactsItem* blank = new BlankForContactsItem();
        blank->show();
    } else if (QString::compare(table->getTopic()->getTopicName(), "notes") == 0){
        BlankForNotesItem* blank = new BlankForNotesItem();
        blank->show();
    }
    // TODO
}

void MainWindow::on_businessButton_clicked()
{
    table->setTopic(context->getBusinessTopic());
    table->refreshTableContent();
}

void MainWindow::on_contactsButton_clicked()
{
    table->setTopic(context->getContactsTopic());
    table->refreshTableContent();
}

void MainWindow::on_deleteButton_clicked()
{

}

void MainWindow::on_exitButton_clicked()
{

}

void MainWindow::on_notesButton_clicked()
{
    table->setTopic(context->getNotesTopic());
    table->refreshTableContent();
}

void MainWindow::on_updateButton_clicked()
{

}

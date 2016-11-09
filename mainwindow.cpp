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

void MainWindow::addNewTopicItem(QStringList dataList)
{
    table->addRow(dataList);
}

void MainWindow::on_addButton_clicked()
{
    BlankForBusinessItem* bBlank = new BlankForBusinessItem();
    BlankForContactsItem* cBlank = new BlankForContactsItem();
    BlankForNotesItem* nBlank = new BlankForNotesItem();

    if(QString::compare(table->getTopic()->getTopicName(), "business") == 0){
        bBlank->show();
    } else if (QString::compare(table->getTopic()->getTopicName(), "contacts") == 0){
        cBlank->show();
    } else if (QString::compare(table->getTopic()->getTopicName(), "notes") == 0){
        nBlank->show();
    }

    QObject::connect(bBlank, SIGNAL(sendDataforNewBusiness(QStringList)), this, SLOT(addNewTopicItem(QStringList)));
    QObject::connect(cBlank, SIGNAL(sendDataforNewContact(QStringList)), this, SLOT(addNewTopicItem(QStringList)));
    QObject::connect(nBlank, SIGNAL(sendDataforNewNote(QStringList)), this, SLOT(addNewTopicItem(QStringList)));
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
    this->close();
}

void MainWindow::on_notesButton_clicked()
{
    table->setTopic(context->getNotesTopic());
    table->refreshTableContent();
}

void MainWindow::on_updateButton_clicked()
{

}

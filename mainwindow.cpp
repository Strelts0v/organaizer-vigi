#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "blankforbusinessitem.h"
#include "blankforcontactsitem.h"
#include "blankfornotesitem.h"
#include <QDialog>
#include <QWidget>
#include <QObject>
#include <QDebug>
#include <vector>

using namespace std;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    context = new ApplicationContext();
    table = new Table(ui->tableWidget);
    isButtonsEnable = false;
    disableTableButtons();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::addNewTopicItem(QStringList dataList)
{
    table->addRow(dataList);
}

void MainWindow::updateTopicItems(QStringList dataList)
{
    table->updateRows(dataList);
}

void MainWindow::deleteTopicItem(int id)
{
    table->deleteRow(id);
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
    if(!isButtonsEnable){
        enableTableButtons();
    }
}

void MainWindow::on_contactsButton_clicked()
{
    table->setTopic(context->getContactsTopic());
    table->refreshTableContent();
    if(!isButtonsEnable){
        enableTableButtons();
    }
}

void MainWindow::on_deleteButton_clicked()
{
    if(ui->tableWidget->selectedItems().isEmpty()){
        return;
    }
    QList<QTableWidgetItem *> selectedList = ui->tableWidget->selectedItems();

    int listCount = 0; bool ok;
    QVector<int> idList;
    idList.push_back(ui->tableWidget->item(selectedList.at(0)->row(), ui->tableWidget->columnCount() - 1)->text().toInt(&ok, 10));
    listCount++;
    for (int i = 1; i < selectedList.count(); i++)
    {
        int id = ui->tableWidget->item(selectedList.at(i)->row(), ui->tableWidget->columnCount() - 1)->text().toInt(&ok, 10);
        if(idList[listCount - 1] != id){
            idList.push_back(id);
            listCount++;
        }
    }
    for(int i = 0; i < idList.size(); i++){
        deleteTopicItem(idList[i]);
    }
    table->refreshTableContent();
}

void MainWindow::on_exitButton_clicked()
{
    this->close();
}

void MainWindow::on_notesButton_clicked()
{
    table->setTopic(context->getNotesTopic());
    table->refreshTableContent();
    if(!isButtonsEnable){
        enableTableButtons();
    }
}

void MainWindow::on_updateButton_clicked()
{
    QStringList updateDataList;
    for(int i = 0; i < ui->tableWidget->rowCount(); i++){
        for(int j = 0;  j < ui->tableWidget->columnCount(); j++){
            updateDataList.push_back(ui->tableWidget->item(i, j)->text());
        }
    }
    updateTopicItems(updateDataList);
}

void MainWindow::enableTableButtons()
{
    ui->addButton->setEnabled(true);
    ui->deleteButton->setEnabled(true);
    ui->updateButton->setEnabled(true);
    ui->findButton->setEnabled(true);
    ui->findEdit->setEnabled(true);
    isButtonsEnable = true;
}

void MainWindow::disableTableButtons()
{
    ui->addButton->setDisabled(true);
    ui->deleteButton->setDisabled(true);
    ui->updateButton->setDisabled(true);
    ui->findButton->setDisabled(true);
    ui->findEdit->setDisabled(true);
    isButtonsEnable = false;
}

void MainWindow::on_findButton_clicked()
{
    table->find(ui->findEdit->text());
}

void MainWindow::on_actionAdd_triggered()
{
    on_addButton_clicked();
}

void MainWindow::on_actionDelete_triggered()
{
    on_deleteButton_clicked();
}

void MainWindow::on_actionUpdate_triggered()
{
    on_updateButton_clicked();
}

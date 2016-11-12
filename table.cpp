#include "table.h"

Table::Table()
{}

Table::Table(QTableWidget* tableWidget)
{
    this->tableWidget = tableWidget;
}

Table::~Table()
{
    //delete topic;
    //delete tableWidget;
}

Topic* Table::getTopic()
{
    return topic;
}

void Table::setTopic(Topic* topic)
{
    this->topic = topic;
    refreshTableContent();
}

void Table::addRow(QStringList dataList)
{
    topic->addItem(dataList);
    refreshTableContent();
}

void Table::updateRows(QStringList dataList)
{
    topic->updateItems(dataList);
    refreshTableContent();
}

void Table::deleteRow(int rowId)
{
    topic->deleteItem(rowId);
    refreshTableContent();
}

QStringList Table::find(QString pattern)
{
    return topic->find(pattern);
}

void Table::refreshTableContent()
{
    QStringList dataList = topic->getTopicContent();
    topic->setRowCount(dataList.size()/topic->getColumnCount());
    tableWidget->setColumnCount(topic->getColumnCount());
    tableWidget->setRowCount(topic->getRowCount());
    tableWidget->setHorizontalHeaderLabels(topic->getColumnHeaders());

    setTopicStyleSheet();

    int count = 0;
    for(int i = 0; i < tableWidget->rowCount(); i++)
        for(int j = 0; j < tableWidget->columnCount(); j++){
            QTableWidgetItem *item = new QTableWidgetItem(dataList[count++]);
            item->setBackgroundColor(Qt::green);
            tableWidget->setItem(i, j, item);
        }
}

void Table::setTopicStyleSheet()
{
    if(QString::compare(topic->getTopicName(), "business") == 0){
        setBusinessStyleSheet();
    } else if(QString::compare(topic->getTopicName(), "contacts") == 0){
        setContactsStyleSheet();
    } else if(QString::compare(topic->getTopicName(), "notes") == 0){
        setNotesStyleSheet();
    }
}

void Table::setBusinessStyleSheet()
{
    tableWidget->setColumnHidden(0, false);
    tableWidget->setColumnHidden(1, false);
    tableWidget->setColumnHidden(2, false);
    tableWidget->setColumnHidden(3, false);
    tableWidget->setColumnHidden(4, true);
    tableWidget->setWordWrap(true);
    tableWidget->setColumnWidth(0, 80);
    tableWidget->setColumnWidth(1, 80);
    tableWidget->setColumnWidth(2, 278);
    tableWidget->setColumnWidth(3, 75);
}

void Table::setContactsStyleSheet()
{
    tableWidget->setColumnHidden(0, false);
    tableWidget->setColumnHidden(1, false);
    tableWidget->setColumnHidden(2, false);
    tableWidget->setColumnHidden(3, true);
    tableWidget->setWordWrap(true);
    tableWidget->setColumnWidth(0, 150);
    tableWidget->setColumnWidth(1, 150);
    tableWidget->setColumnWidth(2, 212);
}

void Table::setNotesStyleSheet()
{
    tableWidget->setColumnHidden(0, false);
    tableWidget->setColumnHidden(1, false);
    tableWidget->setColumnHidden(2, true);
    tableWidget->setWordWrap(true);
    tableWidget->setColumnWidth(0, 150);
    tableWidget->setColumnWidth(1, 364);
}

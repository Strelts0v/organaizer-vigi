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

    int count = 0;
    for(int i = 0; i < tableWidget->rowCount(); i++)
        for(int j = 0; j < tableWidget->columnCount(); j++){
            QTableWidgetItem *item = new QTableWidgetItem(dataList[count++]);
            tableWidget->setItem(i, j, item);
        }
}

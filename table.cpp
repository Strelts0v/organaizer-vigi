#include "table.h"

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

void Table::updateRow(QStringList dataList, int rowId)
{
    topic->updateItem(dataList, rowId);
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
    // заполнение таблицы
}

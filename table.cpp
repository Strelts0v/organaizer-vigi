#include "table.h"
#include <QPalette>

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
    QStringList dataList = topic->find(pattern);
    refreshTableContent(dataList);
}

void Table::refreshTableContent()
{
    QStringList dataList = topic->getTopicContent();
    topic->setRowCount(dataList.size() / topic->getColumnCount());
    tableWidget->setColumnCount(topic->getColumnCount());
    tableWidget->setRowCount(topic->getRowCount());

    setHorizontalHeaders(topic->getColumnHeaders());

    int count = 0;
    for(int i = 0; i < tableWidget->rowCount(); i++)
        for(int j = 0; j < tableWidget->columnCount(); j++){
            QTableWidgetItem *item = new QTableWidgetItem(dataList[count++]);
            item->setTextAlignment(Qt::AlignCenter);
            tableWidget->setItem(i, j, item);
        }
    setTopicStyleSheet();
}

void Table::refreshTableContent(QStringList dataList)
{
    topic->setRowCount(dataList.size() / topic->getColumnCount());
    tableWidget->setColumnCount(topic->getColumnCount());
    tableWidget->setRowCount(topic->getRowCount());

    setHorizontalHeaders(topic->getColumnHeaders());

    int count = 0;
    for(int i = 0; i < tableWidget->rowCount(); i++)
        for(int j = 0; j < tableWidget->columnCount(); j++){
            QTableWidgetItem *item = new QTableWidgetItem(dataList[count++]);
            item->setTextAlignment(Qt::AlignCenter);
            tableWidget->setItem(i, j, item);
        }
    setTopicStyleSheet();
}

void Table::setHorizontalHeaders(QStringList headerLabels)
{
    for(int i = 0; i < headerLabels.size(); i++){
        QTableWidgetItem *headerItem = new QTableWidgetItem(headerLabels[i]);
        tableWidget->setHorizontalHeaderItem(i, headerItem);
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
    const int headColumn = 0;
    const int deadlineColumn =1;
    const int descriptionColumn = 2;
    const int priorityColumn = 3;

    for(int i = 0; i < tableWidget->rowCount(); i++){
        QTableWidgetItem *item = tableWidget->item(i, 3);
        bool ok;
        int priority = item->text().toInt(&ok, 10);
        switch (priority) {
        case 1:
            item->setBackgroundColor(QColor(255, 218, 185));
            item->setText("high"); tableWidget->setItem(i, priorityColumn, item);
            tableWidget->item(i, headColumn)->setBackgroundColor(QColor(255, 218, 185));
            tableWidget->item(i, deadlineColumn)->setBackgroundColor(QColor(255, 218, 185));
            tableWidget->item(i, descriptionColumn)->setBackgroundColor(QColor(255, 218, 185));
            break;
        case 2:
            item->setBackgroundColor(QColor(255, 250, 205));
            item->setText("medium"); tableWidget->setItem(i, 3, item);
            tableWidget->item(i, headColumn)->setBackgroundColor(QColor(255, 250, 205));
            tableWidget->item(i, deadlineColumn)->setBackgroundColor(QColor(255, 250, 205));
            tableWidget->item(i, descriptionColumn)->setBackgroundColor(QColor(255, 250, 205));
            break;
        case 3:
            item->setBackgroundColor(QColor(240, 255, 255));
            item->setText("low"); tableWidget->setItem(i, 3, item);
            tableWidget->item(i, headColumn)->setBackgroundColor(QColor(240, 255, 255));
            tableWidget->item(i, deadlineColumn)->setBackgroundColor(QColor(240, 255, 255));
            tableWidget->item(i, descriptionColumn)->setBackgroundColor(QColor(240, 255, 255));
            break;
        default:
            break;
        }
    }
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

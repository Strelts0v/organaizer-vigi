#include "topic.h"

Topic::Topic()
{}

Topic::Topic(QString topicName, int rowCount, int columnCount,
      QStringList columnHeaders)
{
    this->topicName = topicName;
    this->rowCount = rowCount;
    this->columnCount = columnCount;
    this->columnHeaders = columnHeaders;
}

Topic::~Topic()
{}

QString Topic::getTopicName()
{
    return topicName;
}

void Topic::setTopicName(QString topicName)
{
    this->topicName = topicName;
}

int Topic::getRowCount()
{
    return rowCount;
}

void Topic::setRowCount(int rowCount)
{
    this->rowCount = rowCount;
}

int Topic::getColumnCount()
{
    return columnCount;
}

void Topic::setColumnCount(int columnCount)
{
    this->columnCount = columnCount;
}

QStringList Topic::getColumnHeaders()
{
    return columnHeaders;
}

void Topic::setColumnHeaders(QStringList columnHeaders)
{
    this->columnHeaders = columnHeaders;
}

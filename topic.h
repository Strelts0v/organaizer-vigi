#ifndef TOPIC_H
#define TOPIC_H

#include <QString>
#include <QStringList>

namespace app {

class Topic;

}

class Topic
{
private:

    QString topicName;

    int rowCount;

    int columnCount;

    QStringList columnHeaders;

public:

    Topic();

    Topic(QString topicName, int rowCount, int columnCount,
          QStringList columnHeaders);

    ~Topic();

    QString getTopicName();

    void setTopicName(QString topicName);

    int getRowCount();

    void setRowCount(int rowCount);

    int getColumnCount();

    void setColumnCount(int columnCount);

    QStringList getColumnHeaders();

    void setColumnHeaders(QStringList columnHeaders);

    virtual addItem(QStringList data) = 0;

    virtual updateItem(QStringList data, int id) = 0;

    virtual deleteItem(int id) = 0;

    virtual find(QString pattern) = 0;

    virtual QStringList getTopicContent() = 0;
};

#endif // TOPIC_H

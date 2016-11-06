#ifndef BUSINESSTOPIC_H
#define BUSINESSTOPIC_H

#include <QString>
#include <QStringList>
#include <topic.h>

namespace app{

class BusinessTopic;

}

class BusinessTopic : private Topic
{
public:

    BusinessTopic(QString topicName, int rowCount, int columnCount,
                  QStringList columnHeaders);

    ~BusinessTopic();

    void addItem(QStringList data);

    void updateItem(QStringList data, int rowId);

    void deleteItem(int rowId);

    QStringList find(QString pattern);

    QStringList getTopicContent();

};

#endif // BUSINESSTOPIC_H

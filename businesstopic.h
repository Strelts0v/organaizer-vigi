#ifndef BUSINESSTOPIC_H
#define BUSINESSTOPIC_H

#include <QString>
#include <QStringList>
#include <topic.h>

namespace app{
class BusinessTopic;
}

class BusinessTopic : public Topic
{
public:

    BusinessTopic();

    BusinessTopic(QString topicName, int rowCount, int columnCount,
                  QStringList columnHeaders);

    ~BusinessTopic();

    void addItem(QStringList data);

    void updateItems(QStringList dataList);

    void deleteItem(int rowId);

    QStringList find(QString pattern);

    QStringList getTopicContent();

private:

    int convertPriorityToInteger(QString priority);

};

#endif // BUSINESSTOPIC_H

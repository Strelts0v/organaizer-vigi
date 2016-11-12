#ifndef CONTACTSTOPIC_H
#define CONTACTSTOPIC_H

#include <QString>
#include <QStringList>
#include <topic.h>

namespace app{
class ContactsTopic;
}

class ContactsTopic : public Topic
{
public:

    ContactsTopic();

    ContactsTopic(QString topicName, int rowCount, int columnCount,
                  QStringList columnHeaders);

    ~ContactsTopic();

    void addItem(QStringList data);

    void updateItems(QStringList dataList);

    void deleteItem(int rowId);

    QStringList find(QString pattern);

    QStringList getTopicContent();

};

#endif // CONTACTSTOPIC_H

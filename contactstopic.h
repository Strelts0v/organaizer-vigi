#ifndef CONTACTSTOPIC_H
#define CONTACTSTOPIC_H

#include <QString>
#include <QStringList>
#include <topic.h>

namespace app{

class ContactsTopic;

}

class ContactsTopic : private Topic
{
public:

    ContactsTopic(QString topicName, int rowCount, int columnCount,
                  QStringList columnHeaders);

    ~ContactsTopic();

    void addItem(QStringList data);

    void updateItem(QStringList data, int id);

    void deleteItem(int id);

    QStringList find(QString pattern);

    QStringList getTopicContent();

};

#endif // CONTACTSTOPIC_H

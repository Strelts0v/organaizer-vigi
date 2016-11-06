#ifndef NOTESTOPIC_H
#define NOTESTOPIC_H

#include <QString>
#include <QStringList>
#include <topic.h>

namespace app{

class NotesTopic;

}

class NotesTopic : private Topic
{
public:

    NotesTopic(QString topicName, int rowCount, int columnCount,
                  QStringList columnHeaders);

    ~NotesTopic();

    void addItem(QStringList data);

    void updateItem(QStringList data, int id);

    void deleteItem(int id);

    QStringList find(QString pattern);

    QStringList getTopicContent();

};

#endif // NOTESTOPIC_H

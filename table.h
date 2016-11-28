#ifndef TABLE_H
#define TABLE_H

#include <QString>
#include <QStringList>
#include <QTableWidget>
#include <QItemDelegate>
#include "topic.h"

namespace app {
class Table;
}

class Table
{
private:

    Topic* topic;

    QTableWidget* tableWidget;

public:

    Table();

    Table(QTableWidget* tableWidget);

    ~Table();

    Topic* getTopic();

    void setTopic(Topic* topic);

    void addRow(QStringList dataList);

    void updateRows(QStringList dataList);

    void deleteRow(int rowId);

    void find(QString pattern);

    void refreshTableContent();

private:

    void refreshTableContent(QStringList dataList);

    void setHorizontalHeaders(QStringList headerLabels);

    void setTopicStyleSheet();

    void setBusinessStyleSheet();

    void setContactsStyleSheet();

    void setNotesStyleSheet();

};

#endif // TABLE_H

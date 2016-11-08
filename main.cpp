#include "mainwindow.h"
#include <QApplication>
#include <QDebug>
#include <QString>
#include <QStringList>
#include "topic.h"
#include "businesstopic.h"
#include "contactstopic.h"
#include "notestopic.h"

namespace app {

}

using namespace app;

int main(int argc, char *argv[])
{
    /*
    BusinessTopic* businessTopic = new BusinessTopic("business", 0, 5, QStringList() << "bID"
                                                     << "Head" << "Deadline" << "Description" << "Priority");
    ContactsTopic* contactsTopic = new ContactsTopic("contacts", 0, 4, QStringList() << "cID"
                                                    << "Full name" << "Phone numbers" << "Email");
    NotesTopic* notesTopic = new NotesTopic("notes", 0, 3, QStringList() << "nID"
                                            << "Head" << "Description");
*/
    QApplication a(argc, argv);

    MainWindow w;
    w.show();

    return a.exec();
}

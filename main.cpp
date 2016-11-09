#include "mainwindow.h"
#include <QApplication>
#include <QDebug>
#include <QString>
#include <QStringList>
#include "topic.h"
#include "businesstopic.h"
#include "contactstopic.h"
#include "notestopic.h"
#include "applicationcontext.h"
#include "databasedriver.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    w.show();

    return a.exec();
}

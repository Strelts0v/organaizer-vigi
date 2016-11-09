#ifndef APPLICATIONCONTEXT_H
#define APPLICATIONCONTEXT_H

#include "table.h"
#include "businesstopic.h"
#include "contactstopic.h"
#include "notestopic.h"

namespace app {
class ApplicationContext;
}

class ApplicationContext
{
private:

    BusinessTopic* businessTopic;

    ContactsTopic* contactsTopic;

    NotesTopic* notesTopic;

public:

    ApplicationContext();

    BusinessTopic* getBusinessTopic();

    void setBusinessTopic(BusinessTopic* businessTopic);

    ContactsTopic* getContactsTopic();

    void setContactsTopic(ContactsTopic* contactsTopic);

    NotesTopic* getNotesTopic();

    void setNotesTopic(NotesTopic* notesTopic);

};

#endif // APPLICATIONCONTEXT_H

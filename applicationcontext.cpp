#include "applicationcontext.h"

ApplicationContext::ApplicationContext()
{    
    businessTopic = new BusinessTopic("business", 0, 5, QStringList() << "Head"
                                                     << "Deadline" << "Description" << "Priority" << "bID");
    contactsTopic = new ContactsTopic("contacts", 0, 4, QStringList() << "Full name"
                                                    << "Phone numbers" << "Email" << "cID");
    notesTopic = new NotesTopic("notes", 0, 3, QStringList() << "Head"
                                            << "Description" << "nID");
}

BusinessTopic* ApplicationContext::getBusinessTopic()
{
    return businessTopic;
}

void ApplicationContext::setBusinessTopic(BusinessTopic* businessTopic)
{
    this->businessTopic = businessTopic;
}

ContactsTopic* ApplicationContext::getContactsTopic()
{
    return contactsTopic;
}

void ApplicationContext::setContactsTopic(ContactsTopic* contactsTopic)
{
    this->contactsTopic = contactsTopic;
}

NotesTopic* ApplicationContext::getNotesTopic()
{
    return notesTopic;
}

void ApplicationContext::setNotesTopic(NotesTopic* notesTopic)
{
    this->notesTopic = notesTopic;
}

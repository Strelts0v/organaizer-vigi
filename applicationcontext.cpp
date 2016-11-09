#include "applicationcontext.h"

ApplicationContext::ApplicationContext()
{
    businessTopic = new BusinessTopic("business", 0, 5, QStringList() << "bID"
                                                     << "Head" << "Deadline" << "Description" << "Priority");
    contactsTopic = new ContactsTopic("contacts", 0, 4, QStringList() << "cID"
                                                    << "Full name" << "Phone numbers" << "Email");
    notesTopic = new NotesTopic("notes", 0, 3, QStringList() << "nID"
                                            << "Head" << "Description");
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
    this->notesTopic;
}

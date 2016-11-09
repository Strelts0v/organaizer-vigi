#include "blankforcontactsitem.h"
#include <QHBoxLayout>
#include <QVBoxLayout>

BlankForContactsItem::BlankForContactsItem(QWidget *parent) : QDialog(parent)
{
    headerLabel = new QLabel("Input data for new contact");

    fullNameLabel = new QLabel("full name: ");
    fullNameEdit = new QLineEdit();

    phoneNumbersLabel = new QLabel("phone numbers: ");
    phoneNumbersEdit = new QLineEdit();

    emailLabel = new QLabel("email: ");
    emailEdit = new QLineEdit();

    okButton = new QPushButton("OK");
    cancelButton = new QPushButton("Cancel");

    QHBoxLayout* headerLayot = new QHBoxLayout();
    headerLayot->addWidget(headerLabel);

    QHBoxLayout* fullNameLayot = new QHBoxLayout();
    fullNameLayot->addWidget(fullNameLabel);
    fullNameLayot->addWidget(fullNameEdit);

    QHBoxLayout* phoneNumbersLayot = new QHBoxLayout();
    phoneNumbersLayot->addWidget(phoneNumbersLabel);
    phoneNumbersLayot->addWidget(phoneNumbersEdit);

    QHBoxLayout* emailLayot = new QHBoxLayout();
    emailLayot->addWidget(emailLabel);
    emailLayot->addWidget(emailEdit);

    QHBoxLayout* buttonLayot = new QHBoxLayout();
    buttonLayot->addWidget(okButton);
    buttonLayot->addWidget(cancelButton);

    QVBoxLayout* mainLayot = new QVBoxLayout(this);
    mainLayot->addLayout(headerLayot);
    mainLayot->addLayout(fullNameLayot);
    mainLayot->addLayout(phoneNumbersLayot);
    mainLayot->addLayout(emailLayot);
    mainLayot->addLayout(buttonLayot);

    setLayout(mainLayot);
    setWindowTitle("ViGi");

    connect(okButton, SIGNAL(clicked()), this, SLOT(okClickedSlot()));
    connect(cancelButton, SIGNAL(clicked()), this, SLOT(close()));
}

void BlankForContactsItem::okClickedSlot()
{
    QStringList dataList;
    dataList.push_back(fullNameEdit->text());
    dataList.push_back(phoneNumbersEdit->text());
    dataList.push_back(emailEdit->text());
    emit sendDataforNewContact(dataList);
    this->close();
}

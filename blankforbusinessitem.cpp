#include "blankforbusinessitem.h"

#include <QHBoxLayout>
#include <QVBoxLayout>


BlankForBusinessItem::BlankForBusinessItem(QWidget *parent) : QDialog(parent)
{
    headerLabel = new QLabel("Input data for new business");

    headLabel = new QLabel("head: ");
    headEdit = new QLineEdit();
    //headLabel->setBuddy(headLabel);

    deadlineLabel = new QLabel("deadline: ");
    deadlineEdit = new QDateEdit();

    descriptionLabel = new QLabel("description: ");
    descriptionEdit = new QTextEdit();

    priorityLabel = new QLabel("priority: ");
    QRadioButton *lowPriority = new QRadioButton("low");
    QRadioButton *mediumPriority = new QRadioButton("medium");
    QRadioButton *highPriority = new QRadioButton("high");
    priority = new QButtonGroup(this);
    priority->addButton(lowPriority, 3);
    priority->addButton(mediumPriority, 2);
    priority->addButton(highPriority, 1);

    okButton = new QPushButton("OK");
    cancelButton = new QPushButton("Cancel");

    QHBoxLayout* headerLayot = new QHBoxLayout();
    headerLayot->addWidget(headerLabel);

    QHBoxLayout* headLayot = new QHBoxLayout();
    headLayot->addWidget(headLabel);
    headLayot->addWidget(headEdit);

    QHBoxLayout* deadlineLayot = new QHBoxLayout();
    deadlineLayot->addWidget(deadlineLabel);
    deadlineLayot->addWidget(deadlineEdit);

    QHBoxLayout* descriptionLayot = new QHBoxLayout();
    descriptionLayot->addWidget(descriptionLabel);
    descriptionLayot->addWidget(descriptionEdit);

    QHBoxLayout* priorityLayot = new QHBoxLayout();
    priorityLayot->addWidget(priorityLabel);
    priorityLayot->addWidget(lowPriority);
    priorityLayot->addWidget(mediumPriority);
    priorityLayot->addWidget(highPriority);

    QHBoxLayout* buttonLayot = new QHBoxLayout();
    buttonLayot->addWidget(okButton);
    buttonLayot->addWidget(cancelButton);

    QVBoxLayout* mainLayot = new QVBoxLayout(this);
    mainLayot->addLayout(headerLayot);
    mainLayot->addLayout(headLayot);
    mainLayot->addLayout(deadlineLayot);
    mainLayot->addLayout(descriptionLayot);
    mainLayot->addLayout(priorityLayot);
    mainLayot->addLayout(buttonLayot);

    setLayout(mainLayot);
    setWindowTitle("ViGi");

    connect(okButton, SIGNAL(clicked()), this, SLOT(okClickedSlot()));
    connect(cancelButton, SIGNAL(clicked()), this, SLOT(close()));
}

void BlankForBusinessItem::okClickedSlot()
{
    QStringList dataList;
    dataList.push_back(headEdit->text());
    dataList.push_back(deadlineEdit->text());
    dataList.push_back(descriptionEdit->toPlainText());
    dataList.push_back(QString::number(priority->checkedId()));
    emit sendDataforNewBusiness(dataList);
    this->close();
}




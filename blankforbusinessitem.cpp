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
    descriptionEdit->resize(QSize(100, 30));

    priorityLabel = new QLabel("priority: ");
    lowPriority = new QRadioButton("low");
    mediumPriority = new QRadioButton("medium");
    highPriority = new QRadioButton("high");

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

    connect(okButton, SIGNAL(clicked()), this, SLOT(accept()));
    connect(cancelButton, SIGNAL(clicked()), this, SLOT(close()));
}




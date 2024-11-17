#include "about_dialog.h"
#include "ui_about_dialog.h"

#include <QVBoxLayout>
#include <QPixmap>
#include <QLabel>

About_Dialog::About_Dialog(QWidget *parent)
    : QDialog(parent),
      ui(new Ui::About_Dialog)
{
    ui->setupUi(this);
    setFixedSize(350, 530);
    setWindowTitle("ReadyMario™ - About");

    logo = new QPixmap(":/images/AD_Mario_Logo_Bar.png");
    logoLbl = new QLabel;
    logoLbl->setPixmap(*logo);
    logoLbl->setContentsMargins(0, 0, 0, 2);

    schoolInfo = new QLabel;
    schoolInfo->setAlignment(Qt::AlignCenter);
    schoolInfo->setText("© 2024 | ReadyMario™ | Super Mario Bros Game");
    schoolInfo->setTextFormat(Qt::RichText);
    schoolInfo->setTextInteractionFlags(Qt::TextBrowserInteraction);
    schoolInfo->setOpenExternalLinks(true);
    schoolInfo->setContentsMargins(0, 0, 14, 0);

    classInfo = new QLabel;
    classInfo->setAlignment(Qt::AlignCenter);
    classInfo->setText("Produce by <a href=\"https://readydev.ovh/home\">ReadyDev™ Group</a>");
    classInfo->setTextFormat(Qt::RichText);
    classInfo->setTextInteractionFlags(Qt::TextBrowserInteraction);
    classInfo->setOpenExternalLinks(true);

    groupMember1 = new QLabel;
    groupMember1->setAlignment(Qt::AlignCenter);
    groupMember1->setText("Gerard KESSE : <a href = \"https://www.linkedin.com/in/tia-gerard-kesse/\">LinkedIn</a> ");
    groupMember1->setTextFormat(Qt::RichText);
    groupMember1->setTextInteractionFlags(Qt::TextBrowserInteraction);
    groupMember1->setOpenExternalLinks(true);
    groupMember1->setContentsMargins(14, 0, 0, 0);

    mainVBox = new QVBoxLayout;
    mainVBox->setAlignment(Qt::AlignTop | Qt::AlignCenter);
    mainVBox->addWidget(logoLbl);
    mainVBox->addWidget(schoolInfo);
    mainVBox->addWidget(classInfo);
    mainVBox->addWidget(groupMember1);
    setLayout(mainVBox);
}

About_Dialog::~About_Dialog()
{
    delete ui;
}

#include "mywidget.h"
#include "adddialog.h"

void MainWidget::showDialog(){
    AddDialog addDialog(this);
    addDialog.exec();
}

MainWidget::MainWidget(){
    //----------------[UpperBanner]
    nickName = new QLabel(tr("User"));
    proPic = new QLabel(tr("proPic"));
    totalTime = new QLabel(tr("totalTime"));

    internalUpperHorizontalLayout = new QHBoxLayout;
    internalUpperHorizontalLayout->addWidget(nickName);
    internalUpperHorizontalLayout->addWidget(proPic);
    internalUpperHorizontalLayout->addWidget(totalTime);
    //----------------[]

    //----------------[LowerButtons]
    showAddDialog = new QPushButton(tr("Show dialog"));
    exitBtn = new QPushButton(tr("Exit"));

    internalLowerHorizontalLayout = new QHBoxLayout;
    internalLowerHorizontalLayout->addWidget(showAddDialog);
    internalLowerHorizontalLayout->addWidget(exitBtn);

    connect(showAddDialog, SIGNAL(clicked()), this, SLOT(showDialog()));
    //connect(exitBtn, SIGNAL(clicked()), this, SLOT(close()));
    //connect(exitBtn, SIGNAL(clicked()), this, SLOT());
    //----------------[]

    mainLayout = new QVBoxLayout;
    mainLayout->addLayout(internalUpperHorizontalLayout);
    mainLayout->addLayout(internalLowerHorizontalLayout);
    setLayout(mainLayout);
}

QPushButton * MainWidget::getExitBtn(){
    return exitBtn;
}


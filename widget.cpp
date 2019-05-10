#include "widget.h"
#include "adddialog.h"

Widget::Widget(QWidget *parent): QWidget(parent){
    setWindowTitle(tr("Finestra principale"));
    showAddDialog = new QPushButton(tr("Show dialog"));
    exit = new QPushButton(tr("Exit"));

    nickName = new QLabel(tr("User"));
    proPic = new QLabel(tr("proPic"));
    totalTime = new QLabel(tr("totalTime"));

    verticalLayout = new QVBoxLayout;

    internalUpperHorizontalLayout = new QHBoxLayout;
    internalLowerHorizontalLayout = new QHBoxLayout;

    internalUpperHorizontalLayout->addWidget(nickName);
    internalUpperHorizontalLayout->addWidget(proPic);
    internalUpperHorizontalLayout->addWidget(totalTime);

    internalLowerHorizontalLayout->addWidget(showAddDialog);
    internalLowerHorizontalLayout->addWidget(exit);

    verticalLayout->addLayout(internalUpperHorizontalLayout);
    verticalLayout->addLayout(internalLowerHorizontalLayout);

    setLayout(verticalLayout);

    connect(showAddDialog, SIGNAL(clicked()), this, SLOT(showDialog()));
    connect(exit, SIGNAL(clicked()), this, SLOT(close()));
}

void Widget::showDialog(){
    AddDialog addDialog(this);
    addDialog.exec();
}

QSize Widget::sizeHint() const{
    return QSize(200,200);
}

Widget::~Widget(){}

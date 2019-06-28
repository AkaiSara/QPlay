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

    //----------------[SearchBar]
    searchbar = new QLineEdit();
    searchbar->setPlaceholderText("Ricerca");

    QComboBox* searchAttribute = new QComboBox();
    searchAttribute->addItem(QString("Title"));
    searchAttribute->addItem(QString("Release year"));

    QPushButton* clearSearchButton = new QPushButton(tr("Cancel"));
    clearSearchButton->setToolTip(tr("Delete filters"));

    QHBoxLayout* searchLayout = new QHBoxLayout();
    searchLayout->addWidget(searchbar);
    searchLayout->addWidget(searchAttribute);
    searchLayout->addWidget(clearSearchButton);

    //connect(searchbar, SIGNAL(textChanged(const QString&)), this, SLOT(textFilterChanged()));
    //connect(searchAttribute, SIGNAL(currentTextChanged(const QString&)), this, SLOT(textFilterChanged()));
    connect(clearSearchButton, SIGNAL(clicked()), searchbar, SLOT(clear()));
    //----------------[]

    //----------------[Central]
    listWidget = new QListWidget;
    listWidget->setSelectionMode(QAbstractItemView::SingleSelection);
    listWidget->setFlow(QListView::LeftToRight);

    /*for(int i=1; i<10; i++){
        QListWidgetItem * newItem = new QListWidgetItem;
        newItem->setText(QString("ciao").append(QString::number(i)));
        listWidget->insertItem(i, newItem);
    }*/

    //----------------[]

    //----------------[LowerButtons]
    showAddDialog = new QPushButton(tr("Add an item"));
    showAddDialog->setToolTip(tr("Open an add dialog"));
    exitBtn = new QPushButton(tr("Exit"));

    internalLowerHorizontalLayout = new QHBoxLayout;
    internalLowerHorizontalLayout->addWidget(showAddDialog);
    internalLowerHorizontalLayout->addWidget(exitBtn);

    connect(showAddDialog, SIGNAL(clicked()), this, SLOT(showDialog()));
    //----------------[]

    mainLayout = new QVBoxLayout;
    mainLayout->addLayout(internalUpperHorizontalLayout);
    mainLayout->addLayout(searchLayout);
    mainLayout->addWidget(listWidget);
    mainLayout->addLayout(internalLowerHorizontalLayout);
    setLayout(mainLayout);
}

QPushButton * MainWidget::getExitBtn(){
    return exitBtn;
}


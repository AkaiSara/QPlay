#include "mywidget.h"
#include <QMessageBox>

void MainWidget::showDialog(){
    AddDialog addDialog(this);
    addDialog.exec();
}

void MainWidget::update(Container<DeepPtr<AudioVisual>> list){
    listWidget.clear();

    while(listBoxLayout->count() != 0){ //cancello cosa c'è attualmente nel layout
        auto item = listBoxLayout->takeAt(0);
        delete item->widget();
        delete item;
    }

    for(auto it = list.begin(); it != list.end(); ++it){ //riempio il layout vuoto
        AudioVisualItem * item = new AudioVisualItem(*it, this);
        listBoxLayout->addWidget(item);
        connect(item, SIGNAL(deleteItem(DeepPtr<AudioVisual>)), this, SIGNAL(removeItem(DeepPtr<AudioVisual>)));
        //connect(item, &AudioVisualItem::deleteItem, this, [this](DeepPtr<AudioVisual> a) {emit removeItem(a);});
        //connect edit
        listWidget.push_back(item);

        QFrame *line = new QFrame(); //riga di separazione tra gli elementi
        line->setFrameShape(QFrame::VLine);
        line->setFrameShadow(QFrame::Sunken);
        listBoxLayout->addWidget(line);

        listBoxLayout->addStretch(1);
    }
    if(list.isEmpty()){
        QMessageBox msgBox;
        msgBox.setText("vuota");
        msgBox.exec();
    }

}


MainWidget::MainWidget(QWidget * p) : parent(p){

    //----------------[UserProfile]
    nickName = new QLabel(tr("User"));
    proPic = new QLabel(tr("proPic"));
    totalTime = new QLabel(tr("totalTime"));

    QHBoxLayout *userLayout;
    userLayout = new QHBoxLayout;
    userLayout->addWidget(nickName);
    userLayout->addWidget(proPic);
    userLayout->addWidget(totalTime);
    //----------------[]

    //----------------[SearchBar]
    searchbar = new QLineEdit();
    searchbar->setPlaceholderText("Ricerca");

    QComboBox* searchAttribute = new QComboBox();
    searchAttribute->addItem(QString("Title"));
    searchAttribute->addItem(QString("Type"));
    searchAttribute->addItem(QString("Favorite"));
    searchAttribute->addItem(QString("Release year"));

    QPushButton* clearSearchButton = new QPushButton(tr("Cancel"));
    clearSearchButton->setToolTip(tr("Delete filters"));

    QHBoxLayout* searchLayout = new QHBoxLayout();
    searchLayout->addWidget(searchbar);
    searchLayout->addWidget(searchAttribute);
    searchLayout->addWidget(clearSearchButton);
    //----------------[]

    //----------------[CentralList]
    scrollArea = new QScrollArea();
    QWidget * auxWidget = new QWidget();
    listBoxLayout = new QHBoxLayout;

    scrollArea->setWidgetResizable(true);
    auxWidget->setLayout(listBoxLayout);
    scrollArea->setWidget(auxWidget);

    //----------------[]

    //----------------[ButtonsControl]
    showAddDialog = new QPushButton(tr("Add an item"));
    showAddDialog->setToolTip(tr("Open an add dialog and add a new item"));
    clearListBtn = new QPushButton(tr("Clear"));
    clearListBtn->setToolTip(tr("Delete all item"));
    exitBtn = new QPushButton(tr("Exit"));

    QHBoxLayout *BtnLayout;
    BtnLayout = new QHBoxLayout;
    BtnLayout->addWidget(showAddDialog);
    BtnLayout->addWidget(clearListBtn);
    BtnLayout->addWidget(exitBtn);

    //----------------[]


    //----------------[MainLayout]
    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->addLayout(userLayout);
    mainLayout->addLayout(searchLayout);
    mainLayout->addWidget(scrollArea);
    mainLayout->addLayout(BtnLayout);
    setLayout(mainLayout);

    //----------------[]

    //----------------[Connect]
    //connect(searchbar, SIGNAL(textChanged(const QString&)), this, SLOT(textFilterChanged()));
    //connect(searchAttribute, SIGNAL(currentTextChanged(const QString&)), this, SLOT(textFilterChanged()));
    connect(clearSearchButton, SIGNAL(clicked()), searchbar, SLOT(clear()));

    connect(showAddDialog, SIGNAL(clicked()), this, SLOT(showDialog()));
    connect(clearListBtn, SIGNAL(clicked()), parent, SLOT(clearList()));
    connect(exitBtn, SIGNAL(clicked()), parent, SLOT(close()));

    connect(this, SIGNAL(itemFromDialog(AudioVisual *)), parent, SLOT(addItem(AudioVisual *)));

    connect(this, SIGNAL(removeItem(DeepPtr<AudioVisual>)), parent, SLOT(deleteItem(DeepPtr<AudioVisual>)));

    connect(parent, SIGNAL(listChanged(Container<DeepPtr<AudioVisual>>)), this, SLOT(update(Container<DeepPtr<AudioVisual>>)));
    //----------------[]
}



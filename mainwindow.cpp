#include "mainwindow.h"

void MainWindow::showSearchDetail(const QString & attr){
    if(attr == "Favorite"){
        searchCheckBox->show();
        searchCheckBox->setDown(false);
        searchbar->hide();
    }
    else{
        searchCheckBox->hide();
        searchbar->show();
    }
}

void MainWindow::clearList(){
    model->clearAll();
    emit listChanged();
}

void MainWindow::addItem(AudioVisual * i){
    model->add(*i);
    emit listChanged();
}

void MainWindow::deleteItem(DeepPtr<AudioVisual> a){
    model->remove(a);
    emit listChanged();
}

void MainWindow::editItem(DeepPtr<AudioVisual> a){
    editWidget = new EditWidget(a, this);
    editWidget->exec();
    addItem(&(*a));
    emit listChanged();
}


void MainWindow::openAddDialog(){
    AddDialog addDialog(this);
    addDialog.exec();
}


void MainWindow::update(){
    listWidget.clear();

    while(listBoxLayout->count() != 0){ //cancello cosa c'è attualmente nel layout
        auto item = listBoxLayout->takeAt(0);
        delete item->widget();
        delete item;
    }

    auto list = model->getList();
    for(auto it = list.begin(); it != list.end(); ++it){ //riempio il layout vuoto
        QFrame *line = new QFrame(); //riga di separazione tra gli elementi
        line->setFrameShape(QFrame::VLine);
        line->setFrameShadow(QFrame::Sunken);

        AudioVisualItem * item = new AudioVisualItem(*it, this, line);
        listBoxLayout->addWidget(item);
        connect(item, SIGNAL(deleteAnItem(DeepPtr<AudioVisual>)), this, SLOT(deleteItem(DeepPtr<AudioVisual>)));
        connect(item, SIGNAL(editAnItem(DeepPtr<AudioVisual>)), this, SLOT(editItem(DeepPtr<AudioVisual>)));
        listWidget.push_back(item);

        listBoxLayout->addWidget(line);
        if(*it == list.back()) //se il nodo corrente non è l'ultimo
            item->setLine(false);

        listBoxLayout->addStretch(1);
    }
     //questo messaggio verrà cancellato prima dell ultimo commit, mi serviva per debuggare
        QMessageBox msgBox;
        msgBox.setText("fatto update");
        msgBox.exec();
}

void MainWindow::search(){
    listSearchResult.clear();
    QString attributo = searchAttribute->currentText();

    bool check = false;
    QString valore;
    if(attributo == "Favorite")
        check = searchCheckBox->isChecked();
    else
        valore = searchbar->text();

    for(auto it = listWidget.begin(); it != listWidget.end(); ++it){
        if(attributo == "Title"){
            if(QString::compare(QString::fromStdString( (*it)->getAvPtr()->getTitle()), valore, Qt::CaseInsensitive) == 0){
                listSearchResult.push_back(*it);
            }
            else{
                (*it)->hide();
                (*it)->setLine(false);
            }
        }

        if(attributo == "Release year"){
            if(QString::number((*it)->getAvPtr()->getRelease_date()) == valore){
                listSearchResult.push_back(*it);
            }
            else{
                (*it)->hide();
                (*it)->setLine(false);
            }
        }

        if(attributo == "Favorite"){
            if( (check && (*it)->getAvPtr()->isFavorite()) || (!check && (!(*it)->getAvPtr()->isFavorite()))){
                listSearchResult.push_back(*it);
            }
            else{
                (*it)->hide();
                (*it)->setLine(false);
            }
        }
    }

    while(listBoxLayout->count() != 0){ //cancello cosa c'è attualmente nel layout
        auto item = listBoxLayout->takeAt(0);
        delete item;
    }

    for(auto it = listSearchResult.begin(); it != listSearchResult.end(); ++it){
        listBoxLayout->addWidget(*it);
        listBoxLayout->addWidget((*it)->getLine());
        if(*it == listSearchResult.back()) //se il nodo corrente non è l'ultimo
            (*it)->setLine(false);
        listBoxLayout->addStretch(1);
    }
}

MainWindow::MainWindow(): model(new Model()){
    setMaximumSize(QSize(600,600));

    setWindowTitle(tr("WikiPlay")); //lui cambia le cose, io le sistemo
    //setWindowIcon(QIcon(":/icon.svg"));

    //----------------[Menu]
    fileMenu = menuBar()->addMenu(tr("&File"));

    openAct = new QAction(tr("&Open"), this);
    fileMenu->addAction(openAct);

    saveAct = new QAction(tr("&Save"), this);
    fileMenu->addAction(saveAct);

    fileMenu->addSeparator();

    exitAct = new QAction(tr("E&xit"), this);
    fileMenu->addAction(exitAct);

    //----------------[]

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
    searchAttribute = new QComboBox();
    searchAttribute->addItem(QString("Title"));
    searchAttribute->addItem(QString("Type"));
    searchAttribute->addItem(QString("Favorite"));
    searchAttribute->addItem(QString("Release year"));

    searchbar = new QLineEdit();
    searchbar->setPlaceholderText("Search");

    searchCheckBox = new QCheckBox("Favorite"); //l'etichetta deve essere la stessa del combobox (sfrutto currentTextChanged(const QString&))

    QPushButton* searchButton = new QPushButton(tr("cerca"));
    QPushButton* clearSearchButton = new QPushButton(tr("Cancel"));
    clearSearchButton->setToolTip(tr("Delete filters"));

    QHBoxLayout* searchLayout = new QHBoxLayout();
    searchLayout->addWidget(searchbar);
    searchLayout->addWidget(searchCheckBox);
    searchLayout->addWidget(searchAttribute);
    searchLayout->addWidget(searchButton);
    searchLayout->addWidget(clearSearchButton);

    showSearchDetail(searchAttribute->currentText());
    //----------------[]

    //----------------[CentralList]
    scrollArea = new QScrollArea();
    QWidget * auxWidget = new QWidget();
    listBoxLayout = new QHBoxLayout;

    auxWidget->setLayout(listBoxLayout);
    scrollArea->setWidgetResizable(true);
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
    mainWidget = new QWidget();
    mainWidget->setLayout(mainLayout);
    setCentralWidget(mainWidget);

    //----------------[]

    //----------------[Connect]
    connect(openAct, SIGNAL(triggered()), this, SLOT(openFile()));
    connect(saveAct, SIGNAL(triggered()), this, SLOT(saveFile()));
    connect(exitAct, SIGNAL(triggered()), this, SLOT(close()));

    //connect(searchbar, SIGNAL(textChanged(const QString&)), this, SLOT(textFilterChanged()));
    connect(searchAttribute, SIGNAL(currentTextChanged(const QString&)), this, SLOT(showSearchDetail(const QString&)));
    connect(searchAttribute, SIGNAL(currentTextChanged(const QString&)), this, SLOT(update()));
    connect(clearSearchButton, SIGNAL(clicked()), searchbar, SLOT(clear()));
    connect(clearSearchButton, SIGNAL(clicked()), this, SLOT(update()));
    connect(searchButton, SIGNAL(clicked()), this, SLOT(search()));

    connect(showAddDialog, SIGNAL(clicked()), this, SLOT(openAddDialog()));
    connect(clearListBtn, SIGNAL(clicked()), this, SLOT(clearList()));
    connect(exitBtn, SIGNAL(clicked()), this, SLOT(close()));

    connect(this, SIGNAL(listChanged()), this, SLOT(update()));
    //----------------[]
}

void MainWindow::openFile(){
    QFileDialog choose;

    choose.setFileMode(QFileDialog::ExistingFile);
    choose.setWindowTitle("Load Lineup");
    choose.setNameFilter("XML file (*.xml)");

    if (choose.exec())
        model->load(choose.selectedFiles()[0].toStdString());

    emit listChanged();
}
void MainWindow::saveFile(){
    QFileDialog choose;

    choose.setFileMode(QFileDialog::AnyFile);
    choose.setWindowTitle("Save Lineup");
    choose.setNameFilter("XML file (*.xml)");

    if (choose.exec())
        model->save(choose.selectedFiles()[0].toStdString());
}

QSize MainWindow::sizeHint() const{
    return QSize(450,350);
}

MainWindow::~MainWindow(){}

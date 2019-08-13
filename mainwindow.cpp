#include "mainwindow.h"

void MainWindow::showSearchDetail(const QString & attr){
    searchBar->hide();
    searchCheckBox->hide();
    searchDoc->hide();
    searchMov->hide();
    searchTvs->hide();
    searchComboBox->hide();
    searchComboBox->clear();

    if(attr == "Favorite"){
        searchCheckBox->show();
        searchCheckBox->setText(searchAttribute->currentText());
        searchCheckBox->setDown(false);
    }
    if(attr == "Title" || attr == "Director"){
        searchBar->show();
    }
    if(attr == "Release year" || attr == "Running time"){
        QIntValidator * positVal = new QIntValidator();
        positVal->setBottom(0);
        searchBar->setValidator(positVal);
        searchBar->show();
    }

    if(attr == "Type"){
        searchDoc->show();
        searchMov->show();
        searchTvs->show();
    }

    if(attr == "Genre"){
        foreach (std::string str, AudioVisual::Genre) {
            searchComboBox->addItem(QString::fromStdString(str));
        }
        searchComboBox->show();
    }

    if(attr == "Rating"){
        foreach (std::string str, AudioVisual::Rating) {
            searchComboBox->addItem(QString::fromStdString(str));
        }
        searchComboBox->show();
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

    model->edit(a,editWidget->getEdited());

    emit listChanged();
}


void MainWindow::openAddDialog(){
    AddDialog addDialog(this);
    addDialog.exec();
}


void MainWindow::update(){
    listWidget.clear();
    int time = 0;

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

        time += (*it)->getTotalRunningTime();
    }

    int min = time % 60, hour = ((time / 60) % 24), day = time / (60 * 24);
    totalTime->setText("Total time: " + (day != 0? QString::number(day) + "d " : "") + (hour != 0? QString::number(hour) + "h " : "") + QString::number(min) + "min");
     //questo messaggio verrà cancellato prima dell ultimo commit, mi serviva per debuggare
        //QMessageBox msgBox;
        //msgBox.setText("fatto update");
        //msgBox.exec();
}

void MainWindow::search(){
    listSearchResult.clear();

    QString attributo = searchAttribute->currentText();
    QString valore;

    if(attributo == "Favorite"){
        bool check = searchCheckBox->isChecked();
        for(auto it = listWidget.begin(); it != listWidget.end(); ++it){
            if( (check && (*it)->getAvPtr()->isFavorite()) || (!check && (!(*it)->getAvPtr()->isFavorite()))){
                listSearchResult.push_back(*it);
            }
            else{
                (*it)->hide();
                (*it)->setLine(false);
            }
        }
    }


    if(attributo == "Title" || attributo == "Release year" || attributo == "Director" || attributo == "Running time"){
        valore = searchBar->text();

        if(attributo == "Title"){
            for(auto it = listWidget.begin(); it != listWidget.end(); ++it){
                if(QString::compare(QString::fromStdString( (*it)->getAvPtr()->getTitle()), valore, Qt::CaseInsensitive) == 0){
                    listSearchResult.push_back(*it);
                }
                else{
                    (*it)->hide();
                    (*it)->setLine(false);
                }
            }
        }

        if(attributo == "Release year"){
            for(auto it = listWidget.begin(); it != listWidget.end(); ++it){
                if(QString::number((*it)->getAvPtr()->getRelease_date()) == valore){
                    listSearchResult.push_back(*it);
                }
                else{
                    (*it)->hide();
                    (*it)->setLine(false);
                }
            }
        }

        if(attributo == "Director"){
            for(auto it = listWidget.begin(); it != listWidget.end(); ++it){
                if(QString::compare(QString::fromStdString( (*it)->getAvPtr()->getDirector()), valore, Qt::CaseInsensitive) == 0){
                    listSearchResult.push_back(*it);
                }
                else{
                    (*it)->hide();
                    (*it)->setLine(false);
                }
            }
        }

        if(attributo == "Running time"){
            for(auto it = listWidget.begin(); it != listWidget.end(); ++it){
                if(QString::number((*it)->getAvPtr()->getRunning_time()) == valore){
                    listSearchResult.push_back(*it);
                }
                else{
                    (*it)->hide();
                    (*it)->setLine(false);
                }
            }
        }
    }


    if(attributo == "Type"){ //in base a quale bottone è down poi farò un dynamic
        if(searchDoc->isChecked()){
            for(auto it = listWidget.begin(); it != listWidget.end(); ++it){
                if(dynamic_cast<Documentary *>((*it)->getAvPtr())){
                    listSearchResult.push_back(*it);
                }
                else{
                    (*it)->hide();
                    (*it)->setLine(false);
                }
            }
        }

        if(searchMov->isChecked()){
            for(auto it = listWidget.begin(); it != listWidget.end(); ++it){
                if(dynamic_cast<Movie *>((*it)->getAvPtr())){
                    listSearchResult.push_back(*it);
                }
                else{
                    (*it)->hide();
                    (*it)->setLine(false);
                }
            }
        }

        if(searchTvs->isChecked()){
            for(auto it = listWidget.begin(); it != listWidget.end(); ++it){
                if(dynamic_cast<TvSerie *>((*it)->getAvPtr())){
                    listSearchResult.push_back(*it);
                }
                else{
                    (*it)->hide();
                    (*it)->setLine(false);
                }
            }
        }
    }


    if(attributo == "Genre" || attributo == "Rating"){
        valore = searchComboBox->currentText();

        if(attributo == "Genre"){
            for(auto it = listWidget.begin(); it != listWidget.end(); ++it){
                Movie * p = dynamic_cast<Movie *>((*it)->getAvPtr());
                TvSerie * q = dynamic_cast<TvSerie *>((*it)->getAvPtr());
                if(p != nullptr){
                    if(QString::fromStdString(p->getGenre()) == valore){
                        listSearchResult.push_back(*it);
                    }
                    else{
                        (*it)->hide();
                        (*it)->setLine(false);
                    }
                }
                if(q != nullptr){
                    if(QString::fromStdString(q->getGenre()) == valore){
                        listSearchResult.push_back(*it);
                    }
                    else{
                        (*it)->hide();
                        (*it)->setLine(false);
                    }
                }
            }
        }

        if(attributo == "Rating"){
            for(auto it = listWidget.begin(); it != listWidget.end(); ++it){
                Movie * p = dynamic_cast<Movie *>((*it)->getAvPtr());
                TvSerie * q = dynamic_cast<TvSerie *>((*it)->getAvPtr());
                if(p != nullptr){
                    if(QString::fromStdString(p->getRating()) == valore){
                        listSearchResult.push_back(*it);
                    }
                    else{
                        (*it)->hide();
                        (*it)->setLine(false);
                    }
                }
                if(q != nullptr){
                    if(QString::fromStdString(q->getRating()) == valore){
                        listSearchResult.push_back(*it);
                    }
                    else{
                        (*it)->hide();
                        (*it)->setLine(false);
                    }
                }
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
        listBoxLayout->addStretch(1); //se lo metto fuori dal for??
    }
}

MainWindow::MainWindow(): model(new Model){
    setWindowTitle(tr("WikiPlay")); //lui cambia le cose, io le sistemo
    setWindowIcon(QIcon(":/img/app"));

    setMaximumSize(QSize(600,600));

    //----------------[Menu]
    QAction * openAct = new QAction(QIcon(":/img/load"), tr("&Open"), this);
    QAction * saveAct = new QAction(QIcon(":/img/save"), tr("&Save"), this);
    QAction * exitAct = new QAction(QIcon(":/img/exit"), tr("E&xit"), this);

    fileMenu = menuBar()->addMenu(tr("&File"));

    fileMenu->addAction(openAct);
    fileMenu->addAction(saveAct);
    fileMenu->addSeparator();
    fileMenu->addAction(exitAct);

    //----------------[]

    //----------------[UserProfile]
    QLabel * nickName = new QLabel(tr("User"));
    nickName->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
    QLabel * proPic = new QLabel;
    proPic->setPixmap(QPixmap(":/img/propic").scaled(200, 100, Qt::KeepAspectRatio));
    proPic->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
    proPic->setMaximumWidth(200);

    totalTime = new QLabel(tr("Total time: 0min"));
    totalTime->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);

    QHBoxLayout * userLayout;
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
    searchAttribute->addItem(QString("Running time"));
    searchAttribute->addItem(QString("Director"));
    searchAttribute->addItem(QString("Genre"));
    searchAttribute->addItem(QString("Rating"));

    searchBar = new QLineEdit();
    searchBar->setPlaceholderText("Search");

    searchCheckBox = new QCheckBox();

    searchDoc = new QRadioButton("Documentary");
    searchMov = new QRadioButton("Movie");
    searchTvs = new QRadioButton("SerieTv");
    typeSearchGroup = new QHBoxLayout;
    typeSearchGroup->addWidget(searchDoc);
    typeSearchGroup->addWidget(searchMov);
    typeSearchGroup->addWidget(searchTvs);

    searchComboBox = new QComboBox();

    QPushButton* searchButton = new QPushButton(QIcon(":/img/search"), tr("Cerca"));
    QPushButton* clearSearchButton = new QPushButton(tr("Cancel"));
    clearSearchButton->setToolTip(tr("Delete filters"));

    QHBoxLayout* searchLayout = new QHBoxLayout();
    searchLayout->addWidget(searchAttribute);
    searchLayout->addWidget(searchBar);
    searchLayout->addWidget(searchCheckBox);
    searchLayout->addLayout(typeSearchGroup);
    searchLayout->addWidget(searchComboBox);
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
    showAddDialog = new QPushButton(QIcon(":/img/add"), tr(" Add an item"));
    showAddDialog->setToolTip(tr("Open an add dialog and add a new item"));
    clearListBtn = new QPushButton(QIcon(":/img/delete"), tr("Clear"));
    clearListBtn->setToolTip(tr("Delete all item"));
    exitBtn = new QPushButton(QIcon(":/img/exit"), tr(" Exit"));

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
    connect(clearSearchButton, SIGNAL(clicked()), searchBar, SLOT(clear()));
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
    return QSize(550,500);
}

MainWindow::~MainWindow(){}

#include "adddialog.h"

#include <QSize>

void AddDialog::showDocWidget(bool show){
    show ? docMenu->show() : docMenu->hide();
}

void AddDialog::showMovWidget(bool show){
    show ? movMenu->show() : movMenu->hide();
}

void AddDialog::showTvSWidget(bool show){
    if (show) {
        tvsMenu->show();
        movMenu->show();
    }
    else {
        tvsMenu->hide();
        movMenu->hide();
    }
}

AddDialog::AddDialog(MainWidget* p): parent(p) {
    QStringList listOfGenre;
    listOfGenre << "Unknown" << "Action" << "Adventure" << "Animation" << "Comedy" << "Crime" << "Drama" << "Fantasy" ;

    QStringList listOfRating;
    listOfRating << "All" << "VM18" << "VM14";

    QIntValidator * positVal = new QIntValidator();
    positVal->setBottom(0);

    //----------------[UpperRadioButtons]
    doc = new QRadioButton(tr("Documentary"));
    mov = new QRadioButton(tr("Movie"));
    tvs = new QRadioButton(tr("tvSerie"));

    QVBoxLayout * typeSelectorBox = new QVBoxLayout;
    typeSelectorBox->addWidget(doc);
    typeSelectorBox->addWidget(mov);
    typeSelectorBox->addWidget(tvs);
    typeSelectorBox->addStretch(1);

    QGroupBox * typeSelGroupBox = new   QGroupBox(tr("Seleziona il tipo"));
    typeSelGroupBox->setLayout(typeSelectorBox);

    connect(doc, SIGNAL(toggled(bool)), this, SLOT(showDocWidget(bool)));
    connect(mov, SIGNAL(toggled(bool)), this, SLOT(showMovWidget(bool)));
    connect(tvs, SIGNAL(toggled(bool)), this, SLOT(showTvSWidget(bool)));
    //----------------[]

    //----------------[Central]
    title = new QLineEdit();
    title->setPlaceholderText(QString("Title"));

    date = new QLineEdit();
    date->setValidator(positVal);
    date->setPlaceholderText(QString("Release year"));

    //dir

    fav = new QCheckBox("Favorite");

    QHBoxLayout * titleBox = new QHBoxLayout;
    titleBox->addWidget(title);
    titleBox->addWidget(date);
    titleBox->addWidget(fav);

    descr = new QTextEdit();
    descr->setPlaceholderText(QString("Description"));

    //img

    rt = new QLineEdit();
    rt->setValidator(positVal);
    rt->setPlaceholderText(QString("Running time"));

    ac = new QCheckBox("Audio compression");

    imgres= new QLineEdit();
    imgres->setPlaceholderText(QString("Image resolution"));

    frameps = new QLineEdit();
    frameps->setValidator(positVal);
    frameps->setPlaceholderText(QString("Fps"));

    QVBoxLayout * specBox = new QVBoxLayout();
    specBox->addWidget(rt);
    specBox->addWidget(ac);
    specBox->addWidget(imgres);
    specBox->addWidget(frameps);

    QHBoxLayout * descrBox = new QHBoxLayout;
    descrBox->addWidget(descr);
    descrBox->addLayout(specBox);

    QVBoxLayout * mainLayout = new QVBoxLayout;
    mainLayout->addLayout(titleBox);
    mainLayout->addLayout(descrBox);

    docNarr = new QLineEdit();
    docNarr ->setPlaceholderText("Narrator");
    docTopic = new QLineEdit();
    docTopic->setPlaceholderText(tr("Main topic"));

    cast = new QTextEdit();
    cast->setPlaceholderText(tr("Cast"));
    genre = new QComboBox();
    genre->addItems(listOfGenre);
    rating = new QComboBox();
    rating->addItems(listOfRating);

    tvSeason = new QLineEdit();
    tvSeason->setValidator(positVal);
    tvSeason->setPlaceholderText(QString("Season"));

    tvEpisode = new QLineEdit();
    tvEpisode->setValidator(positVal);
    tvEpisode->setPlaceholderText(QString("Episode"));

    tvEnded = new QCheckBox(tr("This serie has ended"));

    QHBoxLayout * docLayout = new QHBoxLayout;
    docLayout->addWidget(docNarr);
    docLayout->addWidget(docTopic);
    docMenu = new QWidget;
    docMenu->setLayout(docLayout);

    QVBoxLayout * aux1 = new QVBoxLayout;
    aux1->addWidget(genre);
    aux1->addWidget(rating);
    QHBoxLayout * movLayout = new QHBoxLayout;
    movLayout->addWidget(cast);
    movLayout->addLayout(aux1);
    movMenu = new QWidget;
    movMenu->setLayout(movLayout);

    QVBoxLayout * tvsLayout = new QVBoxLayout();
    tvsLayout->addWidget(tvSeason);
    tvsLayout->addWidget(tvEpisode);
    tvsLayout->addWidget(tvEnded);
    tvsMenu = new QWidget;
    tvsMenu->setLayout(tvsLayout);

    QHBoxLayout * menuLayout = new QHBoxLayout;
    menuLayout->addWidget(docMenu);
    menuLayout->addWidget(movMenu);
    menuLayout->addWidget(tvsMenu);

    //----------------[]

    //----------------[LowerButtons]
    add =new QPushButton(tr("Aggiungi elemento"));
    cancel =new QPushButton(tr("Cancel"));
    QHBoxLayout * lowerButtonsBox = new QHBoxLayout;

    lowerButtonsBox->addWidget(add);
    lowerButtonsBox->addWidget(cancel);

    connect(add, SIGNAL(clicked()), this, SLOT(accept()));
    connect(cancel, SIGNAL(clicked()), this, SLOT(reject()));
    //----------------[]

    doc->setChecked(true);
    showDocWidget(true);
    showMovWidget(false);
    showTvSWidget(false);

    setWindowTitle("Inserisci elemento");

    mainBox = new QVBoxLayout;
    mainBox->addWidget(typeSelGroupBox);
    mainBox->addLayout(mainLayout);
    mainBox->addStretch(1);
    mainBox->addSpacing(5);
    mainBox->addLayout(menuLayout);
    mainBox->addLayout(lowerButtonsBox);
    setLayout(mainBox);
}


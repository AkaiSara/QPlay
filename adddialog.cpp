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
        tvSMenu->show();
        movMenu->show();
    }
    else {
        tvSMenu->hide();
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

    //----------------[TypeSelector]
    QVBoxLayout * typeSelectorLayout = new QVBoxLayout;
    doc = new QRadioButton(tr("Documentary"));
    mov = new QRadioButton(tr("Movie"));
    tvs = new QRadioButton(tr("tvSerie"));

    typeSelectorLayout->addWidget(doc);
    typeSelectorLayout->addWidget(mov);
    typeSelectorLayout->addWidget(tvs);
    typeSelectorLayout->addStretch(1);

    QGroupBox * typeSelectorGroupBox = new QGroupBox(tr("Seleziona il tipo"));
    typeSelectorGroupBox->setLayout(typeSelectorLayout);

    connect(doc, SIGNAL(toggled(bool)), this, SLOT(showDocWidget(bool)));
    connect(mov, SIGNAL(toggled(bool)), this, SLOT(showMovWidget(bool)));
    connect(tvs, SIGNAL(toggled(bool)), this, SLOT(showTvSWidget(bool)));
    //----------------[]

    //----------------[Central]

    //title date

    title = new QLineEdit();
    title->setPlaceholderText(QString("Title"));

    date = new QLineEdit();
    date->setValidator(positVal);
    date->setPlaceholderText(QString("Release year"));

    fav = new QCheckBox("Favorite");

    QHBoxLayout * titleBox = new QHBoxLayout;
    titleBox->addWidget(title);
    titleBox->addWidget(date);
    titleBox->addWidget(fav);

    //description

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


    QVBoxLayout * specBox = new QVBoxLayout;
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
    //----------------[]


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

    QVBoxLayout * aux = new QVBoxLayout;
    aux->addWidget(genre);
    aux->addWidget(rating);
    QHBoxLayout * movLayout = new QHBoxLayout;
    movLayout->addWidget(cast);
    movLayout->addLayout(aux);
    movMenu = new QWidget;
    movMenu->setLayout(movLayout);

    QVBoxLayout * tvSLayout = new QVBoxLayout;
    tvSLayout->addWidget(tvSeason);
    tvSLayout->addWidget(tvEpisode);
    tvSLayout->addWidget(tvEnded);
    tvSMenu = new QWidget;
    tvSMenu->setLayout(tvSLayout);

    QHBoxLayout * secondLayout = new QHBoxLayout;
    secondLayout->addWidget(docMenu);
    secondLayout->addWidget(movMenu);
    secondLayout->addWidget(tvSMenu);

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
    mainBox->addWidget(typeSelectorGroupBox);
    mainBox->addLayout(mainLayout);
    mainBox->addStretch(1);
    mainBox->addSpacing(15);
    mainBox->addLayout(secondLayout);
    mainBox->addLayout(lowerButtonsBox);
    setLayout(mainBox);
}

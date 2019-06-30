#include "adddialog.h"

#include <QSize>

void AddDialog::showDocWidget(){
    cast->hide();
    tvSeason->hide();
    tvEpisode->hide();
    tvEnded->hide();
    genre->hide();
    rating->hide();

    docNarr->show();
    docTopic->show();

    hBox->addWidget(docNarr);
    hBox->addWidget(docTopic);
}

void AddDialog::showMovWidget(){
    docNarr->hide();
    docTopic->hide();
    tvSeason->hide();
    tvEpisode->hide();
    tvEnded->hide();

    cast->show();
    genre->show();
    rating->show();

    QVBoxLayout * aux = new QVBoxLayout;
    aux->addWidget(genre);
    aux->addWidget(rating);
    hBox->addWidget(cast);
    hBox->addLayout(aux);
}

void AddDialog::showTvSWidget(){
    docNarr->hide();
    docTopic->hide();

    tvSeason->show();
    tvEpisode->show();
    cast->show();
    tvEnded->show();
    genre->show();
    rating->show();

    QVBoxLayout * aux1 = new QVBoxLayout();
    aux1->addWidget(tvSeason);
    aux1->addWidget(tvEpisode);
    aux1->addWidget(tvEnded);

    QVBoxLayout * aux2 = new QVBoxLayout();
    aux2->addWidget(genre);
    aux2->addWidget(rating);

    hBox->addLayout(aux1);
    hBox->addLayout(aux2);
    hBox->addWidget(cast);
}

AddDialog::AddDialog(MainWidget* p): parent(p) {
    QStringList listOfGenre;
    listOfGenre << "Unknown" << "Action" << "Adventure" << "Animation" << "Comedy" << "Crime" << "Drama" << "Fantasy" ;

    QStringList listOfRating;
    listOfRating << "All" << "VM18" << "VM14";

    QIntValidator * positVal = new QIntValidator();
    positVal->setBottom(0);
    hBox = new QHBoxLayout;

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

    setWindowTitle("Inserisci elemento");

    //----------------[UpperRadioButtons]
    doc = new QRadioButton(tr("Documentary"));
    mov = new QRadioButton(tr("Movie"));
    tvs = new QRadioButton(tr("tvSerie"));
    QVBoxLayout * radioListBox = new QVBoxLayout;
    QGroupBox * upperRadioButtonsGroup = new QGroupBox(tr("Seleziona il tipo"));

    doc->setChecked(true);
    showDocWidget();

    radioListBox->addWidget(doc);
    radioListBox->addWidget(mov);
    radioListBox->addWidget(tvs);
    radioListBox->addStretch(1);
    upperRadioButtonsGroup->setLayout(radioListBox);

    connect(doc, SIGNAL(clicked()), this, SLOT(showDocWidget()));
    connect(mov, SIGNAL(clicked()), this, SLOT(showMovWidget()));
    connect(tvs, SIGNAL(clicked()), this, SLOT(showTvSWidget()));
    //----------------[]

    //----------------[Central]
    title = new QLineEdit();
    title->setPlaceholderText(QString("Title"));

    date= new QLineEdit();
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

    mainBox = new QVBoxLayout;
    mainBox->addWidget(upperRadioButtonsGroup);
    mainBox->addLayout(mainLayout);
    mainBox->addStretch(1);
    mainBox->addSpacing(15);
    mainBox->addLayout(hBox);
    mainBox->addLayout(lowerButtonsBox);
    setLayout(mainBox);
}


#include "displaywidget.h"


DisplayWidget::DisplayWidget(DeepPtr<AudioVisual> a, QWidget * p) :avPtr(a), parent(p) {
    QVBoxLayout * mainLayout = new QVBoxLayout;
    QFrame *line;


    //----------------[Prima parte]
    titolo = new QLabel("Titolo: " + QString::fromStdString(avPtr->getTitle()));
    tipo = new QLabel("Tipo: " + QString::fromStdString(avPtr->getType()));
    anno = new QLabel("Anno: " + QString::number(avPtr->getRelease_date()));
    dir = new QLabel("Direttore: " + QString::fromStdString(avPtr->getDirector()));
    QString favString = (avPtr->isFavorite())? "Si" : "No";
    fav = new QLabel("Preferiti: " + favString);
    tempo = new QLabel("Durata: " + QString::number(avPtr->getRunning_time()));
    //img = new QLabel(QString::fromStdString(avPtr->())); qhbox info | img oppure img | info

    //----------------[]

    //----------------[Seconda parte]
    descr = new QLabel("Descrizione: " + QString::fromStdString(avPtr->getDescription()));
    descr->setWordWrap(true);

    //----------------[]

    //----------------[Terza parte]
    fps = new QLabel("FPS: " + QString::number(avPtr->getFps()));
    ris = new QLabel("Risoluzione immagine: " + QString::number(avPtr->getImage_resolution()));
    QString audioString = (avPtr->isAudioComp())? "Si" : "No";
    audio = new QLabel("Compressione audio: " + audioString);

    QHBoxLayout * tec = new QHBoxLayout;
    tec->addWidget(ris);
    tec->addWidget(audio);
    tec->addWidget(fps);

    //----------------[]

    //----------------[Costruzione parziale del mainLayout]
    mainLayout->addWidget(titolo);
    mainLayout->addWidget(tipo);
    mainLayout->addWidget(anno);
    mainLayout->addWidget(dir);
    mainLayout->addWidget(fav);
    mainLayout->addWidget(tempo);

    line = new QFrame(); //spaziatore
    line->setFrameShape(QFrame::HLine);
    line->setFrameShadow(QFrame::Raised);
    mainLayout->addWidget(line);

    mainLayout->addWidget(descr);

    line = new QFrame(); //spaziatore
    line->setFrameShape(QFrame::HLine);
    line->setFrameShadow(QFrame::Raised);
    mainLayout->addWidget(line);

    mainLayout->addLayout(tec);

    line = new QFrame(); //spaziatore
    line->setFrameShape(QFrame::HLine);
    line->setFrameShadow(QFrame::Raised);
    mainLayout->addWidget(line);

    //----------------[]

    //----------------[Quarta parte]
    QHBoxLayout * docLayout = new QHBoxLayout;
    QHBoxLayout * movLayout = new QHBoxLayout;
    QVBoxLayout * tvsLayout = new QVBoxLayout;

    if(dynamic_cast<Documentary *>(&(*avPtr)) != nullptr){
        Documentary * aux = static_cast<Documentary *>(&(*avPtr));
        narratore = new QLabel("Narratore: " + QString::fromStdString(aux->getNarrator()));
        topic = new QLabel("Topic: " + QString::fromStdString(aux->getTopic()));

        docLayout->addWidget(narratore);
        docLayout->addWidget(topic);
        mainLayout->addLayout(docLayout);
    }
    if(dynamic_cast<Movie *>(&(*avPtr)) != nullptr){
        Movie * aux = static_cast<Movie *>(&(*avPtr));
        cast = new QLabel("Cast: " + QString::fromStdString(aux->getCast()));
        cast->setWordWrap(true);
        rating = new QLabel("Rating: " + QString::fromStdString(aux->getRating()));
        genere = new QLabel("Genere: " + QString::fromStdString(aux->getGenre()));

        movLayout->addWidget(cast);
        movLayout->addWidget(rating);
        movLayout->addWidget(genere);
        mainLayout->addLayout(movLayout);
    }
    if(dynamic_cast<TvSerie *>(&(*avPtr)) != nullptr){
        TvSerie * aux = static_cast<TvSerie *>(&(*avPtr));
        cast = new QLabel("Cast: " + QString::fromStdString(aux->getCast()));
        cast->setWordWrap(true);
        rating = new QLabel("Rating: " + QString::fromStdString(aux->getRating()));
        genere = new QLabel("Genere: " + QString::fromStdString(aux->getGenre()));
        ep = new QLabel("Episodi: " + QString::number(aux->getEpisode()));
        st = new QLabel("Stagioni: " + QString::number(aux->getSeason()));
        QString endString = (aux->isEnded())? "Si" : "No";
        end = new QLabel("Terminata?: " + endString);

        QHBoxLayout * tmp1 = new QHBoxLayout;
        tmp1->addWidget(cast);
        tmp1->addWidget(rating);
        tmp1->addWidget(genere);
        tvsLayout->addLayout(tmp1);

        QHBoxLayout * tmp2 = new QHBoxLayout;
        tmp2->addWidget(ep);
        tmp2->addWidget(st);
        tmp2->addWidget(end);
        tvsLayout->addLayout(tmp2);

        mainLayout->addLayout(tvsLayout);
    }
    //----------------[]


    setLayout(mainLayout);
}

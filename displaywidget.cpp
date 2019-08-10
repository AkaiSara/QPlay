#include "displaywidget.h"


DisplayWidget::DisplayWidget(DeepPtr<AudioVisual> a, QWidget * p) :avPtr(a), parent(p) {
    QVBoxLayout * mainLayout = new QVBoxLayout;
    QFrame *line;
    setWindowTitle("Item details");

    //----------------[Prima parte]
    title = new QLabel("Title: " + QString::fromStdString(avPtr->getTitle()));
    type = new QLabel("Type: " + QString::fromStdString(avPtr->getType()));
    year = new QLabel("Year: " + QString::number(avPtr->getRelease_date()));
    dir = new QLabel("Director: " + QString::fromStdString(avPtr->getDirector()));
    QString favString = (avPtr->isFavorite())? "Yes" : "No";
    fav = new QLabel("Favorites: " + favString);
    time = new QLabel("Duration: " + QString::number(avPtr->getRunning_time()));
    //img = new QLabel(QString::fromStdString(avPtr->())); qhbox info | img oppure img | info

    //----------------[]

    //----------------[Seconda parte]
    descr = new QLabel("Description: " + QString::fromStdString(avPtr->getDescription()));
    descr->setWordWrap(true);

    //----------------[]

    //----------------[Terza parte]
    frame = new QLabel("Frame rate: " + QString::number(avPtr->getFps()));
    res = new QLabel("Image resolution: " + QString::number(avPtr->getImage_resolution()));
    QString audioString = (avPtr->isAudioComp())? "Yes" : "No";
    audio = new QLabel("Audio compression: " + audioString);

    QHBoxLayout * tec = new QHBoxLayout;
    tec->addWidget(res);
    tec->addWidget(audio);
    tec->addWidget(frame);

    //----------------[]

    //----------------[Costruzione parziale del mainLayout]
    mainLayout->addWidget(title);
    mainLayout->addWidget(type);
    mainLayout->addWidget(year);
    mainLayout->addWidget(dir);
    mainLayout->addWidget(fav);
    mainLayout->addWidget(time);

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
        narrator = new QLabel("Narrator: " + QString::fromStdString(aux->getNarrator()));
        topic = new QLabel("Topic: " + QString::fromStdString(aux->getTopic()));

        docLayout->addWidget(narrator);
        docLayout->addWidget(topic);
        mainLayout->addLayout(docLayout);
    }
    if(dynamic_cast<Movie *>(&(*avPtr)) != nullptr){
        Movie * aux = static_cast<Movie *>(&(*avPtr));
        cast = new QLabel("Cast: " + QString::fromStdString(aux->getCast()));
        cast->setWordWrap(true);
        rating = new QLabel("Rating: " + QString::fromStdString(aux->getRating()));
        genre = new QLabel("Genre: " + QString::fromStdString(aux->getGenre()));

        movLayout->addWidget(cast);
        movLayout->addWidget(rating);
        movLayout->addWidget(genre);
        mainLayout->addLayout(movLayout);
    }
    if(dynamic_cast<TvSerie *>(&(*avPtr)) != nullptr){
        TvSerie * aux = static_cast<TvSerie *>(&(*avPtr));
        cast = new QLabel("Cast: " + QString::fromStdString(aux->getCast()));
        cast->setWordWrap(true);
        rating = new QLabel("Rating: " + QString::fromStdString(aux->getRating()));
        genre = new QLabel("Genre: " + QString::fromStdString(aux->getGenre()));
        ep = new QLabel("Episodes: " + QString::number(aux->getEpisode()));
        st = new QLabel("Seasons: " + QString::number(aux->getSeason()));
        QString endString = (aux->isEnded())? "Yes" : "No";
        end = new QLabel("Ended: " + endString);

        QHBoxLayout * tmp1 = new QHBoxLayout;
        tmp1->addWidget(cast);
        tmp1->addWidget(rating);
        tmp1->addWidget(genre);
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

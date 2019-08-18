#include "displaywidget.h"

DisplayWidget::DisplayWidget(DeepPtr<AudioVisual> a, QWidget * p) :avPtr(a), parent(p) {
    QVBoxLayout * mainLayout = new QVBoxLayout;
    QFrame *line;
    setWindowTitle("Item details");
    setMinimumSize(QSize(500,300));
    setMaximumSize(QSize(600,400));

    //----------------[Prima parte]
    title = new QLabel("Title: " + QString::fromStdString(avPtr->getTitle()));
    type = new QLabel("Type: " + QString::fromStdString(avPtr->getType()));
    year = new QLabel("Year: " + QString::number(avPtr->getRelease_date()));
    dir = new QLabel("Director: " + QString::fromStdString(avPtr->getDirector()));
    QString favString = (avPtr->isFavorite())? "Yes" : "No";
    fav = new QLabel("Favorites: " + favString);
    time = new QLabel("Duration: " + QString::number(avPtr->getRunning_time()));
    img = new QLabel;
    img->setPixmap(QPixmap(QString::fromStdString((avPtr->getPath() != ""? avPtr->getPath() : ":/img/picture"))).scaled(150, 150, Qt::KeepAspectRatio));

    //----------------[]

    //----------------[Seconda parte]
    descr = new QLabel("Description: " + QString::fromStdString(avPtr->getDescription()));
    descr->setWordWrap(true);

    //----------------[]

    //----------------[Terza parte]
    frame = new QLabel("Frame rate: " + QString::number(avPtr->getFps()));
    res = new QLabel("Image resolution: " + QString::number(avPtr->getImage_resolution()));
    audio = new QLabel("Audio compression: " + QString::fromStdString(avPtr->isAudioComp() ? "Yes" : "No"));

    QLabel * matureContent = new QLabel("Mature content: " + QString::fromStdString(avPtr->matureContent() ? "Yes" : "No"));
    QLabel * quality = new QLabel("Quality: " + QString::fromStdString(avPtr->isHighQuality()? "Yes" : "No"));
    QLabel * totalRunningTime = new QLabel("Total running time: " + QString::number(avPtr->getTotalRunningTime()));

    QHBoxLayout * tec = new QHBoxLayout;
    tec->addWidget(res);
    tec->addWidget(audio);
    tec->addWidget(frame);

    QHBoxLayout * metodiPuri = new QHBoxLayout;
    metodiPuri->addWidget(matureContent);
    metodiPuri->addWidget(quality);
    metodiPuri->addWidget(totalRunningTime);

    //----------------[]

    //----------------[Costruzione parziale del mainLayout]
    QVBoxLayout * titleLayout = new QVBoxLayout;
    titleLayout->addWidget(title);
    titleLayout->addWidget(type);
    titleLayout->addWidget(year);
    titleLayout->addWidget(dir);
    titleLayout->addWidget(fav);
    titleLayout->addWidget(time);

    QHBoxLayout * imgTitleLayout = new QHBoxLayout;
    imgTitleLayout->addLayout(titleLayout);
    imgTitleLayout->addWidget(img);

    mainLayout->addLayout(imgTitleLayout);

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
    mainLayout->addLayout(metodiPuri);

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

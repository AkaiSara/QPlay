#include "editwidget.h"

void EditWidget::selectImg(){
    QFileDialog dialog;
    dialog.setFileMode(QFileDialog::ExistingFile);
    dialog.setNameFilter(("Files (*.png *.jpg)"));

    if (dialog.exec() == QDialog::Accepted) {
        imgPath = dialog.selectedFiles().first();
        imgLabel->setPixmap(QPixmap(imgPath).scaled(150, 150, Qt::KeepAspectRatio));
        imgLabel->show();
    }
}

void EditWidget::modifyItem(){
    edited = avPtr;
    edited->setTitle(titleEdit->text().toStdString());
    edited->setDescription(descr->toPlainText().toStdString());
    edited->setRelease_date(dateEdit->text().toUInt());
    edited->setDirector(directorEdit->text().toStdString());
    edited->setFavorite(fav->isChecked());
    edited->setPath(imgPath.toStdString());
    edited->setRunning_time(rtEdit->text().toUInt());
    edited->setAudioComp(ac->isChecked());
    edited->setImage_resolution(imgresEdit->text().toUInt());
    edited->setFps(frameRateEdit->text().toUInt());

    if (dynamic_cast<Documentary *>(&(*avPtr)) != nullptr){
        Documentary * edited = static_cast<Documentary *>(&(*avPtr));
        edited->setNarrator(docNarrEdit->text().toStdString());
        edited->setTopic(docTopicEdit->text().toStdString());
    }
    else if (dynamic_cast<Movie *>(&(*avPtr)) != nullptr){
        Movie * edited = static_cast<Movie *>(&(*avPtr));
        edited->setCast(cast->toPlainText().toStdString());
        edited->setRating(rating->currentText().toStdString());
        edited->setGenre(genre->currentText().toStdString());
    }
    else if (dynamic_cast<TvSerie *>(&(*avPtr)) != nullptr){
        TvSerie * edited = static_cast<TvSerie *>(&(*avPtr));
        edited->setCast(cast->toPlainText().toStdString());
        edited->setRating(rating->currentText().toStdString());
        edited->setGenre(genre->currentText().toStdString());
        edited->setSeason(tvSeasonEdit->text().toUInt());
        edited->setEpisode(tvEpisodeEdit->text().toUInt());
        edited->setEnded(tvEnded->isChecked());
    }
}

DeepPtr<AudioVisual> EditWidget::getEdited(){
    return edited;
}

EditWidget::EditWidget(DeepPtr<AudioVisual> a, QWidget * p) : avPtr(a), parent(p) {
    setMaximumSize(QSize(500,580));
    setMinimumSize(QSize(450,500));

    QStringList listOfGenre;
    foreach (std::string str, AudioVisual::Genre) {
        listOfGenre.append(QString::fromStdString(str));
    }

    QStringList listOfRating;
    foreach (std::string str, AudioVisual::Rating) {
        listOfRating.append(QString::fromStdString(str));
    }

    QIntValidator * positVal = new QIntValidator();
    positVal->setBottom(0);

    //----------------[Central]
    QLabel * titleLab = new QLabel("Title: ");
    titleEdit = new QLineEdit();
    titleEdit->setPlaceholderText(QString("Title"));
    titleEdit->setText(QString::fromStdString(avPtr->getTitle()));
    QHBoxLayout * title = new QHBoxLayout;
    title->addWidget(titleLab);
    title->addWidget(titleEdit);

    QLabel * dateLab = new QLabel("Release year: ");
    dateEdit = new QLineEdit();
    dateEdit->setValidator(positVal);
    dateEdit->setMaxLength(4);
    dateEdit->setPlaceholderText(QString("Release year"));
    dateEdit->setText(QString::number(avPtr->getRelease_date()));
    QHBoxLayout * date = new QHBoxLayout;
    date->addWidget(dateLab);
    date->addWidget(dateEdit);

    QLabel * dirLab = new QLabel("Director: ");
    directorEdit = new QLineEdit();
    directorEdit->setPlaceholderText(QString("Director"));
    directorEdit->setText(QString::fromStdString(avPtr->getDirector()));
    QHBoxLayout * director = new QHBoxLayout;
    director->addWidget(dirLab);
    director->addWidget(directorEdit);

    QHBoxLayout * titleBox = new QHBoxLayout;
    titleBox->addLayout(title);
    titleBox->addLayout(date);
    titleBox->addLayout(director);

    fav = new QCheckBox("Favorite");
    fav->setChecked(avPtr->isFavorite());

    QLabel * rtLab= new QLabel("Running time");
    rtEdit = new QLineEdit();
    rtEdit->setValidator(positVal);
    rtEdit->setPlaceholderText(QString("Running time"));
    rtEdit->setText(QString::number(avPtr->getRunning_time()));
    QHBoxLayout * rt = new QHBoxLayout;
    rt->addWidget(rtLab);
    rt->addWidget(rtEdit);

    descr = new QTextEdit();
    descr->setPlaceholderText(QString("Description"));
    descr->setText(QString::fromStdString(avPtr->getDescription()));

    QVBoxLayout * favRtBox = new QVBoxLayout;
    favRtBox->addWidget(fav);
    favRtBox->addLayout(rt);
    favRtBox->addWidget(descr);

    selectImgBtn = new QPushButton("Select image");
    imgLabel = new QLabel();
    imgLabel->setPixmap(QPixmap(QString::fromStdString((avPtr->getPath() != "" ? avPtr->getPath() : ":/img/picture"))).scaled(150, 150, Qt::KeepAspectRatio));
    QVBoxLayout *imgLayout = new QVBoxLayout();
    imgLayout->addWidget(selectImgBtn);
    imgLayout->addWidget(imgLabel);

    QHBoxLayout * descrImageBox = new QHBoxLayout;
    descrImageBox->addLayout(favRtBox);
    descrImageBox->addLayout(imgLayout);

    ac = new QCheckBox("Audio compression");
    ac->setChecked(avPtr->isAudioComp());

    QLabel * irLab = new QLabel("Image resolution:");
    imgresEdit = new QLineEdit();
    imgresEdit->setPlaceholderText(QString("Image resolution"));
    imgresEdit->setText(QString::number(avPtr->getImage_resolution()));
    QHBoxLayout * imgres = new QHBoxLayout;
    imgres->addWidget(irLab);
    imgres->addWidget(imgresEdit);

    QLabel * frLab = new QLabel("Frame rate:");
    frameRateEdit = new QLineEdit();
    frameRateEdit->setValidator(positVal);
    frameRateEdit->setPlaceholderText(QString("Frame rate"));
    frameRateEdit->setText(QString::number(avPtr->getFps()));
    QHBoxLayout * frameRate = new QHBoxLayout;
    frameRate->addWidget(frLab);
    frameRate->addWidget(frameRateEdit);

    QHBoxLayout * specBox = new QHBoxLayout();
    specBox->addWidget(ac);
    specBox->addLayout(imgres);
    specBox->addLayout(frameRate);

    QVBoxLayout * mainLayout = new QVBoxLayout;
    mainLayout->addLayout(titleBox);
    mainLayout->addLayout(descrImageBox);
    mainLayout->addLayout(specBox);

    QHBoxLayout * docLayout = new QHBoxLayout;
    QHBoxLayout * movLayout = new QHBoxLayout;
    QVBoxLayout * tvsLayout = new QVBoxLayout;
    QHBoxLayout * menuLayout = new QHBoxLayout;

    if(dynamic_cast<Documentary *>(&(*avPtr)) != nullptr){
        Documentary * aux = static_cast<Documentary *>(&(*avPtr));

        QLabel * narrLab= new QLabel("Narrator");
        docNarrEdit = new QLineEdit();
        docNarrEdit ->setPlaceholderText("Narrator");
        docNarrEdit->setText(QString::fromStdString(aux->getNarrator()));
        QHBoxLayout * docNarr = new QHBoxLayout;
        docNarr->addWidget(narrLab);
        docNarr->addWidget(docNarrEdit);

        QLabel * topicLab= new QLabel("Main topic");
        docTopicEdit = new QLineEdit();
        docTopicEdit->setPlaceholderText(tr("Main topic"));
        docTopicEdit->setText(QString::fromStdString(aux->getTopic()));
        QHBoxLayout * docTopic = new QHBoxLayout;
        docTopic->addWidget(topicLab);
        docTopic->addWidget(docTopicEdit);

        docLayout->addLayout(docNarr);
        docLayout->addLayout(docTopic);
        docMenu = new QWidget;
        docMenu->setLayout(docLayout);

        menuLayout->addWidget(docMenu);
    }

    if(dynamic_cast<Movie *>(&(*avPtr)) != nullptr){
        Movie * aux = static_cast<Movie *>(&(*avPtr));
        cast = new QTextEdit();
        cast->setPlaceholderText(tr("Cast"));
        cast->setText(QString::fromStdString(aux->getCast()));
        genre = new QComboBox();
        genre->addItems(listOfGenre);
        int index = genre->findText(QString::fromStdString(aux->getGenre()));
        if(index != -1){
            genre->setCurrentIndex(index);
        }
        rating = new QComboBox();
        rating->addItems(listOfRating);
        index = rating->findText(QString::fromStdString(aux->getRating()));
        if(index != -1){
            rating->setCurrentIndex(index);
        }

        QVBoxLayout * aux1 = new QVBoxLayout;
        aux1->addWidget(genre);
        aux1->addWidget(rating);

        movLayout->addWidget(cast);
        movLayout->addLayout(aux1);
        movMenu = new QWidget;
        movMenu->setLayout(movLayout);

        menuLayout->addWidget(movMenu);
    }

    if(dynamic_cast<TvSerie *>(&(*avPtr)) != nullptr){
        TvSerie * aux = static_cast<TvSerie *>(&(*avPtr));
        cast = new QTextEdit();
        cast->setPlaceholderText(tr("Cast"));
        cast->setText(QString::fromStdString(aux->getCast()));
        genre = new QComboBox();
        genre->addItems(listOfGenre);
        int index = genre->findText(QString::fromStdString(aux->getGenre()));
        if(index != -1){
            genre->setCurrentIndex(index);
        }
        rating = new QComboBox();
        rating->addItems(listOfRating);
        index = rating->findText(QString::fromStdString(aux->getRating()));
        if(index != -1){
            rating->setCurrentIndex(index);
        }

        QLabel * snLab= new QLabel("Season");
        tvSeasonEdit = new QLineEdit();
        tvSeasonEdit->setValidator(positVal);
        tvSeasonEdit->setPlaceholderText(QString("Season"));
        tvSeasonEdit->setText(QString::number(aux->getSeason()));
        QHBoxLayout * tvSeason = new QHBoxLayout;
        tvSeason->addWidget(snLab);
        tvSeason->addWidget(tvSeasonEdit);

        QLabel * epLab= new QLabel("Episode");
        tvEpisodeEdit = new QLineEdit();
        tvEpisodeEdit->setValidator(positVal);
        tvEpisodeEdit->setPlaceholderText(QString("Episode"));
        tvEpisodeEdit->setText(QString::number(aux->getEpisode()));
        QHBoxLayout * tvEpisode = new QHBoxLayout;
        tvEpisode->addWidget(epLab);
        tvEpisode->addWidget(tvEpisodeEdit);

        tvEnded = new QCheckBox(tr("This serie has ended"));
        tvEnded->setChecked(aux->isEnded());

        tvsLayout->addLayout(tvSeason);
        tvsLayout->addLayout(tvEpisode);
        tvsLayout->addWidget(tvEnded);
        tvsMenu = new QWidget;
        tvsMenu->setLayout(tvsLayout);

        menuLayout->addWidget(tvsMenu);
    }


    //----------------[]

    //----------------[LowerButtons]
    edit =new QPushButton(QIcon(":/img/edit"), tr("&Edit"));
    cancel =new QPushButton(QIcon(":/img/cancel"), tr("&Cancel"));

    QHBoxLayout * lowerButtonsBox = new QHBoxLayout;
    lowerButtonsBox->addWidget(edit);
    lowerButtonsBox->addWidget(cancel);

    //----------------[]

    setWindowTitle("Edit item");

    mainBox = new QVBoxLayout;
    mainBox->addLayout(mainLayout);
    mainBox->addLayout(menuLayout);
    mainBox->addLayout(lowerButtonsBox);
    setLayout(mainBox);

    //----------------[Connect]
    connect(selectImgBtn, SIGNAL(clicked()), this, SLOT(selectImg()));

    connect(edit, SIGNAL(clicked()), this, SLOT(accept()));
    connect(cancel, SIGNAL(clicked()), this, SLOT(reject()));

    connect(this, SIGNAL(accepted()), this, SLOT(modifyItem()));

    //----------------[]
}

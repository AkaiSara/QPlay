#include "editwidget.h"
void EditWidget::selectImg(){
    QFileDialog dialog;
    dialog.setFileMode(QFileDialog::ExistingFile);
    dialog.setNameFilter(("File (*.png *.svg *.jpg)"));

    if (dialog.exec() == QDialog::Accepted) {
        imgPath = dialog.selectedFiles().first();
        imgLabel->setPixmap(QPixmap(imgPath).scaled(150, 150, Qt::KeepAspectRatio));
        imgLabel->show();
    }
}

void EditWidget::modifyItem(){
    edited = avPtr;
    edited->setTitle(title->text().toStdString());
    edited->setDescription(descr->toPlainText().toStdString());
    edited->setRelease_date(date->text().toUInt());
    edited->setDirector(director->text().toStdString());
    edited->setFavorite(fav->isChecked());
    edited->setPath(imgPath.toStdString());
    edited->setRunning_time(rt->text().toInt());
    edited->setAudioComp(ac->isChecked());
    edited->setImage_resolution(imgres->text().toUInt());
    edited->setFps(frameRate->text().toUInt());

    if (dynamic_cast<Documentary *>(&(*avPtr)) != nullptr){
        Documentary * edited = static_cast<Documentary *>(&(*avPtr));
        edited->setNarrator(docNarr->text().toStdString());
        edited->setTopic(docTopic->text().toStdString());
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
        edited->setSeason(tvSeason->text().toUInt());
        edited->setEpisode(tvEpisode->text().toUInt());
        edited->setEnded(tvEnded->isChecked());
    }
}

DeepPtr<AudioVisual> EditWidget::getEdited(){
    return edited;
}

EditWidget::EditWidget(DeepPtr<AudioVisual> a, QWidget * p) : avPtr(a), parent(p) {
    setMaximumSize(QSize(500,420));
    setMinimumSize(QSize(450,400));

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

    //----------------[UpperRadioButtons]
    /*doc = new QRadioButton(tr("Documentary"));
    mov = new QRadioButton(tr("Movie"));
    tvs = new QRadioButton(tr("TV Serie"));

    QHBoxLayout * typeSelectorBox = new QHBoxLayout;
    typeSelectorBox->addWidget(doc);
    typeSelectorBox->addWidget(mov);
    typeSelectorBox->addWidget(tvs);
    typeSelectorBox->addStretch(1);

    QGroupBox * typeSelGroupBox = new   QGroupBox(tr("Select type"));
    typeSelGroupBox->setLayout(typeSelectorBox);*/

    //----------------[]

    //----------------[Central]
    title = new QLineEdit();
    title->setPlaceholderText(QString("Title"));
    title->setText(QString::fromStdString(avPtr->getTitle()));

    date = new QLineEdit();
    date->setValidator(positVal);
    date->setPlaceholderText(QString("Release year"));
    date->setText(QString::number(avPtr->getRelease_date()));

    director = new QLineEdit();
    director->setPlaceholderText(QString("Director"));
    director->setText(QString::fromStdString(avPtr->getDirector()));

    fav = new QCheckBox("Favorite");
    fav->setChecked(avPtr->isFavorite());

    QHBoxLayout * titleBox = new QHBoxLayout;
    titleBox->addWidget(title);
    titleBox->addWidget(date);
    titleBox->addWidget(director);
    titleBox->addWidget(fav);

    selectImgBtn = new QPushButton("Seleziona immagine");
    imgLabel = new QLabel();
    QVBoxLayout *imgLayout = new QVBoxLayout();
    imgLayout->addWidget(selectImgBtn);
    imgLayout->addWidget(imgLabel);
    imgLabel->hide();

    QHBoxLayout * titleImgLayout = new QHBoxLayout;
    titleImgLayout->addLayout(titleBox);
    titleImgLayout->addLayout(imgLayout);

    descr = new QTextEdit();
    descr->setPlaceholderText(QString("Description"));
    descr->setText(QString::fromStdString(avPtr->getDescription()));

    rt = new QLineEdit();
    rt->setValidator(positVal);
    rt->setPlaceholderText(QString("Running time"));
    rt->setText(QString::number(avPtr->getRunning_time()));

    ac = new QCheckBox("Audio compression");
    ac->setChecked(avPtr->isAudioComp());

    imgres= new QLineEdit();
    imgres->setPlaceholderText(QString("Image resolution"));
    imgres->setText(QString::number(avPtr->getImage_resolution()));

    frameRate = new QLineEdit();
    frameRate->setValidator(positVal);
    frameRate->setPlaceholderText(QString("Frame rate"));
    frameRate->setText(QString::number(avPtr->getFps()));

    QVBoxLayout * specBox = new QVBoxLayout();
    specBox->addWidget(rt);
    specBox->addWidget(ac);
    specBox->addWidget(imgres);
    specBox->addWidget(frameRate);

    QHBoxLayout * descrBox = new QHBoxLayout;
    descrBox->addWidget(descr);
    descrBox->addLayout(specBox);

    QVBoxLayout * mainLayout = new QVBoxLayout;
    mainLayout->addLayout(titleImgLayout);
    mainLayout->addLayout(descrBox);

    QHBoxLayout * docLayout = new QHBoxLayout;
    QHBoxLayout * movLayout = new QHBoxLayout;
    QVBoxLayout * tvsLayout = new QVBoxLayout;
    QHBoxLayout * menuLayout = new QHBoxLayout;

    if(dynamic_cast<Documentary *>(&(*avPtr)) != nullptr){
        Documentary * aux = static_cast<Documentary *>(&(*avPtr));
        docNarr = new QLineEdit();
        docNarr ->setPlaceholderText("Narrator");
        docNarr->setText(QString::fromStdString(aux->getNarrator()));
        docTopic = new QLineEdit();
        docTopic->setPlaceholderText(tr("Main topic"));
        docTopic->setText(QString::fromStdString(aux->getTopic()));

        docLayout->addWidget(docNarr);
        docLayout->addWidget(docTopic);
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

        tvSeason = new QLineEdit();
        tvSeason->setValidator(positVal);
        tvSeason->setPlaceholderText(QString("Season"));
        tvSeason->setText(QString::number(aux->getSeason()));

        tvEpisode = new QLineEdit();
        tvEpisode->setValidator(positVal);
        tvEpisode->setPlaceholderText(QString("Episode"));
        tvEpisode->setText(QString::number(aux->getEpisode()));

        tvEnded = new QCheckBox(tr("This serie has ended"));
        tvEnded->setChecked(aux->isEnded());

        tvsLayout->addWidget(tvSeason);
        tvsLayout->addWidget(tvEpisode);
        tvsLayout->addWidget(tvEnded);
        tvsMenu = new QWidget;
        tvsMenu->setLayout(tvsLayout);

        menuLayout->addWidget(tvsMenu);
    }


    //----------------[]

    //----------------[LowerButtons]
    edit =new QPushButton(QIcon(":/img/edit"), tr("Edit"));
    cancel =new QPushButton(QIcon(":/img/cancel"), tr("Cancel"));

    QHBoxLayout * lowerButtonsBox = new QHBoxLayout;
    lowerButtonsBox->addWidget(edit);
    lowerButtonsBox->addWidget(cancel);

    //----------------[]

    setWindowTitle("Edit item");

    mainBox = new QVBoxLayout;
    //mainBox->addWidget(typeSelGroupBox);
    mainBox->addLayout(mainLayout);
    mainBox->addLayout(menuLayout);
    mainBox->addLayout(lowerButtonsBox);
    setLayout(mainBox);

    //----------------[Connect]
    //connect(doc, SIGNAL(toggled(bool)), this, SLOT(showDocWidget(bool)));
    //connect(mov, SIGNAL(toggled(bool)), this, SLOT(showMovWidget(bool)));
    //connect(tvs, SIGNAL(toggled(bool)), this, SLOT(showTvSWidget(bool)));

        connect(selectImgBtn, SIGNAL(clicked()), this, SLOT(selectImg()));

    connect(edit, SIGNAL(clicked()), this, SLOT(accept()));
    connect(cancel, SIGNAL(clicked()), this, SLOT(reject()));

    connect(this, SIGNAL(accepted()), this, SLOT(modifyItem()));

    //----------------[]
}

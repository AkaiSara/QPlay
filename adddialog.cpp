#include "adddialog.h"

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

void AddDialog::addNewItem() {
    AudioVisual * i = nullptr;

    try {
        if(title->text().toStdString() == "" || descr->toPlainText().toStdString()== "" || date->text().toUInt()== 0 || director->text().toStdString()== "" || rt->text().toInt() == 0 || imgres->text().toUInt() == 0 || frameRate->text().toUInt()== 0){
            throw Exception("Riempire tutti i campi dati!");
        } else if(doc->isChecked() && (docNarr->text().toStdString()== "" || docTopic->text().toStdString()== "")){
            throw Exception("Riempire tutti i campi dati!");
        } else if(mov->isChecked() && cast->toPlainText().toStdString() == ""){
            throw Exception("Riempire tutti i campi dati!");
        } else if(tvs->isChecked() && (cast->toPlainText().toStdString() == "" || tvSeason->text().toUInt() == 0 || tvEpisode->text().toUInt() == 0)){
            throw Exception("Riempire tutti i campi dati!");
        }

        if (doc->isChecked()){
            i = new Documentary(title->text().toStdString(), descr->toPlainText().toStdString(), date->text().toUInt(), director->text().toStdString(), fav->isChecked(), imgPath.toStdString(), rt->text().toUInt(), ac->isChecked(), imgres->text().toUInt(), frameRate->text().toUInt(), docNarr->text().toStdString(), docTopic->text().toStdString());
        }

        if (mov->isChecked()){
            i = new Movie(title->text().toStdString(), descr->toPlainText().toStdString(), date->text().toUInt(), director->text().toStdString(), fav->isChecked(), imgPath.toStdString(), rt->text().toUInt(), ac->isChecked(), imgres->text().toUInt(), frameRate->text().toUInt(), cast->toPlainText().toStdString(), genre->currentText().toStdString(), rating->currentText().toStdString());
        }

        if (tvs->isChecked()){
            i = new TvSerie(title->text().toStdString(), descr->toPlainText().toStdString(), date->text().toUInt(), director->text().toStdString(), fav->isChecked(), imgPath.toStdString(), rt->text().toUInt(), ac->isChecked(), imgres->text().toUInt(), frameRate->text().toUInt(), tvSeason->text().toUInt(), tvEpisode->text().toUInt(), cast->toPlainText().toStdString(), genre->currentText().toStdString(), tvEnded->isChecked(), rating->currentText().toStdString());
        }

        emit created(i);
        accept();
    } catch (Exception & e) {
        QMessageBox::warning(this, "Attenzione", QString::fromStdString(e.getErrorMessage()));
    }
}


void AddDialog::selectImg(){
    QFileDialog dialog;
    dialog.setFileMode(QFileDialog::ExistingFile);
    dialog.setNameFilter(("Files (*.png *.jpg)"));

    if (dialog.exec() == QDialog::Accepted) {
        imgPath = dialog.selectedFiles().first();

        imgLabel->setPixmap(QPixmap(imgPath).scaled(150, 150, Qt::KeepAspectRatio));
        imgLabel->show();
    }
}

AddDialog::AddDialog(QWidget * p) :parent(p) {
    setMaximumSize(QSize(600,600));
    setMinimumSize(QSize(500,400));

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
    doc = new QRadioButton(tr("Documentary"));
    mov = new QRadioButton(tr("Movie"));
    tvs = new QRadioButton(tr("TV Serie"));

    QHBoxLayout * typeSelectorBox = new QHBoxLayout;
    typeSelectorBox->addWidget(doc);
    typeSelectorBox->addWidget(mov);
    typeSelectorBox->addWidget(tvs);
    typeSelectorBox->addStretch(1);

    QGroupBox * typeSelGroupBox = new QGroupBox(tr("Select type"));
    typeSelGroupBox->setLayout(typeSelectorBox);

    //----------------[]

    //----------------[Central]
    title = new QLineEdit();
    title->setMaximumWidth(200);
    title->setPlaceholderText(QString("Title"));

    date = new QLineEdit();
    date->setValidator(positVal);
    date->setMaximumWidth(100);
    date->setPlaceholderText(QString("Release year"));

    director = new QLineEdit();
    director->setMaximumWidth(200);
    director->setPlaceholderText(QString("Director"));

    fav = new QCheckBox("Favorite");

    rt = new QLineEdit();
    rt->setMaximumWidth(200);
    rt->setValidator(positVal);
    rt->setPlaceholderText(QString("Running time in min"));

    QVBoxLayout * titleBox = new QVBoxLayout;
    titleBox->addWidget(title);
    titleBox->addWidget(date);
    titleBox->addWidget(director);
    titleBox->addWidget(fav);
    titleBox->addWidget(rt);

    selectImgBtn = new QPushButton("Select image");
    imgLabel = new QLabel();
    imgLabel->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
    QVBoxLayout *imgLayout = new QVBoxLayout();
    imgLayout->addWidget(selectImgBtn);
    imgLayout->addWidget(imgLabel);
    imgLabel->hide();

    QHBoxLayout * titleImgLayout = new QHBoxLayout;
    titleImgLayout->addLayout(titleBox);
    titleImgLayout->addLayout(imgLayout);

    descr = new QTextEdit();
    descr->setPlaceholderText(QString("Description"));

    ac = new QCheckBox("Audio compression");

    imgres= new QLineEdit();
    imgres->setMaximumWidth(200);
    imgres->setValidator(positVal);
    imgres->setPlaceholderText(QString("Image resolution"));

    frameRate = new QLineEdit();
    frameRate->setMaximumWidth(200);
    frameRate->setValidator(positVal);
    frameRate->setPlaceholderText(QString("Frame rate"));

    QVBoxLayout * specBox = new QVBoxLayout();
    specBox->addWidget(ac);
    specBox->addWidget(imgres);
    specBox->addWidget(frameRate);

    QHBoxLayout * descrBox = new QHBoxLayout;
    descrBox->addWidget(descr);
    descrBox->addLayout(specBox);

    QVBoxLayout * mainLayout = new QVBoxLayout;
    mainLayout->addLayout(titleImgLayout);
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
    add =new QPushButton(QIcon(":/img/add"), tr("&Add"));
    cancel =new QPushButton(QIcon(":/img/cancel"), tr("&Cancel"));

    QHBoxLayout * lowerButtonsBox = new QHBoxLayout;
    lowerButtonsBox->addWidget(add);
    lowerButtonsBox->addWidget(cancel);

    //----------------[]

    doc->setChecked(true);
    showDocWidget(true);
    showMovWidget(false);
    showTvSWidget(false);

    setWindowTitle("Add a new item");

    mainBox = new QVBoxLayout;
    mainBox->addWidget(typeSelGroupBox);
    mainBox->addLayout(mainLayout);
    mainBox->addStretch(1);
    mainBox->addSpacing(5);
    mainBox->addLayout(menuLayout);
    mainBox->addLayout(lowerButtonsBox);
    setLayout(mainBox);

    //----------------[Connect]
    //connect(this, SIGNAL(accepted()), this, SLOT(addNewItem()));

    connect(doc, SIGNAL(toggled(bool)), this, SLOT(showDocWidget(bool)));
    connect(mov, SIGNAL(toggled(bool)), this, SLOT(showMovWidget(bool)));
    connect(tvs, SIGNAL(toggled(bool)), this, SLOT(showTvSWidget(bool)));

    connect(selectImgBtn, SIGNAL(clicked()), this, SLOT(selectImg()));

    connect(add, SIGNAL(clicked()), this, SLOT(addNewItem()));
    connect(cancel, SIGNAL(clicked()), this, SLOT(reject()));

    connect(this, SIGNAL(created(AudioVisual *)), parent, SLOT(addItem(AudioVisual *)));

    //----------------[]
}

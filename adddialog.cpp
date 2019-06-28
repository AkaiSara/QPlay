#include "adddialog.h"

AddDialog::AddDialog(MainWidget* p): parent(p) {

    setWindowTitle("Inserisci elemento");

    //----------------[UpperRadioButtons]
    doc = new QRadioButton(tr("Documentary"));
    mov = new QRadioButton(tr("Movie"));
    tvs = new QRadioButton(tr("tvSerie"));
    radioListBox = new QVBoxLayout; //contiene i radio buttons
    buttonsGroup = new QButtonGroup();
    upperRadioButtonsGroup = new QGroupBox(tr("Seleziona il tipo")); //rende esclusivi tra loro i radio buttons

    doc->setChecked(true); //lo metto checked per far sì che sia cliccabile un solo bottone alla volta

    buttonsGroup->addButton(doc);
    buttonsGroup->addButton(mov);
    buttonsGroup->addButton(tvs);

    radioListBox->addWidget(doc);
    radioListBox->addWidget(mov);
    radioListBox->addWidget(tvs);
    radioListBox->addStretch(1);
    upperRadioButtonsGroup->setLayout(radioListBox);

    connect(buttonsGroup, SIGNAL(buttonClicked()), this, SLOT());
    //----------------[]

    //----------------[Central]
    title = new QLineEdit();
    title->setPlaceholderText(QString("Title"));

    date= new QLineEdit();
    date->setValidator(new QIntValidator());
    date->setPlaceholderText(QString("Release year"));
    //dir

    fav = new QCheckBox();
    favLabel = new QLabel("Favorite: ");
    QHBoxLayout * favBox = new QHBoxLayout;
    favBox->addWidget(favLabel);
    favBox->addWidget(fav);

    QHBoxLayout * titleBox = new QHBoxLayout;
    titleBox->addWidget(title);
    titleBox->addWidget(date);
    titleBox->addLayout(favBox);

    descr = new QTextEdit();
    descr->setPlaceholderText(QString("Description"));

    //img

    rt = new QLineEdit();
    QIntValidator * val = new QIntValidator();
    val->setBottom(0);
    rt->setValidator(val);
    rt->setPlaceholderText(QString("Running time"));

    ac = new QCheckBox("Audio compression");

    imgres= new QLineEdit();
    imgres->setPlaceholderText(QString("Image resolution"));

    frameps = new QLineEdit();
    frameps->setValidator(new QIntValidator());
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
    lowerButtonsBox = new QHBoxLayout;

    lowerButtonsBox->addWidget(add);
    lowerButtonsBox->addWidget(cancel);

    connect(add, SIGNAL(clicked()), this, SLOT(accept()));
    connect(cancel, SIGNAL(clicked()), this, SLOT(reject()));
    //----------------[]

    mainBox = new QVBoxLayout;
    mainBox->addWidget(upperRadioButtonsGroup);
    mainBox->addLayout(mainLayout);
    mainBox->addLayout(lowerButtonsBox);
    setLayout(mainBox);
}


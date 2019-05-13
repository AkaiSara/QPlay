#include "adddialog.h"

AddDialog::AddDialog(MainWidget* p): parent(p) {

    setWindowTitle("Inserisci elemento");

    //----------------[UpperRadioButtons]
    type1 = new QRadioButton(tr("&type1"));
    type2 = new QRadioButton(tr("type2"));
    type3 = new QRadioButton(tr("type3"));
    radioListBox = new QVBoxLayout; //contiene i radio buttons
    upperRadioButtonsGroup = new QGroupBox(tr("Seleziona il tipo")); //rende esclusivi tra loro i radio buttons

    type1->setChecked(true); //lo metto checked per far sì che sia cliccabile un solo bottone alla volta

    radioListBox->addWidget(type1);
    radioListBox->addWidget(type2);
    radioListBox->addWidget(type3);
    radioListBox->addStretch(1);
    upperRadioButtonsGroup->setLayout(radioListBox);
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
    mainBox->addLayout(lowerButtonsBox);
    setLayout(mainBox);
}


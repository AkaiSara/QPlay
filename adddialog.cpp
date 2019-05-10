#include "adddialog.h"

AddDialog::AddDialog(Widget* p): parent(p) {
    //setNomefinestra
    //Vlayout
        //createChooseType(); //type
        //sottooggetto
        //createButtons(); //add or cancel
    //show();

    setWindowTitle("Inserisci elemento");

    QPushButton *ok =new QPushButton("Ok");
    QPushButton *cancel =new QPushButton("Cancel");
    QHBoxLayout * hbox = new QHBoxLayout;

    hbox->addWidget(ok);
    hbox->addWidget(cancel);
    setLayout(hbox);

    connect(ok, SIGNAL(clicked()), this, SLOT(accept()));
    connect(cancel, SIGNAL(clicked()), this, SLOT(reject()));
}


void createChooseType(){}
void createButtons(){}

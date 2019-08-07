#include "audiovisualitem.h"

#include <QVBoxLayout>
#include <QLabel>

AudioVisualItem::AudioVisualItem(DeepPtr<AudioVisual> a, QWidget * p) :avPtr(a), parent(p) {
    displayWidget = new DisplayWidget(avPtr, this);
    //setMaximumSize(QSize(150,300));

    //----------------[immagine]
    /*
    auto path = "img/" + QString::fromStdString(avptr->getImg());

    if (!QFile::exists(path)) {
        path = ":/gui/img/av";
    }
    QLabel *img = new QLabel();
    img->setPixmap(QPixmap(path).scaled(200, 100, Qt::KeepAspectRatio));
    img->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
    img->setMaximumWidth(200);
    master->addWidget(img);
    */
    //----------------[]

    //----------------[titolo]
    QLabel *title = new QLabel(QString::fromStdString(avPtr->getTitle()));
    QFont f = title->font();
    //f.setBold(true);
    f.setPointSize(16);
    title->setFont(f);

    //----------------[]

    //tempo totale?

    //----------------[bottoni]
    deleteBtn = new QPushButton(tr("Elimina"));
    editBtn = new QPushButton(tr("Modifica"));
    QHBoxLayout * buttonsLayout = new QHBoxLayout;
    buttonsLayout->addWidget(editBtn);
    buttonsLayout->addWidget(deleteBtn);

    //----------------[]

    //----------------[Layout]
    QVBoxLayout * mainLayout = new QVBoxLayout;
    //immagine
    mainLayout->addWidget(title); //titolo
    mainLayout->addLayout(buttonsLayout); //bottoni
    setLayout(mainLayout);

    //----------------[]

    //----------------[Connect]
    connect(deleteBtn, &QPushButton::clicked, this, [this]() {emit deleteItem(avPtr); });
    //connect(this, SIGNAL(deleteItem(DeepPtr<AudioVisual>)), parent, SIGNAL(removeItem(DeepPtr<AudioVisual>)));

    connect(editBtn, &QPushButton::clicked, this, [this]() {emit modifyItem(avPtr); });
    //----------------[]

}

void AudioVisualItem::mouseDoubleClickEvent(QMouseEvent *event){
    displayWidget->show();
    QWidget::mouseDoubleClickEvent(event);
}

#include "audiovisualitem.h"

#include <QVBoxLayout>
#include <QLabel>

void AudioVisualItem::setLine(bool b){
    b? line->show() : line->hide();
}

DeepPtr<AudioVisual> AudioVisualItem::getAvPtr() const{
    return avPtr;
}

AudioVisualItem::AudioVisualItem(DeepPtr<AudioVisual> a, QWidget * p, QFrame * fr) :avPtr(a), parent(p), line(fr){
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
    connect(deleteBtn, &QPushButton::clicked, this, [this]() {emit deleteAnItem(avPtr); });
    connect(editBtn, &QPushButton::clicked, this, [this]() {emit editAnItem(avPtr); });
    //----------------[]

}

void AudioVisualItem::mouseDoubleClickEvent(QMouseEvent *event){
    displayWidget->show();
    QWidget::mouseDoubleClickEvent(event);
}

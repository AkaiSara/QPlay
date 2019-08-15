#include "audiovisualitem.h"

#include <QVBoxLayout>
#include <QLabel>
#include <QFile>

void AudioVisualItem::setLine(bool b){
    b? line->show() : line->hide();
}

QFrame* AudioVisualItem::getLine() const{
    return line;
}

AudioVisual *AudioVisualItem::getAvPtr() const{
    return &(*avPtr);
}

AudioVisualItem::AudioVisualItem(DeepPtr<AudioVisual> a, QWidget * p, QFrame * fr) :avPtr(a), parent(p), line(fr){
    displayWidget = new DisplayWidget(avPtr, this);
    //setMaximumSize(QSize(150,300));

    //----------------[immagine]

    QLabel * img = new QLabel;

    QString path = QString::fromStdString(avPtr->getPath());
    if (!QFile::exists(path)) {
        path = ":/img/picture";
    }
    img->setPixmap(QPixmap(path).scaled(200, 100, Qt::KeepAspectRatio));
    img->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
    img->setMaximumWidth(200);

    //----------------[]

    //----------------[titolo]
    QLabel *title = new QLabel(QString::fromStdString(avPtr->getTitle()));
    QFont f = title->font();
    //f.setBold(true);
    f.setPointSize(16);
    title->setFont(f);
    title->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);

    //----------------[]

    QLabel * totTime = new QLabel("Total time: " + QString::number(avPtr->getTotalRunningTime()) + "min");
    totTime->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);

    //----------------[bottoni]
    deleteBtn = new QPushButton(QIcon(":/img/remove"), tr("Elimina"));
    editBtn = new QPushButton(QIcon(":/img/edit"), tr("Modifica"));
    QHBoxLayout * buttonsLayout = new QHBoxLayout;
    buttonsLayout->addWidget(editBtn);
    buttonsLayout->addWidget(deleteBtn);

    //----------------[]

    //----------------[Layout]
    QVBoxLayout * mainLayout = new QVBoxLayout;
    mainLayout->addWidget(img);
    mainLayout->addWidget(title); //titolo
    mainLayout->addWidget(totTime);
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

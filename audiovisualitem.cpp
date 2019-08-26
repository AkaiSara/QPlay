#include "audiovisualitem.h"

void AudioVisualItem::setLine(bool b){
    b? line->show() : line->hide();
}

QFrame * AudioVisualItem::getLine() const{
    return line;
}

AudioVisual * AudioVisualItem::getAvPtr() const{
    return &(*avPtr);
}

AudioVisualItem::AudioVisualItem(const DeepPtr<AudioVisual> & a, QWidget * p, QFrame * fr) :avPtr(a), parent(p), line(fr){
    displayWidget = new DisplayWidget(avPtr, this);

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
    f.setPointSize(16);
    title->setFont(f);
    title->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);

    //----------------[]

    //----------------[Time]
    QLabel * totTime = new QLabel("Total time: " + (avPtr->getTotalRunningTime() / 60 != 0? QString::number(avPtr->getTotalRunningTime() / 60) + "h " : "") + QString::number(avPtr->getTotalRunningTime() % 60) + "min");
    totTime->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
    //----------------[]

    //----------------[bottoni]
    deleteBtn = new QPushButton(QIcon(":/img/remove"), tr(" &Delete"));
    editBtn = new QPushButton(QIcon(":/img/edit"), tr(" &Edit"));
    QHBoxLayout * buttonsLayout = new QHBoxLayout;
    buttonsLayout->addWidget(editBtn);
    buttonsLayout->addWidget(deleteBtn);

    //----------------[]

    //----------------[Layout]
    QVBoxLayout * mainLayout = new QVBoxLayout;
    mainLayout->addWidget(img);
    mainLayout->addWidget(title);
    mainLayout->addWidget(totTime);
    mainLayout->addLayout(buttonsLayout);

    QLabel * hint = new QLabel("Double click to see more..");
    QFont hintFont = hint->font();
    hintFont.setItalic(true);
    hintFont.setPixelSize(10);
    hint->setFont(hintFont);

    mainLayout->addWidget(hint);
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

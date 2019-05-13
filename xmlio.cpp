#include "xmlio.h"

#include <QFile>
#include <QSaveFile>
#include <QXmlStreamReader>
#include <QXmlStreamWriter>
#include <QDebug>

Xmlio::Xmlio(QString filepath) : filename(filepath) {}

Container<AudioVisual> Xmlio::read() const{
    Container<AudioVisual> list;

    /*QFile file(filename);
    if(!file.open(QIODevice::ReadOnly)) {
        qWarning() << "Non è stato possibile aprire il file" << file.errorString();
        return  list;
    }*/return list;

}

void Xmlio::write(const Container<AudioVisual> &) const{
     QSaveFile file(filename);

     if(!file.open(QIODevice::WriteOnly)) {
         throw std::exception();
         // NB: la cosa giusta da fare sarebbe creare un tipo eccezione. std::exception è troppo generica.
     }

      QXmlStreamWriter writer(&file);


}

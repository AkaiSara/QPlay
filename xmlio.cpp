#include "xmlio.h"

#include <QFile>
#include <QSaveFile>
#include <QXmlStreamReader>
#include <QXmlStreamWriter>
#include <QDebug>
#include <QMessageBox>

Xmlio::Xmlio(QString filepath) : filename(filepath) {}

Container<AudioVisual> Xmlio::read() const{
    Container<AudioVisual> list;

    QFile file(filename);
    if(!file.open(QIODevice::ReadOnly)) {
        QMessageBox box(QMessageBox::Warning, "Errore di apertura", "Non è stato possibile aprire il file", QMessageBox::Ok);
        qWarning() << "Non è stato possibile aprire il file" << file.errorString();
        return  list;
    }
    QXmlStreamReader reader(&file);
    if(reader.readNextStartElement()) {
        if(reader.name() == "root") {
            while(reader.readNextStartElement()) {
                try{list.push_back(AudioVisual::unserialize(reader));}
                catch(std::string s) {
                    QMessageBox box(QMessageBox::Warning, "Errore in lettura", "Qualche elemento potrebbe non essere stato letto correttamente", QMessageBox::Ok);
                }
            }
        }
    }
    file.close();
    return list;
}

void Xmlio::write(const Container<AudioVisual> & list) const {
     QSaveFile file(filename);

     if(!file.open(QIODevice::WriteOnly)) {
         throw std::exception();
         // NB: la cosa giusta da fare sarebbe creare un tipo eccezione. std::exception è troppo generica.
     }

     QXmlStreamWriter writer(&file);

     writer.setAutoFormatting(true);
     writer.writeStartDocument();
     writer.writeComment("File di salvataggio dell'applicazione. Non modificare a mano.");

     writer.writeStartElement("root");

     auto cit = list.begin();
     while(cit!= list.end()) {
         (*cit)->serialize(writer);
         ++cit;
     }
     writer.writeEndElement();                                        // </root>
     writer.writeEndDocument();
     file.commit();
}

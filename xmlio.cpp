#include "xmlio.h"
#include "documentary.h"
#include "movie.h"
#include "tvserie.h"

#include <QFile>
#include <QSaveFile>
#include <QXmlStreamReader>
#include <QXmlStreamWriter>
#include <QDebug>
#include <QMessageBox>

Xmlio::Xmlio(const std::string & filepath) : filename(filepath) {}

Container<AudioVisual> Xmlio::read() const{
    Container<AudioVisual> list;

    QFile file(QString::fromStdString(filename));

    if(!file.open(QIODevice::ReadOnly)) {
        QMessageBox box(QMessageBox::Warning, "Errore di apertura", "Non è stato possibile aprire il file", QMessageBox::Ok);
        qWarning() << "Non è stato possibile aprire il file" << file.errorString();
        return  list;
    } //non è stato possibile aprire il file

    //se viene aperto
    QXmlStreamReader input(&file);
    if(input.readNextStartElement()) {
        if(input.name() == "root") {
            while(input.readNextStartElement()) {
                if(input.name() == "Documentary") {
                    input.readNextStartElement();
                    std::string titolo = input.readElementText().toStdString();
                    input.readNextStartElement();
                    std::string descrizione = input.readElementText().toStdString();
                    input.readNextStartElement();
                    int anno = input.readElementText().toInt();
                    input.readNextStartElement();
                    std::string direttore = input.readElementText().toStdString();
                    input.readNextStartElement();
                    bool preferiti = input.readElementText() == "true"? true:false;
                    input.readNextStartElement();
                    int durata = input.readElementText().toInt();
                    input.readNextStartElement();
                    bool compressione = input.readElementText() == "true"? true:false;
                    input.readNextStartElement();
                    int risoluzione = input.readElementText().toInt();
                    input.readNextStartElement();
                    int frame = input.readElementText().toInt();
                    input.readNextStartElement();
                    //campi dati doc
                    std::string narratore = input.readElementText().toStdString();
                    input.readNextStartElement();
                    std::string argomento = input.readElementText().toStdString();
                    input.readNextStartElement();
                    list.push_back(Documentary(titolo, descrizione, anno, direttore, preferiti, durata, compressione, risoluzione, frame, narratore, argomento));
                    input.readNextStartElement();

                }else if (input.name() == "Movie") {
                    input.readNextStartElement();
                    std::string titolo = input.readElementText().toStdString();
                    input.readNextStartElement();
                    std::string descrizione = input.readElementText().toStdString();
                    input.readNextStartElement();
                    int anno = input.readElementText().toInt();
                    input.readNextStartElement();
                    std::string direttore = input.readElementText().toStdString();
                    input.readNextStartElement();
                    bool preferiti = input.readElementText() == "true"? true:false;
                    input.readNextStartElement();
                    int durata = input.readElementText().toInt();
                    input.readNextStartElement();
                    bool compressione = input.readElementText() == "true"? true:false;
                    input.readNextStartElement();
                    int risoluzione = input.readElementText().toInt();
                    input.readNextStartElement();
                    int frame = input.readElementText().toInt();
                    input.readNextStartElement();

                    //campidati film
                    std::string cast = input.readElementText().toStdString();
                    input.readNextStartElement();
                    std::string genere = input.readElementText().toStdString();
                    input.readNextStartElement();
                    std::string rating = input.readElementText().toStdString();
                    input.readNextStartElement();

                    list.push_back(Movie(titolo, descrizione, anno, direttore, preferiti, durata, compressione, risoluzione, frame, cast, genere, rating));
                    input.readNextStartElement();

                }else if (input.name() == "TvSerie") {
                    input.readNextStartElement();
                    std::string titolo = input.readElementText().toStdString();
                    input.readNextStartElement();
                    std::string descrizione = input.readElementText().toStdString();
                    input.readNextStartElement();
                    int anno = input.readElementText().toInt();
                    input.readNextStartElement();
                    std::string direttore = input.readElementText().toStdString();
                    input.readNextStartElement();
                    bool preferiti = input.readElementText() == "true"? true:false;
                    input.readNextStartElement();
                    int durata = input.readElementText().toInt();
                    input.readNextStartElement();
                    bool compressione = input.readElementText() == "true"? true:false;
                    input.readNextStartElement();
                    int risoluzione = input.readElementText().toInt();
                    input.readNextStartElement();
                    int frame = input.readElementText().toInt();
                    input.readNextStartElement();

                    //campi dati serie tv
                    int stagioni = input.readElementText().toInt();
                    input.readNextStartElement();
                    int episodi = input.readElementText().toInt();
                    input.readNextStartElement();
                    std::string cast = input.readElementText().toStdString();
                    input.readNextStartElement();
                    std::string genere = input.readElementText().toStdString();
                    input.readNextStartElement();
                    bool finita = input.readElementText() == "true"? true:false;
                    input.readNextStartElement();
                    std::string rating = input.readElementText().toStdString();
                    input.readNextStartElement();

                    list.push_back(TvSerie(titolo, descrizione, anno, direttore, preferiti, durata, compressione, risoluzione, frame, stagioni, episodi, cast, genere, finita, rating));
                    input.readNextStartElement();

                }
            }
        }
    }
    file.close();
    return list;
}

void Xmlio::write(const Container<AudioVisual> & list) const {
    QSaveFile file(QString::fromStdString(filename));

    if(!file.open(QIODevice::WriteOnly)) {
        throw std::exception();
    }

    QXmlStreamWriter output(&file);

    output.setAutoFormatting(true);
    output.writeStartDocument();
    output.writeComment("File di salvataggio dell'applicazione. Non modificare a mano.");
    output.writeStartElement("root"); //apre un tag Root
    if(!list.isEmpty())
        for(auto cit = list.cbegin(); cit != list.cend(); ++cit){
            if(dynamic_cast<Documentary*>(&(*cit))){
                const Documentary & doc = static_cast<Documentary &>(*cit);
                output.writeStartElement("Documentary");
                output.writeStartElement("Title");
                output.writeCharacters(QString::fromStdString(doc.getTitle()));
                output.writeEndElement();
                output.writeStartElement("Description");
                output.writeCharacters(QString::fromStdString(doc.getDescription()));
                output.writeEndElement();
                output.writeStartElement("ReleaseDate");
                output.writeCharacters(QString::number(doc.getRelease_date()));
                output.writeEndElement();
                output.writeStartElement("Director");
                output.writeCharacters(QString::fromStdString(doc.getDirector()));
                output.writeEndElement();
                output.writeStartElement("Favorite");
                output.writeCharacters(doc.isFavorite() ? "true": "false");
                output.writeEndElement();
                output.writeStartElement("Running time");
                output.writeCharacters(QString::number(doc.getRunning_time()));
                output.writeEndElement();
                output.writeStartElement("Audio compression");
                output.writeCharacters(doc.isAudioComp() ? "true": "false");
                output.writeEndElement();
                output.writeStartElement("Image resolution");
                output.writeCharacters(QString::number(doc.getImage_resolution()));
                output.writeEndElement();
                output.writeStartElement("Frame per sec");
                output.writeCharacters(QString::number(doc.getFps()));
                output.writeEndElement();

                output.writeStartElement("Narrator");
                output.writeCharacters(QString::fromStdString(doc.getNarrator()));
                output.writeEndElement();
                output.writeStartElement("Topic");
                output.writeCharacters(QString::fromStdString(doc.getTopic()));
                output.writeEndElement();

                output.writeEndElement();
            }
            else if(dynamic_cast<Movie*>(&(*cit))){
                const Movie & mov = static_cast<Movie &>(*cit);
                output.writeStartElement("Movie");

                output.writeStartElement("Title");
                output.writeCharacters(QString::fromStdString(mov.getTitle()));
                output.writeEndElement();
                output.writeStartElement("Description");
                output.writeCharacters(QString::fromStdString(mov.getDescription()));
                output.writeEndElement();
                output.writeStartElement("ReleaseDate");
                output.writeCharacters(QString::number(mov.getRelease_date()));
                output.writeEndElement();
                output.writeStartElement("Director");
                output.writeCharacters(QString::fromStdString(mov.getDirector()));
                output.writeEndElement();
                output.writeStartElement("Favorite");
                output.writeCharacters(mov.isFavorite() ? "true": "false");
                output.writeEndElement();
                output.writeStartElement("Running time");
                output.writeCharacters(QString::number(mov.getRunning_time()));
                output.writeEndElement();
                output.writeStartElement("Audio compression");
                output.writeCharacters(mov.isAudioComp() ? "true": "false");
                output.writeEndElement();
                output.writeStartElement("Image resolution");
                output.writeCharacters(QString::number(mov.getImage_resolution()));
                output.writeEndElement();
                output.writeStartElement("Frame per sec");
                output.writeCharacters(QString::number(mov.getFps()));
                output.writeEndElement();

                output.writeStartElement("Cast");
                output.writeCharacters(QString::fromStdString(mov.getCast()));
                output.writeEndElement();
                output.writeStartElement("Genre");
                output.writeCharacters(QString::fromStdString(mov.getGenre()));
                output.writeEndElement();
                output.writeStartElement("Rating");
                output.writeCharacters(QString::fromStdString(mov.getRating()));
                output.writeEndElement();

                output.writeEndElement();
            }
            else if(dynamic_cast<TvSerie*>(&(*cit))){
                const TvSerie & tvs = static_cast<TvSerie &>(*cit);
                output.writeStartElement("TvSerie");

                output.writeStartElement("Title");
                output.writeCharacters(QString::fromStdString(tvs.getTitle()));
                output.writeEndElement();
                output.writeStartElement("Description");
                output.writeCharacters(QString::fromStdString(tvs.getDescription()));
                output.writeEndElement();
                output.writeStartElement("ReleaseDate");
                output.writeCharacters(QString::number(tvs.getRelease_date()));
                output.writeEndElement();
                output.writeStartElement("Director");
                output.writeCharacters(QString::fromStdString(tvs.getDirector()));
                output.writeEndElement();
                output.writeStartElement("Favorite");
                output.writeCharacters(tvs.isFavorite() ? "true": "false");
                output.writeEndElement();
                output.writeStartElement("Running time");
                output.writeCharacters(QString::number(tvs.getRunning_time()));
                output.writeEndElement();
                output.writeStartElement("Audio compression");
                output.writeCharacters(tvs.isAudioComp() ? "true": "false");
                output.writeEndElement();
                output.writeStartElement("Image resolution");
                output.writeCharacters(QString::number(tvs.getImage_resolution()));
                output.writeEndElement();
                output.writeStartElement("Frame per sec");
                output.writeCharacters(QString::number(tvs.getFps()));
                output.writeEndElement();

                output.writeStartElement("Season");
                output.writeCharacters(QString::number(tvs.getSeason()));
                output.writeEndElement();
                output.writeStartElement("Episode");
                output.writeCharacters(QString::number(tvs.getEpisode()));
                output.writeEndElement();
                output.writeStartElement("Cast");
                output.writeCharacters(QString::fromStdString(tvs.getCast()));
                output.writeEndElement();
                output.writeStartElement("Genre");
                output.writeCharacters(QString::fromStdString(tvs.getGenre()));
                output.writeEndElement();
                output.writeStartElement("Ended");
                output.writeCharacters(tvs.isEnded() ? "true": "false");
                output.writeEndElement();
                output.writeStartElement("Rating");
                output.writeCharacters(QString::fromStdString(tvs.getRating()));
                output.writeEndElement();

                output.writeEndElement();
            }
        }
    output.writeEndElement();
    output.writeEndDocument();

    bool succes = file.commit();
    if(!succes)
        throw std::exception();
}

#ifndef XMLIO_H
#define XMLIO_H

#include "container.h"
#include "deepptr.h"
#include "audiovisual.h"
#include "documentary.h"
#include "movie.h"
#include "tvserie.h"

#include <QFile>
#include <QSaveFile>
#include <QXmlStreamReader>
#include <QXmlStreamWriter>
#include <QMessageBox>

class Xmlio {
private:
    std::string filename;
public:
    Xmlio(const std::string &);
    Container<DeepPtr<AudioVisual>> read() const;
    void write(const Container<DeepPtr<AudioVisual>> &) const;
};

#endif // XMLIO_H

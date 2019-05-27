#ifndef XMLIO_H
#define XMLIO_H

#include <QString>
#include "container.h"
#include "audiovisual.h"

class Xmlio {
private:
    QString filename;
public:
    Xmlio(QString);
    Container<AudioVisual> read() const;
    void write(const Container<AudioVisual> &) const;
};

#endif // XMLIO_H

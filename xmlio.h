#ifndef XMLIO_H
#define XMLIO_H

#include <QString>
#include "container.h"
#include "audiovisual.h"

class Xmlio {
private:
    std::string filename;
public:
    Xmlio(const std::string &);
    Container<AudioVisual> read() const;
    void write(const Container<AudioVisual> &) const;
};

#endif // XMLIO_H

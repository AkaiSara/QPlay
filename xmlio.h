#ifndef XMLIO_H
#define XMLIO_H

#include <QString>
#include "container.h"
#include "deepptr.h"

class Xmlio {
private:
    std::string filename;
public:
    Xmlio(const std::string &);
    Container<DeepPtr<AudioVisual>> read() const;
    void write(const Container<DeepPtr<AudioVisual>> &) const;
};

#endif // XMLIO_H

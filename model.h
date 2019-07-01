#ifndef MODEL_H
#define MODEL_H
#include "container.h"

class Model
{
private:
    Container<AudioVisual> list;
public:
    Model() = default;
    void save(const std::string &) const;
    void load(const std::string &);
    /* addAV, remove AV*/
};

#endif // MODEL_H

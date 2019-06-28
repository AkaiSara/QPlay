#ifndef MODEL_H
#define MODEL_H
#include "container.h"
#include "audiovisual.h"

class Model
{
private:
    Container<AudioVisual> list;
public:
    Model() = default;
    void save(const std::string &path) const;
    void load(const std::string &);
    /* addAV, remove AV*/
};

#endif // MODEL_H

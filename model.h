#ifndef MODEL_H
#define MODEL_H
#include "xmlio.h"
#include "deepptr.h"
#include "audiovisual.h"
#include <string>

class Model
{
private:
    Container<DeepPtr<AudioVisual>> list;
public:
    Model();
    ~Model();

    void save(const std::string &) const;
    void load(const std::string &);

    void add(const AudioVisual&);
    void remove();
    void clearAll();
    Container<DeepPtr<AudioVisual>> getList();
};

#endif // MODEL_H

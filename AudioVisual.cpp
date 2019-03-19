#include "AudioVisual.h"
#include <string>


AudioVisual::AudioVisual(std::string ti, std::string tr, unsigned int a, std::string r, std::string pr, bool f): title(ti), description(tr), release_date(a), director(r), producer(pr), favorite(f) {}

/*
bool AudioVisual::operator==(const AudioVisual& av){
    return (title == av.title) && (description == av.description) && (year == av.year);
}
bool AudioVisual::operator!=(const AudioVisual& av){
    return !(*this == av);
}
*/
std::string AudioVisual::getInfo() const {
            return title + ':' + description;
}

AudioVisual::~AudioVisual(){}

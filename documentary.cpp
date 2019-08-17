#include "documentary.h"

Documentary::Documentary(std::string ti, std::string tr, unsigned int rd, std::string r, bool f, std::string p, int rt , bool ac, unsigned int ir, unsigned int fp, std::string n, std::string ar): AudioVisual(ti,tr,rd,r,f,p,rt,ac,ir,fp), narrator(n), topic(ar) {}

bool Documentary::operator==(const AudioVisual& av) const{
    return AudioVisual::operator==(av) && narrator == static_cast<const Documentary &>(av).narrator && topic == static_cast<const Documentary &>(av).topic;
}



Documentary* Documentary::clone() const {
    return new Documentary(*this);
}

int Documentary::getTotalRunningTime() const{
    return running_time;
}
std::string Documentary::getType() const{
    return "Documentary";
}

bool Documentary::getQuality() const{
    return !audio_compression && (image_resolution>500? true : false) && (fps > 25? true: false);
}

bool Documentary::matureContent() const{
    return false;
}

Documentary::~Documentary() {}

std::string Documentary::getNarrator() const{
    return narrator;
}
std::string Documentary::getTopic() const{
    return topic;
}

void Documentary::setNarrator(std::string n){
    narrator = n;
}
void Documentary::setTopic(std::string t){
    topic = t;
}

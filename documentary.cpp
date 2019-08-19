#include "documentary.h"

Documentary::Documentary(const std::string & ti, const std::string & tr, unsigned int rd, const std::string & r, bool f, const std::string & p, unsigned int rt , bool ac, unsigned int ir, unsigned int fp, const std::string & n, const std::string & ar): AudioVisual(ti,tr,rd,r,f,p,rt,ac,ir,fp), narrator(n), topic(ar) {}

bool Documentary::operator==(const AudioVisual& av) const{
    return AudioVisual::operator==(av) && narrator == static_cast<const Documentary &>(av).narrator && topic == static_cast<const Documentary &>(av).topic;
}



Documentary* Documentary::clone() const {
    return new Documentary(*this);
}

unsigned int Documentary::getTotalRunningTime() const{
    return running_time;
}
std::string Documentary::getType() const{
    return "Documentary";
}

bool Documentary::isHighQuality() const{
    return (!audio_compression && image_resolution >= 480 && fps > 25);
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

void Documentary::setNarrator(const std::string & n){
    narrator = n;
}
void Documentary::setTopic(const std::string &t){
    topic = t;
}

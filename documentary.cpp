#include "documentary.h"
#include <string>

Documentary::Documentary(std::string ti, std::string tr, unsigned int rd, std::chrono::minutes rt ,std::string r, bool f, bool ac, unsigned int ir, unsigned int fp, std::string n, std::string ar): AudioVisual(ti,tr,rd,rt,r,f,ac,ir,fp), narrator(n), topic(ar) {}

Documentary* Documentary::clone() const {
    return new Documentary(*this);
}

std::chrono::minutes Documentary::getTotalRunningTime() const{
    return running_time;
}
std::string Documentary::getType() const{
    return "Documentary";
}

bool Documentary::getQuality() const{
    return audio_compression && (image_resolution>500? true : false) && (fps > 25? true: false);
}

bool Documentary::matureContent() const{
    return false;
}

bool Documentary::operator==(const AudioVisual& av) const{
    return AudioVisual::operator==(av) && narrator == static_cast<const Documentary &>(av).narrator && topic == static_cast<const Documentary &>(av).topic;
}

Documentary::~Documentary() {}

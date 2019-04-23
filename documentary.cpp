#include "documentary.h"
#include <string>

Documentary::Documentary(std::string ti, std::string tr, unsigned int a, std::string re, bool p, std::string n, std::string ar): AudioVisual(ti,tr,a,re,p), narrator(n), topic(ar) {}

Documentary* Documentary::clone() const {
    return new Documentary(*this);
}

Documentary::~Documentary() {}

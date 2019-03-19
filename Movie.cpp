#include "Movie.h"

Movie::Movie(std::string ti, std::string tr, unsigned int a, std::string re, std::string pr, bool p, std::string ca, Genre g, Rating ra, bool co):  AudioVisual(ti,tr,a,re,pr,p), cast(ca), genre(g), rating(ra), collezione(co) {}

Movie* Movie::clone() const {
    return new Movie(*this);
}

Movie::~Movie() {}

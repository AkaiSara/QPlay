#include "TVSerie.h"
#include <string>

TvSerie::TvSerie(std::string ti, std::string tr, unsigned int a, std::string re, std::string pr, bool p, unsigned int st, unsigned int ep, std::string ca, Genre g, bool ic, Rating ra): AudioVisual(ti,tr,a,re,pr,p), season(st), episode(ep), cast(ca), genre(g), ended(ic), rating(ra) {}

TvSerie* TvSerie::clone() const {
    return new TvSerie(*this);
}

TvSerie::~TvSerie() {}

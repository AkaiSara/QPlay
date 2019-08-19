#include "tvserie.h"

TvSerie::TvSerie(const std::string & ti, const std::string & tr, unsigned int rd, const std::string & r, bool f, const std::string & p, unsigned int rt, bool ac, unsigned int ir, unsigned int fp, unsigned int st, unsigned int ep, const std::string & ca, const std::string & g, bool ic, const std::string & ra): AudioVisual(ti,tr,rd,r,f,p,rt,ac,ir,fp), season(st), episode(ep), cast(ca), genre(g), ended(ic), rating(ra) {}

bool TvSerie::operator==(const AudioVisual& av) const{
    return AudioVisual::operator==(av) &&
            season == static_cast<const TvSerie &>(av).season &&
            episode == static_cast<const TvSerie &>(av).episode &&
            cast == static_cast<const TvSerie &>(av).cast &&
            genre == static_cast<const TvSerie &>(av).genre &&
            ended == static_cast<const TvSerie &>(av).ended &&
            rating == static_cast<const TvSerie &>(av).rating;
}

TvSerie* TvSerie::clone() const {
    return new TvSerie(*this);
}

unsigned int TvSerie::getTotalRunningTime() const{
    return (running_time * episode * season);
}
std::string TvSerie::getType() const{
    return "TvSerie";
}

bool TvSerie::isHighQuality() const{
    return (!audio_compression && image_resolution >= 720 && fps >= 30);
}

bool TvSerie::matureContent() const{
    return (rating == "VM18" || ((genre == "Crime" || genre == "Horror" || genre == "Thriller") && rating == "VM18"));
}

TvSerie::~TvSerie() {}

std::string TvSerie::getCast() const{
    return cast;
}
std::string TvSerie::getGenre() const{
    return genre;
}
std::string TvSerie::getRating() const{
    return rating;
}

bool TvSerie::isEnded() const{
    return ended;
}
unsigned int TvSerie::getSeason() const{
    return season;
}
unsigned int TvSerie::getEpisode() const{
    return episode;
}

void TvSerie::setCast(const std::string &c){
    cast = c;
}
void TvSerie::setRating(const std::string &r){
    rating = r;
}
void TvSerie::setGenre(const std::string &g){
    genre = g;
}
void TvSerie::setEnded(bool e){
    ended = e;
}
void TvSerie::setSeason(unsigned int s){
    season = s;
}
void TvSerie::setEpisode(unsigned int e){
    episode = e;
}

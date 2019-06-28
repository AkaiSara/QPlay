#include "tvserie.h"
#include <string>

TvSerie::TvSerie(std::string ti, std::string tr, unsigned int rd, std::string r, bool f, int rt, bool ac, unsigned int ir, unsigned int fp, unsigned int st, unsigned int ep, std::string ca, Genre g, bool ic, Rating ra): AudioVisual(ti,tr,rd,r,f,rt,ac,ir,fp), season(st), episode(ep), cast(ca), genre(g), ended(ic), rating(ra) {}

TvSerie* TvSerie::clone() const {
    return new TvSerie(*this);
}

int TvSerie::getTotalRunningTime() const{
    return (running_time * static_cast<int>(episode)); //episode * season
}
std::string TvSerie::getType() const{
    return "TvSerie";
}

bool TvSerie::getQuality() const{
    return audio_compression && (image_resolution>500? true : false) && (fps > 25? true: false);
}

bool TvSerie::matureContent() const{
    return (rating == VM18? true : false) && (genre == Crime || genre == Horror ? true : false);
}

bool TvSerie::operator==(const AudioVisual& av) const{
    return AudioVisual::operator==(av) &&
            season == static_cast<const TvSerie &>(av).season &&
            episode == static_cast<const TvSerie &>(av).episode &&
            cast == static_cast<const TvSerie &>(av).cast &&
            genre == static_cast<const TvSerie &>(av).genre &&
            ended == static_cast<const TvSerie &>(av).ended &&
            rating == static_cast<const TvSerie &>(av).rating;
}

TvSerie::~TvSerie() {}

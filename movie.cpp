#include "movie.h"

Movie::Movie(std::string ti, std::string tr, unsigned int rd, std::string r, bool f, int rt , bool ac, unsigned int ir, unsigned int fp, std::string ca, Genre g, Rating ra):  AudioVisual(ti,tr,rd,r,f,rt,ac,ir,fp), cast(ca), genre(g), rating(ra) {}

Movie* Movie::clone() const {
    return new Movie(*this);
}

int Movie::getTotalRunningTime() const{
    return running_time;
}
std::string Movie::getType() const{
    return "Movie";
}

bool Movie::getQuality() const{
    return audio_compression && (image_resolution>500? true : false) && (fps > 25? true: false);
}

bool Movie::matureContent() const{
    return (rating == VM18? true : false) && (genre == Crime || genre == Horror ? true : false);
}

bool Movie::operator==(const AudioVisual& av) const{
    return AudioVisual::operator==(av) &&
            cast == static_cast<const Movie &>(av).cast &&
            genre == static_cast<const Movie &>(av).genre &&
            rating == static_cast<const Movie &>(av).rating;
}

Movie::~Movie() {}

#include "movie.h"

Movie::Movie(std::string ti, std::string tr, unsigned int rd, std::string r, bool f, std::string p, unsigned int rt , bool ac, unsigned int ir, unsigned int fp, std::string ca, std::string g, std::string ra):  AudioVisual(ti,tr,rd,r,f,p,rt,ac,ir,fp), cast(ca), genre(g), rating(ra) {}

bool Movie::operator==(const AudioVisual& av) const{
    return AudioVisual::operator==(av) &&
            cast == static_cast<const Movie &>(av).cast &&
            genre == static_cast<const Movie &>(av).genre &&
            rating == static_cast<const Movie &>(av).rating;
}


Movie* Movie::clone() const {
    return new Movie(*this);
}

unsigned int Movie::getTotalRunningTime() const{
    return running_time;
}
std::string Movie::getType() const{
    return "Movie";
}

bool Movie::getQuality() const{
    return !audio_compression && (image_resolution>500? true : false) && (fps > 25? true: false);
}

bool Movie::matureContent() const{
    return ((rating == "VM18"? true : false) && (genre == "Crime" || genre == "Horror" ? true : false)) || (rating == "VM18"? true : false);
}

Movie::~Movie() {}

std::string Movie::getCast() const{
    return cast;
}
std::string Movie::getGenre() const{
    return genre;
}
std::string Movie::getRating() const{
    return rating;
}

void Movie::setCast(std::string c){
    cast = c;
}
void Movie::setRating(std::string r){
    rating = r;
}
void Movie::setGenre(std::string g){
    genre = g;
}

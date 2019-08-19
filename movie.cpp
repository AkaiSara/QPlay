#include "movie.h"

Movie::Movie(const std::string & ti, const std::string & tr, unsigned int rd, const std::string & r, bool f, const std::string & p, unsigned int rt , bool ac, unsigned int ir, unsigned int fp, const std::string & ca, const std::string & g, const std::string & ra):  AudioVisual(ti,tr,rd,r,f,p,rt,ac,ir,fp), cast(ca), genre(g), rating(ra) {}

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

bool Movie::isHighQuality() const{
    return (!audio_compression && image_resolution >= 1080 && fps > 40);
}

bool Movie::matureContent() const{
    return ((rating == "VM18" && (genre == "Crime" || genre == "Horror")) || rating == "VM18");
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

void Movie::setCast(const std::string &c){
    cast = c;
}
void Movie::setRating(const std::string &r){
    rating = r;
}
void Movie::setGenre(const std::string &g){
    genre = g;
}

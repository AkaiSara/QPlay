#include "audiovisual.h"

const std::vector<std::string> AudioVisual::Rating = {"All", "VM14", "VM18"};

const std::vector<std::string> AudioVisual::Genre = {"Unknown", "Action", "Adventure", "Animation", "Comedy", "Crime", "Drama", "Fantasy", "Food", "Game show", "Horror", "Mystery", "Reality", "Romance", "Science fiction", "Soap", "Sport", "Talk show", "Thriller", "Travel", "Western"};

AudioVisual::AudioVisual(std::string ti, std::string tr, unsigned int rd, std::string r, bool f, std::string p, int rt, bool ac, unsigned int ir, unsigned int fp): title(ti), description(tr), release_date(rd), director(r), favorite(f), pathImg(p), running_time(rt), audio_compression(ac), image_resolution(ir), fps(fp) {}

AudioVisual::~AudioVisual(){}

bool AudioVisual::operator==(const AudioVisual& av) const{
    return getType() == av.getType() &&
            title == av.title &&
            description == av.description &&
            release_date == av.release_date &&
            running_time == av.running_time &&
            director == av.director &&
            pathImg == av.pathImg &&
            favorite == av.favorite &&
            audio_compression == av.audio_compression &&
            image_resolution == av.image_resolution &&
            fps == av.fps;
}
bool AudioVisual::operator!=(const AudioVisual& av) const{
    return !(*this == av);
}

/* ------ Getter & Setter ------ */

bool AudioVisual::isFavorite() const{
    return favorite;
}
std::string AudioVisual::getPath() const{
    return pathImg;
}

std::string AudioVisual::getTitle() const{
    return title;
}

std::string AudioVisual::getDescription() const{
    return description;
}
unsigned int AudioVisual::getRelease_date() const{
    return release_date;
}
std::string AudioVisual::getDirector() const{
    return director;
}
int AudioVisual::getRunning_time() const{
return running_time;
}
bool AudioVisual::isAudioComp() const{
    return audio_compression;
}
unsigned int AudioVisual::getImage_resolution() const{
    return image_resolution;
}
unsigned int AudioVisual::getFps() const{
    return fps;
}

void AudioVisual::setFavorite(const bool f){
    favorite = f;
}
void AudioVisual::setPath(const std::string & p){
    pathImg = p;
}
void AudioVisual::setTitle(const std::string & t){
    title = t;
}
void AudioVisual::setDescription(const std::string & d){
    description = d;
}
void AudioVisual::setRelease_date(const unsigned int d){
    release_date = d;
}
void AudioVisual::setDirector(const std::string & d){
    director = d;
}
void AudioVisual::setRunning_time(const int t){
    running_time = t;
}
void AudioVisual::setAudioComp(const bool a){
    audio_compression = a;
}
void AudioVisual::setImage_resolution(const unsigned int r){
    image_resolution = r;
}
void AudioVisual::setFps(const unsigned int f){
    fps = f;
}

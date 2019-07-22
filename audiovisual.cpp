#include "audiovisual.h"

const std::vector<std::string> AudioVisual::Rating = {"VM14", "VM18", "All"};

const std::vector<std::string> AudioVisual::Genre = {"Action", "Adventure", "Animation", "Comedy", "Crime", "Drama", "Fantasy", "Food", "Game show", "Horror", "Mystery", "Reality", "Romance", "Science fiction", "Soap", "Sport", "Talk show", "Thriller", "Travel", "Unknown", "Western"};

AudioVisual::AudioVisual(std::string ti, std::string tr, unsigned int rd, std::string r, bool f, int rt, bool ac, unsigned int ir, unsigned int fp): title(ti), description(tr), release_date(rd), director(r), favorite(f), running_time(rt), audio_compression(ac), image_resolution(ir), fps(fp) {}

bool AudioVisual::operator==(const AudioVisual& av) const{
    return getType() == av.getType() &&
            title == av.title &&
            description == av.description &&
            release_date == av.release_date &&
            running_time == av.running_time &&
            director == av.director &&
            favorite == av.favorite &&
            audio_compression == av.audio_compression &&
            image_resolution == av.image_resolution &&
            fps == av.fps;
}
bool AudioVisual::operator!=(const AudioVisual& av) const{
    return !(*this == av);
}

bool AudioVisual::isFavorite() const{
    return favorite;
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

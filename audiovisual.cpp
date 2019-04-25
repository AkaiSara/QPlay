#include "audiovisual.h"
#include <string>

AudioVisual::AudioVisual(std::string ti, std::string tr, unsigned int rd, std::chrono::minutes rt ,std::string r, bool f, bool ac, unsigned int ir, unsigned int fp): title(ti), description(tr), release_date(rd), running_time(rt), director(r), favorite(f), audio_compression(ac), image_resolution(ir), fps(fp) {}

bool AudioVisual::operator==(const AudioVisual& av) const{
    return getType() == av.getType() && title == av.title && description == av.description && release_date == av.release_date && running_time == av.running_time && director == av.director && favorite == av.favorite && audio_compression == av.audio_compression && image_resolution == av.image_resolution && fps == av.fps;
}
bool AudioVisual::operator!=(const AudioVisual& av) const{
    return !(*this == av);
}

bool AudioVisual::isFavorite() const{
    return favorite;
}

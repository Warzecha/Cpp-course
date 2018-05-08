//
// Created by damian on 07.05.18.
//

#ifndef JIMP_EXERCISES_MOVIESUBTITLES_H
#define JIMP_EXERCISES_MOVIESUBTITLES_H


#include <ostream>
#include <regex>

namespace moviesubs
{
    class MovieSubtitles {

        virtual void ShiftAllSubtitlesBy(int offset_in_micro_seconds, int frame_per_second, std::istream *in, std::ostream *out) = 0;

    };



    class MicroDvdSubtitles : public MovieSubtitles
    {

        void ShiftAllSubtitlesBy(int offset_in_micro_seconds, int frame_per_second, std::istream *in, std::ostream *out) override ;

    };


    class SubRipSubtitles : public MovieSubtitles
    {

        void ShiftAllSubtitlesBy(int offset_in_micro_seconds, int frame_per_second, std::istream *in, std::ostream *out) override ;

    };



}




#endif //JIMP_EXERCISES_MOVIESUBTITLES_H

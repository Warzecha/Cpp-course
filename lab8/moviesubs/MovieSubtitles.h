//
// Created by damian on 07.05.18.
//

#ifndef JIMP_EXERCISES_MOVIESUBTITLES_H
#define JIMP_EXERCISES_MOVIESUBTITLES_H


#include <ostream>
#include <regex>
#include <exception>


namespace moviesubs
{
    class MovieSubtitles {
    public:
        virtual void ShiftAllSubtitlesBy(int offset_in_micro_seconds, int frame_per_second, std::istream *in, std::ostream *out) = 0;

    };



    class MicroDvdSubtitles : public MovieSubtitles
    {
    public:
        void ShiftAllSubtitlesBy(int offset_in_micro_seconds, int frame_per_second, std::istream *in, std::ostream *out) override ;

    };


    class SubRipSubtitles : public MovieSubtitles
    {
    public:
        void ShiftAllSubtitlesBy(int offset_in_micro_seconds, int frame_per_second, std::istream *in, std::ostream *out) override ;

    };

    class SubtitlesException : public std::invalid_argument
    {
    public:
        SubtitlesException(const std::string &__arg, int invalied_line);

        int LineAt() const ;


    private:
        int invalied_line;



    };


    class NegativeFrameAfterShift : public SubtitlesException
    {
    public:
        NegativeFrameAfterShift(const std::string &__arg, int invalied_line);





    };

    class SubtitleEndBeforeStart : public SubtitlesException
    {
    public:
        SubtitleEndBeforeStart(const std::string &__arg, int invalied_line);




    };

    class InvalidSubtitleLineFormat : public SubtitlesException
    {
    public:
        InvalidSubtitleLineFormat(const std::string &__arg, int invalied_line);


    };

    class OutOfOrderFrames : public SubtitlesException
    {
    public:
        OutOfOrderFrames(const std::string &__arg, int invalied_line);


    };

    class MissingTimeSpecification : public SubtitlesException
    {
    public:
        MissingTimeSpecification(const std::string &__arg, int invalied_line);


    };


}




#endif //JIMP_EXERCISES_MOVIESUBTITLES_H

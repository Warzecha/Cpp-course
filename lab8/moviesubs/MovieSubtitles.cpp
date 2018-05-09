//
// Created by damian on 07.05.18.
//

#include <iostream>
#include <iomanip>
#include "MovieSubtitles.h"


namespace moviesubs
{


    void MicroDvdSubtitles::ShiftAllSubtitlesBy(int offset_in_micro_seconds, int frame_per_second, std::istream *in,
                                                std::ostream *out) {

        std::regex MicroDvdExpression("^\\{(\\d+)\\}\\{(\\d+)}(.*)");

        std::cmatch m;

        std::string line;

        int line_number = 0;
        if(frame_per_second <= 0)
        {
            throw (SubtitlesException("Illegal framerate", line_number));

        }

        while(std::getline( *in, line ))
        {
            line_number++;





            if(std::regex_match(line.c_str(), m, MicroDvdExpression))
            {

                int start_frame = std::stoi(m[1].str());
                int stop_frame = std::stoi(m[2].str());


                if(start_frame > stop_frame)
                {
                    throw(SubtitleEndBeforeStart("At line " + std::to_string(2) + ": " + line, line_number));
                }

                int shift = offset_in_micro_seconds * frame_per_second / 1000;

                start_frame += shift;
                stop_frame += shift;

                if (start_frame < 0)
                {
                    throw(NegativeFrameAfterShift("Negative frames after shift", line_number));
                }

                std::string shifted_line = "{" + std::to_string(start_frame) + "}{" + std::to_string(stop_frame) + "}" + m[3].str();

                *out << shifted_line << std::endl;


            }
            else
            {
                throw(InvalidSubtitleLineFormat("Invalid line format",line_number));

            }

        }


    }


    SubtitlesException::SubtitlesException(const std::string &__arg, int invalied_line) : invalid_argument(__arg),
                                                                                          invalied_line(
                                                                                                  invalied_line) {}

    int SubtitlesException::LineAt() const {
        return invalied_line;
    }

    NegativeFrameAfterShift::NegativeFrameAfterShift(const std::string &__arg, int invalied_line) : SubtitlesException(
            __arg, invalied_line) {}

    SubtitleEndBeforeStart::SubtitleEndBeforeStart(const std::string &__arg, int invalied_line) : SubtitlesException(
            __arg, invalied_line) {}

    InvalidSubtitleLineFormat::InvalidSubtitleLineFormat(const std::string &__arg, int invalied_line)
            : SubtitlesException(__arg, invalied_line) {}

    void SubRipSubtitles::ShiftAllSubtitlesBy(int offset_in_micro_seconds, int frame_per_second, std::istream *in,
                                              std::ostream *out) {


        std::regex SubRipTimeExpression("^(\\d\\d):(\\d\\d):(\\d\\d),(\\d\\d\\d) --> (\\d\\d):(\\d\\d):(\\d\\d),(\\d\\d\\d)$");

        std::cmatch m;

        std::string line;
        std::string line_with_number;
        std::string line_with_time;
        std::string text_line;

        int frame_number = 0;
        if(frame_per_second <= 0)
        {
            throw (SubtitlesException("Illegal framerate", frame_number));

        }

        while(std::getline( *in, line ))
        {

            frame_number++;

            if(std::stoi(line) != frame_number)
            {
                throw(OutOfOrderFrames("Frames out of order", frame_number));
            }

            *out << line << std::endl;

            std::getline( *in, line );




            if(std::regex_match(line.c_str(), m, SubRipTimeExpression))
            {

                int start_frame_hour = std::stoi(m[1].str());
                int start_frame_minute = std::stoi(m[2].str());
                int start_frame_second = std::stoi(m[3].str());
                int start_frame_milisecond = std::stoi(m[4].str());

                int stop_frame_hour = std::stoi(m[5].str());
                int stop_frame_minute = std::stoi(m[6].str());
                int stop_frame_second = std::stoi(m[7].str());
                int stop_frame_milisecond = std::stoi(m[8].str());


                int total_start_frame_miliseconds = start_frame_hour * 3600000 + start_frame_minute * 60000 + start_frame_second * 1000 + start_frame_milisecond;


                int total_stop_frame_miliseconds = stop_frame_hour * 3600000 + stop_frame_minute * 60000 + stop_frame_second * 1000 + stop_frame_milisecond;


                if(total_start_frame_miliseconds > total_stop_frame_miliseconds)
                {
                    throw(SubtitleEndBeforeStart("At line " + std::to_string(frame_number) +": " + line, frame_number));
                }

                int shift = offset_in_micro_seconds;

                total_start_frame_miliseconds += shift;
                total_stop_frame_miliseconds += shift;

                if (total_start_frame_miliseconds < 0)
                {
                    //throw(MissingTimeSpecification("Missing time specification", line_number));
                    throw(NegativeFrameAfterShift("Negative frames after shift", frame_number));
                }


                start_frame_hour = total_start_frame_miliseconds / 3600000;
                total_start_frame_miliseconds = total_start_frame_miliseconds % 3600000;
                start_frame_minute = total_start_frame_miliseconds / 60000;
                total_start_frame_miliseconds = total_start_frame_miliseconds % 60000;
                start_frame_second = total_start_frame_miliseconds / 1000;
                start_frame_milisecond = total_start_frame_miliseconds % 1000 ;



                stop_frame_hour = total_stop_frame_miliseconds / 3600000;
                total_stop_frame_miliseconds = total_stop_frame_miliseconds % 3600000;
                stop_frame_minute = total_stop_frame_miliseconds / 60000;
                total_stop_frame_miliseconds = total_stop_frame_miliseconds % 60000;
                stop_frame_second = total_stop_frame_miliseconds / 1000;
                stop_frame_milisecond = total_stop_frame_miliseconds % 1000 ;





                *out << std::setw(2) << std::setfill('0') << start_frame_hour << ":" << std::setw(2) << std::setfill('0') << start_frame_minute << ":" << std::setw(2) << std::setfill('0') << start_frame_second << "," << std::setw(3) << std::setfill('0') <<start_frame_milisecond;
                *out << " --> ";
                *out << std::setw(2) << std::setfill('0') << stop_frame_hour << ":" << std::setw(2) << std::setfill('0') << stop_frame_minute << ":" << std::setw(2) << std::setfill('0') << stop_frame_second << "," << std::setw(3) << std::setfill('0') <<stop_frame_milisecond;
                *out << std::endl;


                while(std::getline( *in, line ) && !line.empty())
                {
                    *out << line << std::endl;


                }

                *out << std::endl;





            }
            else
            {
                //throw(MissingTimeSpecification("Missing time specification", line_number));
                throw(InvalidSubtitleLineFormat("Invalid line format",frame_number));

            }

        }


    }

    OutOfOrderFrames::OutOfOrderFrames(const std::string &__arg, int invalied_line) : SubtitlesException(__arg,
                                                                                                         invalied_line) {}

    MissingTimeSpecification::MissingTimeSpecification(const std::string &__arg, int invalied_line)
            : SubtitlesException(__arg, invalied_line) {}
}
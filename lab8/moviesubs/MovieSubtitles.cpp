//
// Created by damian on 07.05.18.
//

#include "MovieSubtitles.h"


namespace moviesubs
{


    void MicroDvdSubtitles::ShiftAllSubtitlesBy(int offset_in_micro_seconds, int frame_per_second, std::istream *in,
                                                std::ostream *out) {

        std::regex MicroDvdExpression("^\\{(\\d+)\\}\\{(\\d+)}(.*)");

        std::cmatch m;

        std::string line;


        while(std::getline( *in, line ))
        {
            if(std::regex_match(line.c_str(), m, MicroDvdExpression))
            {

                int start_frame = std::stoi(m[1].str());
                int stop_frame = std::stoi(m[2].str());

                int shift = offset_in_micro_seconds * frame_per_second / 1000;

                std::string shifted_line = "{" + std::to_string(start_frame + shift) + "}{" + std::to_string(stop_frame + shift) + "}" + m[3].str();



            }

        }


    }
}
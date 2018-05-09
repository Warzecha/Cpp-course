//
// Created by damian on 07.05.18.
//

#include <iostream>
#include <MovieSubtitles.h>
#include <memory>
#include <sstream>


int main()
{


    auto subs = std::make_unique<moviesubs::SubRipSubtitles>();
    std::stringstream in {"1\n00:00:00,000 --> 00:00:00,100\nText\n\n2\n00:00:00,100 --> 00:00:00,200\nNEWLINE\n"};
    std::stringstream out;
    subs->ShiftAllSubtitlesBy(1, 25, &in, &out);

    std::cout << in.str() << std::endl;

    std::cout << out.str() << std::endl;






}
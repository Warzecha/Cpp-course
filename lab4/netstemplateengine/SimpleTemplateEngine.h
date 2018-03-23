//
// Created by damian on 20.03.18.
//

#ifndef JIMP_EXERCISES_SIMPLETEMPLATEENGINE_H
#define JIMP_EXERCISES_SIMPLETEMPLATEENGINE_H

#include <string>
#include <unordered_map>
#include <regex>

namespace nets {

    class View {
    public:


        View(const std::string &object_template);

        std::string Render(const std::unordered_map <std::string, std::string> &model) const;

        const std::string &getObject_template() const;

    private:
        std::string object_template;




    };

}


#endif //JIMP_EXERCISES_SIMPLETEMPLATEENGINE_H

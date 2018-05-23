//
// Created by damian on 23.05.18.
//

#include "Algo.h"
#include <algorithm>
#include <iostream>

namespace algo
{




    void CopyInto(const std::vector<int> &v, int n_elements, std::vector<int> *out) {
        std::copy_n(v.begin(), n_elements, std::back_inserter(*out));
    }

    bool Contains(const std::vector<int> &v, int element) {
        return std::find(v.begin(), v.end(), element) != v.end();
    }

    void InitializeWith(int initial_value, std::vector<int> *v) {

        std::fill(v->begin(), v->end(), initial_value);

    }

    std::vector<int> InitializedVectorOfLength(int length, int initial_value) {
        std::vector<int> to_return (length);

        std::fill(to_return.begin(),to_return.end(),initial_value);

        return to_return;
    }

    std::vector<std::string> MapToString(const std::vector<double> &v) {
        std::vector<std::string> to_return;

        std::transform(v.begin(),v.end(),std::back_inserter(to_return),[](double d) -> std::string { return std::to_string(d); });

        return to_return;
    }

    std::set<std::string> Keys(const std::map<std::string, int> &m) {
        std::set<std::string> to_return;

        std::transform(m.begin(),m.end(),std::inserter(to_return, to_return.begin()),[](std::pair<std::string, int> pair) -> std::string { return pair.first; });
        return to_return;
    }

    std::vector<int> Values(const std::map<std::string, int> &m) {
        std::vector<int > to_return;

        std::transform(m.begin(),m.end(),std::back_inserter(to_return),[](std::pair<std::string, int> pair) -> int { return pair.second; });
        return to_return;
    }

    bool ContainsKey(const std::map<std::string, int> &v, const std::string &key) {

        return v.find(key) != v.end();
    }

    bool ContainsValue(const std::map<std::string, int> &v, int value) {
        return std::find_if(v.begin(),v.end(),[value](std::pair<std::string, int> pair) -> bool { return pair.second == value;}) != v.end();
    }

    std::vector<int> DivisableBy(const std::vector<int> &v, int divisor) {
        std::vector<int> to_return;

        std::copy_if(v.begin(),v.end(),std::back_inserter(to_return),[divisor](int x) -> bool { return x % divisor == 0; });

        return to_return;
    }
}
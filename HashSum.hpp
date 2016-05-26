//
// Created by khang on 26/05/2016.
//

#ifndef ASSIGNMENT_CPP_HASHSUM_HPP
#define ASSIGNMENT_CPP_HASHSUM_HPP

#include <string>

using namespace std;

namespace Hash {
    //Prime numbers
#define A 76963
#define B 86969

    unsigned hashSum(string s);

    bool checkHashCode(string s, unsigned code);
}

#endif //ASSIGNMENT_CPP_HASHSUM_HPP

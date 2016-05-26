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

    unsigned hashSum(string s) {
        unsigned hashCode = 51;
        for (int i = 0; i < s.length(); i++)
            hashCode = (hashCode * A) ^ (s[i] * B);
        return hashCode;
    }

    bool checkHashCode(string s, unsigned code) {
        unsigned sHashCode = hashSum(s);
        return sHashCode == code;
    }
}

#endif //ASSIGNMENT_CPP_HASHSUM_HPP

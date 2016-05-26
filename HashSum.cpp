//
// Created by root on 27/05/2016.
//

#include "HashSum.hpp"

unsigned Hash::hashSum(string s) {
    unsigned hashCode = 51;
    for (int i = 0; i < s.length(); i++)
        hashCode = (hashCode * A) ^ (s[i] * B);
    return hashCode;
}

bool ::Hash::checkHashCode(string s, unsigned code) {
    unsigned sHashCode = hashSum(s);
    return sHashCode == code;
}

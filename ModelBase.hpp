//
// Created by khang on 26/05/2016.
//

#ifndef ASSIGNMENT_CPP_MODELBASE_HPP
#define ASSIGNMENT_CPP_MODELBASE_HPP

#include "json.hpp"

using json = nlohmann::json;

class ModelBase {
public:
    ModelBase(json j) { };

    virtual json toJson() {
        return {};
    }
};


#endif //ASSIGNMENT_CPP_MODELBASE_HPP

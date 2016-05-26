//
// Created by khang on 26/05/2016.
//

#ifndef ASSIGNMENT_CPP_IOHELPER_HPP
#define ASSIGNMENT_CPP_IOHELPER_HPP

#include <iostream>
#include "ModelBase.hpp"

using namespace std;

template<typename T, typename = typename std::enable_if<std::is_base_of<ModelBase, T>::value, T>::type>
class IOHelper<T> {
public:
    static void print(ostream &stream, vector<T *> dataList) {
        json jDataList;
        for (int i = 0; i < dataList.size(); i++)
            jDataList.push_back(dataList[i]->toJson());
        string jsonStringNormal = jDataList.dump();
        unsigned hashCode = hashSum(jsonStringNormal);

        json jObject = json({
                                    {"data", jDataList},
                                    {"code", hashCode}
                            });
        stream << setw(4) << jObject;
    }

};


#endif //ASSIGNMENT_CPP_IOHELPER_HPP

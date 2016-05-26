//
// Created by khang on 26/05/2016.
//

#ifndef ASSIGNMENT_CPP_IOHELPER_HPP
#define ASSIGNMENT_CPP_IOHELPER_HPP

#include <iostream>
#include "ModelBase.hpp"
#include "HashSum.hpp"

using namespace std;

template<typename T, typename = typename std::enable_if<std::is_base_of<ModelBase, T>::value, T>::type>
class IOHelper {
public:

    /**
	 * Write out (@link ModelBase) array to output stream (pretty print).
	 * @param stream output stream.
	 * @param models array class implement (@link ModelBase).
	 */
    static void print(ostream &stream, vector<T *> dataList) {
        json jDataList;
        for (int i = 0; i < dataList.size(); i++)
            jDataList.push_back(dataList[i]->toJson());
        string jsonStringNormal = jDataList.dump();
        unsigned hashCode = Hash::hashSum(jsonStringNormal);

        json jObject = json({
                                    {"data", jDataList},
                                    {"code", hashCode}
                            });
        stream << setw(4) << jObject;
    }

    /**
	 * Parse list of (@link ModelBase) from stream.
	 * @param stream input stream
	 * @throw error if hash code is mismatch.
	 * @return array of (@link ModelBase)
	 */
    static vector<T *> read(istream &stream) throw(const char*) {
        string dataStr = string((std::istreambuf_iterator<char>(stream)),
                                (std::istreambuf_iterator<char>()));
        vector<T *> result;
        json jObject = json::parse(dataStr);
        json jData = jObject["data"];
        unsigned hashCode = jObject["code"];
        if (!Hash::checkHashCode(jData.dump(), hashCode))
            throw "Hash code mismatch";
        else if (!jData.is_array()) {
            throw "Struct invalid";
        } else {
            for (int i = 0; i < jData.size(); i++)
                result.push_back(new T(jData[i]));
        }
        return result;
    };
};


#endif //ASSIGNMENT_CPP_IOHELPER_HPP

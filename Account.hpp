//
// Created by khang on 26/05/2016.
//

#ifndef ASSIGNMENT_CPP_ACCOUNT_HPP
#define ASSIGNMENT_CPP_ACCOUNT_HPP

#include <iostream>
#include "ModelBase.hpp"
#include "HashSum.hpp"

using namespace std;

class Account : public ModelBase {
public:
    Account(const string userName, int passwordHash, int type) : ModelBase(),
                                                                 userName(userName),
                                                                 passwordHash(passwordHash),
                                                                 type(type) {}

    Account(const string userName, string password, int type) :
            Account(userName, Hash::hashSum(password), type) {}

    Account(const json &j) : Account(j[USER_NAME], (int) j[PASSWORD], j[TYPE]) {}

    json toJson() const;

    bool isMatchWith(string userName, string password) const;

    const string &getUserName() const {
        return userName;
    }

    void setUserName(const string &userName) {
        Account::userName = userName;
    }

    const int &getPasswordHash() const {
        return passwordHash;
    }

    void setPassword(const string &password) {
        Account::passwordHash = Hash::hashSum(password);
    }

    int getType() const {
        return type;
    }

    string getTypeStr() const {
        switch (type) {
            case TYPE_ADMIN:
                return "ADMIN";
            case TYPE_MANAGER:
                return "MANAGER";
            default:
                return "CUSTOMER";
        }
    }

    void setType(int type) {
        Account::type = type;
    }

    static const int TYPE_ADMIN = 1;
    static const int TYPE_MANAGER = 2;
    static const int TYPE_CUSTOMER = 3;
    static const char *TYPE;
    static const char *USER_NAME;
    static const char *PASSWORD;
private:
    string userName;
    int passwordHash;
    int type;
};


#endif //ASSIGNMENT_CPP_ACCOUNT_HPP

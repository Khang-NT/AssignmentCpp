//
// Created by khang on 26/05/2016.
//

#include "Account.hpp"

const char *Account::TYPE = "type";
const char *Account::USER_NAME = "userName";
const char *Account::PASSWORD = "password";

json Account::toJson() const {
    return {
            {USER_NAME, userName},
            {PASSWORD,  passwordHash},
            {TYPE,      type}
    };
}

bool Account::isMatchWith(string userName, string password) const {
    return (this->userName.compare(userName) == 0 &&
            this->passwordHash == Hash::hashSum(password));
}


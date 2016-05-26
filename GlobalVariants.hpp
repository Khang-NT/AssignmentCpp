//
// Created by root on 27/05/2016.
//

#ifndef ASSIGNMENT_CPP_GLOBALVARIANTS_HPP
#define ASSIGNMENT_CPP_GLOBALVARIANTS_HPP


#include "Account.hpp"
#include "IOHelper.hpp"
#include <fstream>

extern const char *ACCOUNT_FILE;

class GlobalVariants {
public:
    static vector<Account *> accounts;
    static int currentAccount;

    static void addAccount(Account *account);

    static void removeAccount(int accountIndex);

    static void changePasswordCurrentAccount(string newPassword);

private:
    static void onAccountListChanged();
};

#endif //ASSIGNMENT_CPP_GLOBALVARIANTS_HPP

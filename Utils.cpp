//
// Created by root on 27/05/2016.
//

#include <iostream>
#include "Utils.hpp"
#include "GlobalVariants.hpp"

void readLine(string &s) {
    do {
        getline(cin, s);
    } while (s.compare("") == 0);
}

void doSignUp(int accountType) {
    while (true) {
        string userName, password;
        printf("User name: ");
        readLine(userName);
        printf("Password: ");
        readLine(password);
        if (userName.length() < 5) {
            printf("User name too short.\n");
            continue;
        } else if (password.length() < 5) {
            printf("Password too short.\n");
            continue;
        } else if (userName.length() > 20) {
            printf("User name too long.\n");
            continue;
        } else {
            bool checkOk = true;
            for (const Account *account : GlobalVariants::accounts)
                if (account->getUserName().compare(userName) == 0) {
                    printf("User name exists.\n");
                    checkOk = false;
                    break;
                }
            if (!checkOk)
                continue;
            GlobalVariants::addAccount(new Account(userName, password, accountType));
            printf("Create account success!\n");
            break;
        }
    }
}

void doChangePassword() {
    while (true) {
        string password;
        printf("New password: ");
        readLine(password);
        if (password.length() < 5) {
            printf("Password too short.\n");
            continue;
        } else {
            GlobalVariants::changePasswordCurrentAccount(password);
            printf("Change password success!");
            cin.ignore();
            return;
        }
    }
}

void printUserList() {
    int i = 1;
    printf("%-4s. %-20s %-10s\n", "ID", "User Name", "Type");
    for (Account *account : GlobalVariants::accounts)
        printf("%-4d. %-20s %-10s\n", i++, account->getUserName().c_str(), account->getTypeStr().c_str());
}

//
// Created by root on 27/05/2016.
//

#include "GlobalVariants.hpp"

const char *ACCOUNT_FILE = "accounts.txt";

vector<Account *> GlobalVariants::accounts = {};
int GlobalVariants::currentAccount = -1;

void GlobalVariants::addAccount(Account *account) {
    accounts.push_back(account);
    onAccountListChanged();
}

void GlobalVariants::removeAccount(int accountIndex) {
    accounts.erase(accounts.begin() + accountIndex);
    onAccountListChanged();
}

void GlobalVariants::changePasswordCurrentAccount(string newPassword) {
    accounts[currentAccount]->setPassword(newPassword);
    onAccountListChanged();
}

void GlobalVariants::onAccountListChanged() {
    try {
        std::ofstream out(ACCOUNT_FILE);
        IOHelper<Account>::print(out, accounts);
        out.close();
    } catch (exception &e) {}
}



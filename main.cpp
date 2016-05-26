#include <iostream>
#include <fstream>
#include "Account.hpp"
#include "IOHelper.hpp"
#include "GlobalVariants.hpp"
#include "MenuHelper.hpp"
#include "Utils.hpp"
#include "AdminProcess.hpp"

using namespace std;

void doSignUpCustomer() {
    doSignUp(Account::TYPE_CUSTOMER);
}

void doSignIn() {
    while (true) {
        string userName, password;
        printf("User name: ");
        readLine(userName);
        printf("Password: ");
        readLine(password);
        for (int i = 0; i < GlobalVariants::accounts.size(); i++)
            if (GlobalVariants::accounts[i]->isMatchWith(userName, password)) {
                GlobalVariants::currentAccount = i;
                switch (GlobalVariants::accounts[i]->getType()) {
                    case Account::TYPE_ADMIN:
                        Admin::start();
                        break;
                    default:
                        break;
                }
                return;
            }
        printf("User name or password is wrong.\n");
    }
}

Account *defaultAdmin = new Account("admin", "admin", Account::TYPE_ADMIN);


int main() {

    MenuHelper *loginMenu = (new MenuHelper("LOGIN", MenuHelper::QUIT_CAPTION))
            ->addItem("Sign in", doSignIn)
            ->addItem("Sign up", doSignUpCustomer);


    ifstream accountFile(ACCOUNT_FILE);
    if (accountFile.fail()) {
        printf("Account file doesn't exist, do you want generate it (y/n)? ");
        if (!yesNo())
            return 0;
        GlobalVariants::addAccount(defaultAdmin);
    } else
        try {
            GlobalVariants::accounts = IOHelper<Account>::read(accountFile);
            accountFile.close();
        } catch (const char *e) {
            printf("Read Account.txt error: %s\nAll user data will be lost.\nRenew file (Y/N)? ", e);
            if (!yesNo())
                return 0;
            GlobalVariants::addAccount(defaultAdmin);
        }

    loginMenu->run(true);


    return 0;
}
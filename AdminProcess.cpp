//
// Created by root on 27/05/2016.
//

#include "AdminProcess.hpp"
#include "MenuHelper.hpp"
#include "Utils.hpp"
#include "Account.hpp"
#include "GlobalVariants.hpp"

void createAdminAccount() {
    doSignUp(Account::TYPE_ADMIN);
}

void createManagerAccount() {
    doSignUp(Account::TYPE_MANAGER);
}

void openManagerControlPanel() {

}

void deleteAnAccount() {
    printUserList();
    printf("\nType -1 to exit.\n");
    int choice;
    do {
        printf("Select account (ID) = ");
        cin >> choice;
        if (choice == GlobalVariants::currentAccount + 1) {
            printf("Could not delete your account\n");
            choice = 0;
        }
        if (choice == -1)
            return;
    } while (choice < 1 || choice > GlobalVariants::accounts.size());
    GlobalVariants::removeAccount(choice - 1);
    printf("Remove account complete.");
    cin.ignore();
}

MenuHelper *adminMenu = (new MenuHelper("Admin control panel", MenuHelper::LOG_OUT_CAPTION))
        ->addItem("Change password", doChangePassword)
        ->addItem("Open new admin account", createAdminAccount)
        ->addItem("Open new manager account", createManagerAccount)
        ->addItem("Remove an account", deleteAnAccount)
        ->addItem("Open manager control panel", openManagerControlPanel);

void Admin::start() {
    adminMenu->run(true);
}
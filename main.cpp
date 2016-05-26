#include <iostream>
#include <fstream>
#include "Account.hpp"
#include "IOHelper.hpp"

using namespace std;

int main() {
    Account *account = new Account("Test username", "passwordHash", Account::TYPE_ADMIN);
    vector<Account *> accounts;
    accounts.resize(1, account);

    //ofstream file("out.txt");
    //IOHelper<Account>::print(file, accounts);
    //file.close();

    ifstream input("out.txt");
    vector<Account *> a = IOHelper<Account>::read(input);;
    return 0;
}
#include "bankOperations.h"
#include "bankAccount.h"
#include <iostream>
#include <algorithm>

int BankOperations::numOfBnkAcc = 0;

void BankOperations::openBankAcct() {
    string firstName, lastName, SSN;
    BankAccount *bankAcct = new BankAccount();

    cout << "\n\tEnter the first name of the account holder: ";
    cin >> firstName;
    bankAcct->setFirstName(firstName);

    cout << "\tEnter the last name of the account holder: ";
    cin >> lastName;
    bankAcct->setLastName(lastName);

    cout << "\tEnter the SSN of the account holder: ";
    cin >> SSN;
    bankAcct->setSSN(SSN);

    bankAcct->setBnkAccNum(make_pair("BNK", 10000 + numOfBnkAcc));

    numOfBnkAcc++;
    bankAccts.push_back(bankAcct);

    cout << "\n\t| A new Bank Account " << bankAcct->getBnkAccNum().first
         << bankAcct->getBnkAccNum().second << " was successfully created\n\n";

    bankAcct->bankAccMenu();

    totBalAccts += bankAcct->getTotalBalance();
}

void BankOperations::modBnkAcc() {
    string strNum, bnkAccount;
    BankAccount temp;
    pair<string, int> bnkAccNum;
    bool check = true;

    cout << "\tEnter the bank account number to be modified: ";
    bnkAccNum = temp.getBnkAccNum();

    for (auto &acc : bankAccts) {
        if (bnkAccNum.second == acc->getBnkAccNum().second) {
            acc->bankAccMenu();
            check = false;
            break;
        }
    }
    if (check) {
        cout << "\n\t| Entered Bank Account Number Not found!\n";
    }
}

void BankOperations::closeBnkAccount() {
    pair<string, int> bnkAccNum;
    BankAccount temp;
    vector<BankAccount *>::iterator it;

    cout << "\tEnter the bank account number to be closed: ";
    bnkAccNum = temp.getBnkAccNum();

    for (it = bankAccts.begin(); it != bankAccts.end(); ++it) {
        if ((*it)->getBnkAccNum().second == bnkAccNum.second) {
            cout << "\n\t| Bank account " << bnkAccNum.first << bnkAccNum.second
                 << " was successfully closed.\n";
            bankAccts.erase(it);
            break;
        }
    }
}

void BankOperations::detailBnkAccts() {
    for (auto &acc : bankAccts) {
        acc->printInfo();
        acc->sortedDetailSubAccInfo();
    }
}

void BankOperations::sortedDetailBnkAccInfo() {
    sort(bankAccts.begin(), bankAccts.end(), [](BankAccount* a, BankAccount* b) {
        return a->getTotalBalance() < b->getTotalBalance();
    });

    detailBnkAccts();
}

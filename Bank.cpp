#include "Bank.h"

Bank::Bank() {
    cout << "Enter the name of the bank: ";
    getline(cin, bankName);
    cout << "Enter the address of the bank: ";
    getline(cin, bankAddress);
    cout << "Enter the working hours: ";
    getline(cin, workHours);
    cout << endl;
}

void Bank::menu() {
    char selection = 'y';

    while (selection != 'X') {
        cout << "\nEligible Services for " << bankName << endl;
        cout << "\t\tA -- Number of Bank-Accounts" << endl;
        cout << "\t\tS -- Number of Saving-Accounts" << endl;
        cout << "\t\tH -- Number of Checking-Accounts" << endl;
        cout << "\t\tO -- Open Bank-Account" << endl;
        cout << "\t\tC -- Close Bank-Account" << endl;
        cout << "\t\tM -- Modify Bank-Account" << endl;
        cout << "\t\tD -- Detailed Bank-Accounts" << endl;
        cout << "\t\tB -- Brief Bank-Accounts Info Sorted Based on Aggregated Balances" << endl;
cout << "\t\tX -- Exit" << endl;

cout << "Please enter your selection: ";
cin >> selection;
selection = toupper(selection);

switch (selection) {
    case 'A':
        cout << "\t| The number of Bank Account(s) is " << operations.bankAccts.size() << endl << endl;
        break;
    case 'S':
        cout << "\t| The number of Saving-Account(s) is " << BankAccount::numOfSavAcc << endl << endl;
        break;
    case 'H':
        cout << "\t| The number of Checking-Account(s) is " << BankAccount::numOfChkAcc << endl << endl;
        break;
    case 'O':
        operations.openBankAcct();
        break;
    case 'C':
        operations.closeBnkAccount();
        break;
    case 'M':
        operations.modBnkAcc();
        break;
    case 'D':
        operations.detailBnkAccts();
        break;
    case 'B':
        operations.sortedDetailBnkAccInfo();
        break;
    case 'X':
        cout << "\t| End of service for bank " << bankName << endl;
        break;
    default:
        cout << "\n\t| Invalid input" << endl << endl;
}
    }
}
            
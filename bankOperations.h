#ifndef BANK_OPERATIONS_H
#define BANK_OPERATIONS_H

#include "bankAccount.h"
#include <vector>

class BankOperations {
public:
    void openBankAcct();
    void modBnkAcc();
    void closeBnkAccount();
    void detailBnkAccts();
    void sortedDetailBnkAccInfo();

    vector<BankAccount *> bankAccts; // Public for easier access in the Bank class.
    static int numOfBnkAcc;
    double totBalAccts = 0;
};

#endif 
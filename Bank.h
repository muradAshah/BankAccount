#ifndef BANK_H
#define BANK_H

#include "bankOperations.h"
#include <iostream>
#include <string>

class Bank {
public:
    Bank();
    void menu();

private:
    string bankName;
    string bankAddress;
    string workHours;
    BankOperations operations;
};

#endif 

#ifndef PROJECT2_BANKACCOUNT_H
#define PROJECT2_BANKACCOUNT_H
#include "Account.h"

class bankAccount:public Account{
public:
    bankAccount(double=0);
    void deposit();
    void withdraw();

};
#endif //PROJECT2_BANKACCOUNT_H

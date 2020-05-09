#ifndef PROJECT2_STOCKACCOUNT_H
#define PROJECT2_STOCKACCOUNT_H
#include "Account.h"
#include "Account.cpp"

class stockAccount:public Account
{
public:
    stockAccount(double=0);
    void buyStock (vector<Stock>&);
    void sellStock(vector<Stock>&);
    void displayCurrentPortfolio(vector<Stock>&);
    void displayTransactionsHistory(vector<Stock>&);

};
#endif //PROJECT2_STOCKACCOUNT_H

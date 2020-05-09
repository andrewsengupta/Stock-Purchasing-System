#ifndef PROJECT2_ACCOUNT_H
#define PROJECT2_ACCOUNT_H
#include <iostream>
#include <vector>
#include "stock.cpp"
using namespace std;

class Account {
protected:
    double cashBalance;
public:
    Account(double=0);
    double getBalance(void);
    void setBalance(double);
    void displayTransactionHistory(void);
    void displayAccounts(vector<Stock>);
    string displayPrice (string);
    void storeStockInfo (vector<Stock>&);

};

#endif //PROJECT2_ACCOUNT_H

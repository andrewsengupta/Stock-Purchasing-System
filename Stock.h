#ifndef PROJECT2_STOCK_H
#define PROJECT2_STOCK_H
#include <iostream>
#include <vector>
using namespace std;

class Stock{
public:
    Stock(string,string,int=0);
    string stockSymbol;
    string stockCompany;
    int stockAmount;
};
#endif //PROJECT2_STOCK_H

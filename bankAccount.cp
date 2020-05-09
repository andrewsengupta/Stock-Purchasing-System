#include "BankAccount.h"

bankAccount::bankAccount(double balance){
    balance=cashBalance;

}

void bankAccount::deposit(void){
    int input;
    cout<<"Enter amount to be deposited: ";
    cin>>input;
    cashBalance+=input;
}

void bankAccount::withdraw(void){
    int input;
    cout<<"Enter amount to be withdrawn: ";
    cin>>input;
    if(input<=cashBalance)
    {
        cashBalance-=input;
    }

    else
    {
        cout<<"Invalid input."<<endl;
    }
}


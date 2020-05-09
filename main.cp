#include "stockAccount.cpp"
#include "bankAccount.cpp"
#include <fstream>

void menu(int *num) {
    int select = 0;
    cout << "Welcome to the Account Management System." << endl;
    cout << "Please select an account to access" << endl;
    cout << "\t1. Stock Portfolio Account." << "\n\t2. Bank Account."
         << "\n\t3. Exit." << endl;
    cout << "Your selection:\t";
    cin >> select;
    *num = select;
}

void stockMenu(int *num) {
    int select = 0;
    cout << "Please select an option" << endl;
    cout << "\t1. Display current price for a stock symbol." << "\n\t2. Buy stock."
         << "\n\t3. Sell stock." << "\n\t4. Display current portfolio."
         << "\n\t5. Display transactions history." << "\n\t6. Return to main menu." << endl;
    cout << "Your selection:\t";
    cin >> select;
    *num = select;
}

void menu3(int *num) {
    int select = 0;
    cout << "Please select an option" << endl;
    cout << "\t1. View account balance." << "\n\t2. Deposit money."
         << "\n\t3. Withdraw money." << "\n\t4. Display transaction history."
         << "\n\t5. Return to main menu." << endl;
    cout << "Selection:\t";
    cin >> select;
    *num = select;
}

int main(){
    vector<Stock> vec;

    stockAccount s(10000);
    bankAccount b(10000);
    s.storeStockInfo(vec);

    int input1=0;
    int input2=0;
    int input3=0;

    while(input1==0){
        int input = 0;
        int *inputPtr = &input;
        menu(inputPtr);
        switch (input) {
            case 1:{
                while(input2==0)
                {
                    int input = 0;
                    int *inputPtr = &input;
                    stockMenu(inputPtr);
                    switch (input) {
                        case 1:{
                            string symbol;
                            cout<<"Enter stock symbol: ";
                            cin>>symbol;
                            s.displayPrice(symbol);
                            break;
                        }
                        case 2:
                            s.buyStock(vec);
                            b.setBalance(s.getBalance());
                            break;
                        case 3:
                            s.sellStock(vec);
                            b.setBalance(s.getBalance());
                            break;
                        case 4:
                            s.displayCurrentPortfolio(vec);
                            break;
                        case 5:
                            s.displayTransactionsHistory(vec);
                            break;
                        case 6:
                            input2=1;
                            break;
                        default:
                            cout<<"Invalid input.";
                            break;
                    }
                }
                input2=0;
                break;
            }
            case 2:{
                while(input3==0){
                    int input = 0;
                    int *inputPtr = &input;
                    menu3(inputPtr);
                    switch (input) {
                        case 1:
                            s.displayCurrentPortfolio(vec);
                            break;
                        case 2:
                            b.deposit();
                            s.setBalance(b.getBalance());
                            break;
                        case 3:
                            b.withdraw();
                            s.setBalance(b.getBalance());
                            break;
                        case 4:
                            s.displayCurrentPortfolio(vec);
                            break;
                        case 5:
                            input3=1;
                            break;
                        default:
                            cout<<"Invalid input.";
                            break;
                    }
                }
                input3=0;
                break;
            }
            case 3:
                input1=1;
                break;
            default:
                cout<<"Invalid input.";
                break;
        }
    }
    return 0;
}
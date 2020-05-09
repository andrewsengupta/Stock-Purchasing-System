#include "Account.h"
#include <fstream>
#include <iostream>
#include <cstdlib>
#include <time.h>
#include <string>
#include <sstream>
using namespace std;

Account::Account (double bal)
{
    cashBalance=bal;
}

void displayPrice(string stockSymbol) {
    cout << "Enter symbol: " << endl;
    cin >> stockSymbol;
    srand(time(NULL));
    int num = rand() % 4 + 1;
    string nameTwo = "C:\\Users\\andrew\\CLionProjects\\Project2\\stock" + to_string(num) + ".txt";
    ifstream file_(nameTwo);
    string line, co;
    int first;
    "\n";
    if (file_.is_open()) {
        while (getline(file_, line)) {
            first = line.find("\t");
            co = line.substr(0, first);
            if (stockSymbol == co) {
                cout << line << endl;
                file_.close();

                return;
            }

        }
        cout << "That stock can not be found" << endl;


    }
}



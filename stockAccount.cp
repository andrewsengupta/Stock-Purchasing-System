#include "stockAccount.h"
#include <string>
#include <fstream>

    void stockAccount::buyStock(vector<Stock>&vec)
    {
        string stockSymbol;
        int shareAmount;
        double priceWilling;
        cout<<"Enter symbol: ";
        cin>>stockSymbol;
        srand(time(NULL));
        int num = rand() % 4 + 1;
        ifstream file ("C:\\Users\\andrew\\CLionProjects\\Project2\\stock" + to_string(num) + ".txt");
        string symbolFromFile;
        string companyName;
        double stockPrice;
        while (file>>symbolFromFile>>companyName>>stockPrice)
        {
            if (symbolFromFile==stockSymbol)
            {
                cout<<symbolFromFile<<stockPrice<<endl;
                cout<<"Enter amount of shares: ";
                cin>>shareAmount;
                cout<<"Enter price willing to pay: ";
                cin>>priceWilling;
                if (priceWilling>=stockPrice && cashBalance>=(priceWilling*shareAmount))
                {
                    cashBalance-=(priceWilling*shareAmount);
                    cout<<"Cash balance: "<<cashBalance<<endl;
                    ofstream transactionHistory("stock_transaction_history.txt");
                    transactionHistory<<stockSymbol<< " " <<companyName<< " " << " " <<shareAmount<< " "<<priceWilling*shareAmount<<endl;
                    break;


                }
                else
                {
                    cout<<"Cannot process transaction";
                    break;
                }
            }
            else
            {
                cout<<"That stock cannot be found."<<endl;
                break;
            }
        }
    }

void stockAccount::sellStock(vector<Stock>&vec)
{
    srand(time(NULL));
    int num = rand() % 4 + 1;
    string stockSymbol;
    int shareAmount;
    double priceWilling;
    cout<<"Enter symbol: ";
    cin>>stockSymbol;
    cout<<"Enter amount of shares: ";
    cin>>shareAmount;
    cout<<"Enter price for each share: ";
    cin>>priceWilling;
    ifstream historyFile ("C:\\Users\\andrew\\CLionProjects\\Project2\\stock_transaction_history.txt");
    string symbolFromFile;
    string companyName;
    int shareAmountFromFile;
    double total;
    while (historyFile>>symbolFromFile>>companyName>>shareAmountFromFile>>total)
    {
        if (symbolFromFile==stockSymbol && shareAmount>=shareAmountFromFile)
        {
            ifstream stockFile ("C:\\Users\\andrew\\CLionProjects\\Project2\\stock" + to_string(num) + ".txt");
            string symbolFromStockFile;
            string stockCompanyName;
            double stockPriceFromFile;
            while (stockFile>>symbolFromStockFile>>stockCompanyName>>stockPriceFromFile)
            {
                if (priceWilling<=stockPriceFromFile)
                {
                    cashBalance+=(priceWilling*shareAmount);
                    cout<<"Cash balance: "<<cashBalance<<endl;
                    break;
                }
                else
                {
                    cout<<"Cannot process transaction."<<endl;
                    break;
                }
            }
        }
        else
        {
            cout<<"Cannot process transaction."<<endl;
            break;
        }
    }


}

    void stockAccount::displayCurrentPortfolio(vector<Stock> &)
    {
        srand(time(NULL));
        int num = rand() % 4 + 1;
        cout<<"Cash balance: "<<cashBalance<<endl;
        ifstream historyFile ("C:\\Users\\andrew\\CLionProjects\\Project2\\stock_transaction_history.txt");
        string symbolFromFile;
        string companyName;
        int shareAmountFromFile;
        double total;
        while (historyFile>>symbolFromFile>>companyName>>shareAmountFromFile>>total)
        {
            ifstream stockFile ("C:\\Users\\andrew\\CLionProjects\\Project2\\stock" + to_string(num) + ".txt");
            string symbolFromStockFile;
            string stockCompanyName;
            double stockPriceFromFile;
            while (stockFile>>symbolFromStockFile>>stockCompanyName>>stockPriceFromFile)
            {
                cout<<symbolFromFile<< " " <<companyName<< " " <<stockPriceFromFile<< " " <<total<<endl;
            }
        }

    }

void stockAccount::displayTransactionsHistory(vector<Stock> &)
{
    ifstream historyFile ("C:\\Users\\andrew\\CLionProjects\\Project2\\stock_transaction_history.txt");
    string symbolFromFile;
    string companyName;
    int shareAmountFromFile;
    double total;
    while (historyFile>>symbolFromFile>>companyName>>shareAmountFromFile>>total)
    {
        cout<<symbolFromFile<< " " <<companyName<< " " <<shareAmountFromFile<< " " <<total<<endl;
    }
}





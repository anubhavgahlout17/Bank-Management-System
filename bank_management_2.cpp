#include <iostream>
#include <stdlib.h>
#include <string>
#include <fstream>
using namespace std;

class bankAccount
{

    int accountNumber;
    static int nextaccount;
    string name;
    double balance;
    string phone;

public:
    static void setNextAcc(int val)
    {
        nextaccount = val;
    }
    void setData(int accNo, string nam, string ph, double bal)
    {
        accountNumber = accNo;
        name = nam;
        phone = ph;
        balance = bal;
    }
    int getacc()
    {
        return accountNumber;
    }

    bool createAcc();
    void displayAcc();
    void deposit();
    void withdraw();
    void checkbalance();

    string getName()
    {
        return name;
    }
    string getPhone()
    {
        return phone;
    }
    double getBalance()
    {
        return balance;
    }
};

int bankAccount::nextaccount = 1000;

bool bankAccount::createAcc()
{
    cout << "Enter Name: ";
    getline(cin, name);

    cout << "Enter Phone Number: ";
    cin >> phone;

    cout << "Enter Initial Balance: ";
    cin >> balance;

    if (balance < 500)
    {
        cout << "Mininimum balance is 500" << endl;
        return false;
    }
    else
    {
        accountNumber = nextaccount++;
        ofstream file("accounts.txt", ios::app);
        file << accountNumber << "|"
             << name << "|"
             << phone << "|"
             << balance << "\n";

        file.close();
        cout << "Accounts Create Successfully" << endl;
        cout << "Your Account Number is: " << accountNumber << endl;
    }

    return true;
}

void bankAccount::displayAcc()
{
    cout << "Name of Account Holder: " << name << endl;
    cout << "Account Number: " << accountNumber << endl;
    cout << "Phone Number: " << phone << endl;
    cout << "Balance: " << balance << endl;
}

void bankAccount::deposit()
{
    double amount;
    cout << "Enter amount: ";
    cin >> amount;
    if (amount <= 0)
    {
        cout << "Amount is not valid" << endl;
        return;
    }
    else
    {
        balance = balance + amount;
        cout << "Amount Successfully Deposit" << endl;
    }
}

void bankAccount::withdraw()
{
    double amount;
    cout << "Enter Amount: ";
    cin >> amount;
    int minibal = 500;

    if (amount <= 0)
    {
        cout << "Invalid Amount" << endl;
        return;
    }

    if (amount > balance)
    {
        cout << "Insufficient balance" << endl;
        return;
    }
    else if (balance - amount >= minibal)
    {
        balance = balance - amount;
        cout << "withdraw successful" << endl;
    }
    else
    {
        cout << "Cannot withdraw, minimum balance must remain 500" << endl;
    }
}

void saveAllAccounts(bankAccount acc[], int count)
{
    ofstream file("accounts.txt");

    for (int i = 0; i < count; i++)
    {
        file << acc[i].getacc() << "|"
             << acc[i].getName() << "|"
             << acc[i].getPhone() << "|"
             << acc[i].getBalance() << "\n";
    }

    file.close();
}

void bankAccount::checkbalance()
{
    cout << "Balance is: " << balance << endl;
}

int main()
{
    bankAccount acc[500];
    int choose;
    int count = 0;
    int max = 999;

    ifstream file("accounts.txt");
    string line;

    while (getline(file, line))
    {
        int p1 = line.find('|');
        int p2 = line.find('|', p1 + 1);
        int p3 = line.find('|', p2 + 1);

        if (p1 == string::npos || p2 == string::npos || p3 == string::npos)
            continue;

        int accNo       = stoi(line.substr(0, p1));
        string name     = line.substr(p1 + 1, p2 - p1 - 1);
        string phone    = line.substr(p2 + 1, p3 - p2 - 1);
        double balance  = stod(line.substr(p3 + 1));

        acc[count].setData(accNo, name, phone, balance);
        count++;
        if (accNo > max)
        {
            max = accNo;
        }
    }

    bankAccount::setNextAcc(max + 1);
    file.close();

    do
    {
        cout << "\n1.Create Account" << endl;
        cout << "2.Search Account " << endl;
        cout << "3.Deposit Money" << endl;
        cout << "4.withdraw Money" << endl;
        cout << "5.Check Balance" << endl;
        cout << "6.Show all accounts" << endl;
        cout << "7.Delete Account" << endl;
        cout << "8.Exit" << endl;
        cout << "Enter choice: ";
        cin >> choose;
        cin.ignore();

        switch (choose)
        {
        case 1:

            if (acc[count].createAcc())
            {
                count++;
            }

            break;
        case 2:
        {
            int accNum;
            cout << "Enter Account Number: ";
            cin >> accNum;
            bool found = false;
            for (int i = 0; i < count; i++)
            {
                if (acc[i].getacc() == accNum)
                {
                    acc[i].displayAcc();
                    found = true;
                    break;
                }
            }
            if (found == false)
            {
                cout << "Account not Found" << endl;
            }
            break;
        }

        case 3:
        {
            int accNo;
            cout << "Enter Account Number: ";
            cin >> accNo;
            bool found = false;

            for (int i = 0; i < count; i++)
            {
                if (acc[i].getacc() == accNo)
                {
                    acc[i].deposit();
                    saveAllAccounts(acc, count);
                    found = true;
                    break;
                }
            }
            if (found == false)
            {
                cout << "Account Not found" << endl;
            }
            break;
        }

        case 4:
        {
            int accNum;
            cout << "Enter Account Number: ";
            cin >> accNum;
            bool found = false;

            for (int i = 0; i < count; i++)
            {
                if (accNum == acc[i].getacc())
                {
                    acc[i].withdraw();
                    saveAllAccounts(acc, count);
                    found = true;
                    break;
                }
            }
            if (found == false)
            {
                cout << "Account Not found" << endl;
            }

            break;
        }

        case 5:
        {
            int AccNo;
            cout << "Enter Account Number: ";
            cin >> AccNo;
            bool found = false;
            for (int i = 0; i < count; i++)
            {
                if (AccNo == acc[i].getacc())
                {
                    acc[i].checkbalance();
                    found = true;
                    break;
                }
            }
            if (found == false)
            {
                cout << "Acount not found" << endl;
            }
            break;
        }

        case 6:
            if (count == 0)
            {
                cout << "Accounts not exist" << endl;
            }
            else
            {
                for (int i = 0; i < count; i++)
                {
                    acc[i].displayAcc();
                }
            }
            break;

        case 7:
        {
            int accNo;
            cout << "Enter Account Number: ";
            cin >> accNo;
            bool found = false;
            int index = 0;
            for (int i = 0; i < count; i++)
            {
                if (accNo == acc[i].getacc())
                {
                    index = i;
                    found = true;
                    break;
                }
            }

            if (found == true)
            {
                for (int i = index; i < count - 1; i++)
                {
                    acc[i] = acc[i + 1];
                }
                count--;
                saveAllAccounts(acc, count);
                cout << "Account Deleted Successfully" << endl;
            }
            else
            {
                cout << "Account not found" << endl;
            }
            break;
        }
        case 8:
            cout << "Exiting....." << endl;
            exit(0);
            break;
        default:
            cout << "Invalid Choice" << endl;
            break;
        }

    } while (1);

    return 0;
}

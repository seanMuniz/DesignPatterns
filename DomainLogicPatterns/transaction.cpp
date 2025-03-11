#include <iostream>
#include <string>

using namespace std;

class Account {
private: 
    string owner; 
    double balance; 
public:
    Account(const string& owner, double balance) : owner(owner), balance(balance) {}
    string getOwner() const { return owner;}
    double getBalance() const {return balance;}

    void debit(double amount){
        if (amount <= balance) {
            balance -= amount; 
            cout << "Debited $" << amount << " from " << owner << endl;
            cout << " New balance: " << balance << endl;
        } else {
            cout << "Insufficient funds for debit " << endl;
        }
    }

    void credit (double amount) {
        balance += amount ;
        cout << "Credited $" << amount << " to " << owner << endl;
        cout << "new balance: " << balance;
    }
};

class TransactionScript {
public: 
    // this function conducts a series of steps. first it debits one account, then credits the next.
    static void transferFunds(Account& fromAccount, Account& toAccount, double amount) {
        fromAccount.debit(amount);
        toAccount.credit(amount);
        cout << "Transaction completed \n";
    }
};

int main() {
    Account account1("Alice", 500);
    Account account2("Bob", 300);

    TransactionScript::transferFunds(account1, account2, 100);
}

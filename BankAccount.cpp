#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <cmath>
using namespace std;

class BankAccount {
private:
    string accountNumber;
    string accountHolderName;
    string accountType;
    float accountBalance;
    vector<string> transactionHistory;

public:
    // Constructor
    BankAccount(const string& accNum, const string& holderName, const string& accType, float balance)
        : accountNumber(accNum), accountHolderName(holderName), accountType(accType), accountBalance(balance) {
        addTransaction("Account created with balance $" + to_string(balance));
    }

    // Getter and Setter for account attributes
    string getAccountNumber() const { return accountNumber; }
    string getAccountHolderName() const { return accountHolderName; }
    string getAccountType() const { return accountType; }
    float getAccountBalance() const { return accountBalance; }

    void setAccountBalance(float balance) { accountBalance = balance; }

    // Transaction history
    void addTransaction(const string& transaction) {
        transactionHistory.push_back(transaction);
    }

    void displayTransactionHistory() const {
        cout << "Transaction History for " << accountNumber << ":\n";
        for (const string& transaction : transactionHistory) {
            cout << "- " << transaction << endl;
        }
    }

    // Deposit method
    void deposit(float amount) {
        if (amount > 0) {
            accountBalance += amount;
            addTransaction("Deposited $" + to_string(amount) + ". New balance: $" + to_string(accountBalance));
        } else {
            cout << "Invalid deposit amount.\n";
        }
    }

    // Withdraw method
    bool withdraw(float amount) {
        if (amount <= accountBalance) {
            accountBalance -= amount;
            addTransaction("Withdrew $" + to_string(amount) + ". New balance: $" + to_string(accountBalance));
            return true;
        } else {
            cout << "Insufficient funds. Withdrawal denied.\n";
            return false;
        }
    }

    // Transfer funds
    void transferFunds(BankAccount& toAccount, float amount) {
        if (withdraw(amount)) {
            toAccount.deposit(amount);
            addTransaction("Transferred $" + to_string(amount) + " to " + toAccount.getAccountNumber());
            toAccount.addTransaction("Received $" + to_string(amount) + " from " + accountNumber);
        }
    }

    // Overload + and == operators
    BankAccount operator+(const BankAccount& other) const {
        return BankAccount("MergedAccount", "N/A", "N/A", this->accountBalance + other.accountBalance);
    }

    bool operator==(const BankAccount& other) const {
        return this->accountNumber == other.accountNumber;
    }

    // Virtual method for interest rate
    virtual float getInterestRate() const {
        return 0.0f; // Default interest rate for base class
    }

    // Display account details
    virtual void displayDetails() const {
        cout << "Account Number: " << accountNumber
             << "\nAccount Holder: " << accountHolderName
             << "\nAccount Type: " << accountType
             << "\nAccount Balance: $" << fixed << setprecision(2) << accountBalance << endl;
    }
};

// SavingsAccount class
class SavingsAccount : public BankAccount {
public:
    SavingsAccount(const string& accNum, const string& holderName, float balance)
        : BankAccount(accNum, holderName, "Savings", balance) {}

    float getInterestRate() const override {
        return 0.03f; // 3% interest rate
    }

    float calculateCompoundInterest(int years, int frequency) const {
        float rate = getInterestRate();
        float principal = getAccountBalance();
        float compoundBalance = principal * pow((1 + rate / frequency), frequency * years);
        return compoundBalance - principal; // Return only the interest earned
    }
};

// CheckingAccount class
class CheckingAccount : public BankAccount {
public:
    CheckingAccount(const string& accNum, const string& holderName, float balance)
        : BankAccount(accNum, holderName, "Checking", balance) {}

    float getInterestRate() const override {
        return 0.01f; // 1% interest rate
    }
};

// CreditAccount class
class CreditAccount : public BankAccount {
private:
    float creditLimit;
    float interestRate;

public:
    CreditAccount(const string& accNum, const string& holderName, float limit, float rate)
        : BankAccount(accNum, holderName, "Credit", 0.0f), creditLimit(limit), interestRate(rate) {}

    void borrow(float amount) {
        if (amount <= creditLimit) {
            setAccountBalance(getAccountBalance() + amount);
            addTransaction("Borrowed $" + to_string(amount) + ". New balance: $" + to_string(getAccountBalance()));
        } else {
            cout << "Credit limit exceeded. Borrowing denied.\n";
        }
    }

    void applyInterest() {
        float interest = getAccountBalance() * interestRate;
        setAccountBalance(getAccountBalance() + interest);
        addTransaction("Applied interest: $" + to_string(interest) + ". New balance: $" + to_string(getAccountBalance()));
    }
};

// JointAccount class
class JointAccount : public BankAccount {
private:
    vector<string> accountHolders;

public:
    JointAccount(const string& accNum, const vector<string>& holders, float balance)
        : BankAccount(accNum, "Joint Account", "Joint", balance), accountHolders(holders) {}

    void displayDetails() const override {
        BankAccount::displayDetails();
        cout << "Account Holders: ";
        for (const string& holder : accountHolders) {
            cout << holder << " ";
        }
        cout << endl;
    }
};

// Main function
int main() {
    // Create accounts
    SavingsAccount savings("SA123", "Alice", 3000.0f);
    CheckingAccount checking("CA456", "Bob", 1500.0f);
    CreditAccount credit("CC789", "Charlie", 5000.0f, 0.05f);
    JointAccount joint("JA101", {"Alice", "Bob"}, 4000.0f);

    // Test transfer
    savings.transferFunds(checking, 500);

    // Test transaction history
    savings.displayTransactionHistory();
    checking.displayTransactionHistory();

    // Test compound interest
    cout << "Savings Account Compound Interest (5 years, compounded annually): $"
         << savings.calculateCompoundInterest(5, 1) << endl;

    // Test credit account borrowing and interest
    credit.borrow(1000);
    credit.applyInterest();
    credit.displayTransactionHistory();

    // Display joint account details
    joint.displayDetails();

    return 0;
}

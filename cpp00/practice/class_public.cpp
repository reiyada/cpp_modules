#include <iostream>
#include <string>

class BankAccount
{
public://access specifier
    std::string name;
    int balance;

    void withdraw(int amount)
    {
        balance -= amount;
    }
    void print()
    {
        std::cout << name << " has " << balance << " euros " << std::endl;
    }
};

int main()
{
    BankAccount account1;
    BankAccount account2;
    BankAccount account3;

    account1.name = "Rei";
    account1.balance = -100000;

    account2.name = "Louis";
    account2.balance = 100000;

    account3.name = "Family account";

    account1.print();
    account2.print();
    std::cout << account1.name << " withdrawed " << " 100 euros " << std::endl;
    account1.withdraw(100);
    account3.balance = account1.balance + account2.balance;
    account3.print();
    return (0);
}
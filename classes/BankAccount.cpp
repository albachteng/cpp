#include "BankAccount.h"
#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

BankAccount::BankAccount(string n) : BankAccount(n, 0) {}

BankAccount::BankAccount(const BankAccount &bank_account)
    : name(bank_account.name), balance(bank_account.balance) {
  cout << "copying: " << name << " with " << balance << " balance" << endl;
}

BankAccount::BankAccount(string n, float b) : name(n), balance(b) {
  cout << "account constructor for " << name << " balance: " << balance << endl;
}

string BankAccount::get_name() { return name; }

float BankAccount::get_balance() { return balance; }
void BankAccount::set_balance(float b) { balance = b; }
void BankAccount::display() {
  cout << "name: " << name << " balance: " << balance << endl;
}

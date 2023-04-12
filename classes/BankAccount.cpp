#include "BankAccount.h"
#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

BankAccount::BankAccount(string n, float b) : name(n), balance(b) {
  cout << "account constructor for " << name << " balance: " << balance << endl;
}

string BankAccount::get_name() { return name; }

float BankAccount::get_balance() { return balance; }

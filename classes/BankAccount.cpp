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
  credit_card = new CreditCard(*(bank_account.credit_card));
}

BankAccount::~BankAccount() {
  cout << "deleting: " << name << " with " << balance << " balance" << endl;
  cout << "credit card: " << credit_card->get_name()
       << " limit: " << credit_card->get_limit() << endl;
  delete credit_card;
  credit_card = nullptr;
}

BankAccount::BankAccount(string n, float b) : name(n), balance(b) {
  credit_card = new CreditCard("Visa", 1000);
  cout << "account constructor for " << name << " balance: " << balance << endl;
  cout << "credit card: " << credit_card->get_name()
       << " limit: " << credit_card->get_limit() << endl;
}

string BankAccount::get_name() { return name; }

void BankAccount::set_limit(float l) { credit_card->set_limit(l); }

float BankAccount::get_balance() { return balance; }
void BankAccount::set_balance(float b) { balance = b; }
void BankAccount::display() {
  cout << "name: " << name << " balance: " << balance << endl;
  cout << "credit card: " << credit_card->get_name()
       << " limit: " << credit_card->get_limit() << endl;
}

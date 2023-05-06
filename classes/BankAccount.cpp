#include "BankAccount.h"
#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

BankAccount::BankAccount(string n, float b) : name(n), balance(b) {
  credit_card = new CreditCard("Visa", 1000);
  cout << "account constructor for " << name << " balance: " << balance << endl;
  cout << "credit card: " << credit_card->get_name()
       << " limit: " << credit_card->get_limit() << endl;
  transaction_log.push_back("constructed account");
}

BankAccount::BankAccount(string n) : BankAccount(n, 0) {
  transaction_log.push_back("constructed account");
}

BankAccount::BankAccount(const BankAccount &bank_account)
    : name(bank_account.name), balance(bank_account.balance) {
  cout << "copying: " << name << " with " << balance << " balance" << endl;
  credit_card = new CreditCard(*(bank_account.credit_card));
  transaction_log.push_back("copied account");
}

BankAccount::~BankAccount() {
  cout << "deleting: " << name << " with " << balance << " balance" << endl;
  cout << "credit card: " << credit_card->get_name()
       << " limit: " << credit_card->get_limit() << endl;
  delete credit_card;
  credit_card = nullptr;
  transaction_log.push_back("deleted account");
}

string BankAccount::get_name() {
  transaction_log.push_back("returned name");
  return name;
}
void BankAccount::set_limit(float l) {
  credit_card->set_limit(l);
  transaction_log.push_back("set limit");
}
float BankAccount::get_balance() {
  transaction_log.push_back("got balance");
  return balance;
}
void BankAccount::set_balance(float b) {
  transaction_log.push_back("set balance");
  balance = b;
}
void BankAccount::display() {
  cout << "name: " << name << " balance: " << balance << endl;
  cout << "credit card: " << credit_card->get_name()
       << " limit: " << credit_card->get_limit() << endl;
  transaction_log.push_back("displayed info");
}

void BankAccount::display_transaction_report() const {
  for (auto transaction : transaction_log) {
    cout << transaction << endl;
  }
}

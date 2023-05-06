#include "CreditCard.h"
#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

CreditCard::CreditCard(const CreditCard &credit_card)
    : name(credit_card.name), limit(credit_card.limit) {
  cout << "copying card: " << name << " with " << limit << " limit" << endl;
}

CreditCard::~CreditCard() {
  cout << "deleting card: " << name << " with " << limit << " limit" << endl;
}

CreditCard::CreditCard(string n, float b) : name(n), limit(b) {
  cout << "card constructor for " << name << " limit: " << limit << endl;
}

string CreditCard::get_name() { return name; }

float CreditCard::get_limit() { return limit; }
void CreditCard::set_limit(float b) { limit = b; }
void CreditCard::display() {
  cout << "card: " << name << " limit: " << limit << endl;
}

#include "BankAccount.h"
#include <iostream>

using std::cout;
using std::endl;

void update_and_display_account_details(BankAccount bank_account) {
  bank_account.set_balance(4444);
  bank_account.display();
}

int main() {
  BankAccount claudia_account("Claudia", 1000.45f);
  BankAccount claudia_copy{claudia_account};

  cout << "---- claudia's acct ----" << endl;
  claudia_account.display();

  cout << "--- claudia copy ---" << endl;
  claudia_copy.display();

  // update_and_display_account_details(claudia_account);
  cout << " --- end ---" << endl;

  // peter_account.display();
}

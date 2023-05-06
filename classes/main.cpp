#include "BankAccount.h"
#include <iostream>

using std::cout;
using std::endl;

int main() {
  BankAccount claudia_account("Claudia", 1000.45f);
  BankAccount peter_account{"Peter", 555.55f};
  BankAccount sarah_account;
  BankAccount peter_copy{peter_account};

  cout << "---- claudia's acct ----" << endl;
  cout << claudia_account.get_name() << endl;
  cout << claudia_account.get_balance() << endl;
  claudia_account.set_balance(2000.45f);
  cout << "new balance: " << endl;
  cout << claudia_account.get_balance() << endl;

  cout << "---- peter's acct ----" << endl;
  cout << peter_account.get_name() << endl;
  cout << peter_account.get_balance() << endl;

  cout << "---- sarah's acct ----" << endl;
  cout << sarah_account.get_name() << endl;
  cout << sarah_account.get_balance() << endl;

  cout << "--- peter copy ---" << endl;
  peter_copy.set_balance(1999.0f);
  peter_copy.display();

  peter_account.display();
}

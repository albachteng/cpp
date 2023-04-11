#include <iostream>

using std::cout;
using std::endl;
using std::string;

class BankAccount {
private:
  string name{};
  float balance{0};

public:
  string get_name() { return name; };
  void set_name(string n) { name = n; };
  float get_balance() { return balance; };
  void set_balance(float b) { balance = b; };
};

int main() {
  BankAccount claudia_account;
  BankAccount peter_account;

  claudia_account.set_name("Claudia");
  peter_account.set_name("Peter");
  claudia_account.set_balance(1000);
  peter_account.set_balance(555);

  cout << "---- claudia's acct ----" << endl;
  cout << claudia_account.get_name() << endl;
  cout << claudia_account.get_balance() << endl;

  cout << "---- peter's acct ----" << endl;
  cout << peter_account.get_name() << endl;
  cout << peter_account.get_balance() << endl;
}

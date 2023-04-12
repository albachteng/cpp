#pragma once
#include <string>

class BankAccount {
private:
  const std::string name{};
  float balance{0};

public:
  BankAccount() = default;
  BankAccount(std::string);
  BankAccount(std::string n, float b);
  std::string get_name();
  void set_name(std::string n);
  float get_balance();
  void set_balance(float b);
};

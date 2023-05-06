#pragma once
#include <string>

class BankAccount {
private:
  const std::string name{};
  float balance{0};

public:
  explicit BankAccount() = default;
  BankAccount(const BankAccount &bank_account);
  explicit BankAccount(std::string);
  explicit BankAccount(std::string n, float b);
  std::string get_name();
  void set_name(std::string n);
  void display();
  float get_balance();
  void set_balance(float b);
};

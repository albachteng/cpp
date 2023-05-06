#pragma once
#include "CreditCard.h"
#include <string>
#include <vector>

class BankAccount {
private:
  const std::string name{};
  float balance{0};
  CreditCard *credit_card;
  std::vector<std::string> transaction_log;

public:
  explicit BankAccount() = default;
  BankAccount(const BankAccount &bank_account);
  ~BankAccount();
  explicit BankAccount(std::string);
  explicit BankAccount(std::string n, float b);

  void set_limit(float f);
  std::string get_name();
  void set_name(std::string n);
  void display();
  float get_balance();
  void set_balance(float b);
  void display_transaction_report() const;
};

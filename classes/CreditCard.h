#pragma once
#include <string>

class CreditCard {
private:
  float limit;
  std::string name;

public:
  CreditCard(std::string name, float limit);
  CreditCard(const CreditCard &credit_card);
  ~CreditCard();
  std::string get_name();
  void set_name(std::string n);
  void display();
  float get_limit();
  void set_limit(float b);
};

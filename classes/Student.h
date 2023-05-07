#pragma once
#include <string>
#include <vector>

class Student {
private:
  std::string id;
  float tuition;
  std::string name;
  float gpa;

public:
  Student() = default;

  float get_tuition();
  float get_gpa();
  std::string get_name();
  std::string get_id();

  void set_tuition(float t);
  void set_gpa(float g);
  void set_name(std::string n);
  void set_id(std::string id);
};

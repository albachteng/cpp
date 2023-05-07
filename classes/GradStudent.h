#pragma once
#include "Student.h"
#include <string>

class GraduateStudent : private Student {
private:
  bool scholarship;

public:
  using Student::get_gpa;
  using Student::get_name;
  using Student::set_gpa;
  using Student::set_name;
  GraduateStudent() = default;
  bool has_scholarship() const;
  void set_scholarship(bool b);
  void display();
};

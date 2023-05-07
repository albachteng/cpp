#pragma once
#include "Student.h"
#include <string>

class GraduateStudent : public Student {
private:
  bool scholarship;

public:
  GraduateStudent() = default;
  bool has_scholarship() const;
  void set_scholarship(bool b);
  void display();
};

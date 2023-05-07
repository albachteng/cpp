#pragma once
#include "Student.h"
#include <string>

class GraduateStudent : public Student {
public:
  bool scholarship;
  GraduateStudent() = default;
  bool has_scholarship() const;
};

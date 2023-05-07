#include "GradStudent.h"
#include <iostream>
#include <string>

using std::boolalpha;
using std::cout;
using std::endl;
using std::string;

bool GraduateStudent::has_scholarship() const { return scholarship; }

void GraduateStudent::set_scholarship(bool b) { scholarship = b; }

void GraduateStudent::display() {
  cout << "Grad name: " << get_name() << " gpa: " << get_gpa()
       << " scholarship: " << boolalpha << scholarship << endl;
}

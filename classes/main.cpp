#include "BankAccount.h"
#include "GradStudent.h"
#include <ios>
#include <iostream>
#include <type_traits>

using std::cout;
using std::endl;

int main() {
  Student student;
  GraduateStudent grad_student;

  cout << "student: " << typeid(student).name() << endl;
  cout << "grad student: " << typeid(grad_student).name() << endl;

  cout << "Student is a base class of GraduateStudent: " << std::boolalpha
       << std::is_base_of<Student, GraduateStudent>() << endl;
  cout << "Graduatestudent is a base class of Student: " << std::boolalpha
       << std::is_base_of<GraduateStudent, Student>() << endl;
}

#include "BankAccount.h"
#include "GradStudent.h"
#include <ios>
#include <iostream>
#include <type_traits>

using std::boolalpha;
using std::cout;
using std::endl;

int main() {
  Student student = Student();
  GraduateStudent grad_student = GraduateStudent();

  student.name = "Ethan";
  student.gpa = 3.7f;

  grad_student.name = "Vera";
  grad_student.gpa = 2.9f;
  grad_student.scholarship = true;

  cout << "Student name: " << student.get_name()
       << " gpa: " << student.get_gpa() << endl;

  cout << "Grad name: " << grad_student.get_name()
       << " gpa: " << grad_student.get_gpa() << " scholarship: " << boolalpha
       << grad_student.has_scholarship() << endl;
}

#include "BankAccount.h"
#include "GradStudent.h"
#include <ios>
#include <iostream>
#include <type_traits>

using std::cout;
using std::endl;

int main() {
  Student student = Student();
  GraduateStudent grad_student = GraduateStudent();

  student.set_name("Ethan");
  student.set_tuition(3.7f);

  grad_student.set_name("Vera");
  grad_student.set_gpa(2.9f);
  grad_student.set_scholarship(true);

  cout << "Student name: " << student.get_name()
       << " gpa: " << student.get_gpa() << endl;

  grad_student.display();
}

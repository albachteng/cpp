#include "Student.h"
#include <iostream>
#include <string>

// using std::cout;
// using std::endl;
using std::string;

std::string Student::get_name() { return name; }
std::string Student::get_id() { return id; }
float Student::get_tuition() { return tuition; }
float Student::get_gpa() { return gpa; }

void Student::set_name(std::string n) { name = n; }
void Student::set_id(std::string i) { id = i; }
void Student::set_tuition(float t) { tuition = t; }
void Student::set_gpa(float g) { gpa = g; }

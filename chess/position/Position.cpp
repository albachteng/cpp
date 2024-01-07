#include "Position.h"
#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

Position::Position(uint r, enum file f) : rank(r), file(f) {
  cout << "position: " << file << rank << endl;
};

enum file Position::get_file() { return file; }
uint Position::get_rank() { return rank; }

void Position::set_rank(uint r) { rank = r; }
void Position::set_file(enum file f) { file = f; }

void Position::display() {
  cout << "rank: " << rank << " file: " << file << endl;
}

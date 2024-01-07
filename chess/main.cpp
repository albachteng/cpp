#include "./pieces/Pawn.h"
#include "./pieces/Piece.h"
#include "./position/Position.h"
#include <iostream>

using std::cout;
using std::endl;

int main() {
  Position pos{0, A};
  Piece *p = new Pawn(pos);
  p->get_position().display();
  cout << p->get_name() << endl;
  p->move();
  p->get_position().display();
  return 1;
}

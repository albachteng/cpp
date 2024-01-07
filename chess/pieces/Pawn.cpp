#include "Pawn.h"
#include "../position/Position.h"
#include "iostream"

using std::cout;
using std::endl;

Pawn::Pawn(Position pos) : Piece(pos, "Pawn") {}

Position Pawn::move() {
  cout << "before: " << endl;
  pos.display();
  cout << "after: " << endl;
  Position new_pos{pos.get_rank() + 1, pos.get_file()};
  Pawn::set_pos(new_pos);
  return new_pos;
}

#include "Piece.h"
#include <iostream>

Piece::Piece(Position pos, std::string name) : pos(pos), name(name) {}

Position Piece::get_position() { return pos; }
std::string Piece::get_name() { return name; }

void Piece::set_pos(Position p) { pos = p; }

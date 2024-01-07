#pragma once
#include "../position/Position.h"
#include <iostream>
#include <string>

class Piece {
public:
  Piece(Position pos, std::string name);
  std::string name;
  Position pos;

  void set_pos(Position p);
  virtual Position move() = 0;
  std::string get_name();
  Position get_position();
};

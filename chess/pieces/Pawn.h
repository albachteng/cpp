#pragma once
#include "Piece.h"

class Pawn : public Piece {
public:
  Pawn(Position pos);

  Position move() override;
};

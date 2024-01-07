#pragma once

#include <iostream>
#include <string>

enum file {
  A,
  B,
  C,
  D,
  E,
  F,
  G,
  H,
};

class Position {
private:
  file file;
  uint rank;

public:
  Position() = delete;
  Position(uint rank, enum file file);
  void display();
  void set_rank(uint r);
  void set_file(enum file f);
  uint get_rank();
  enum file get_file();
};

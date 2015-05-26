
#pragma once
#include "../object.h"


class Player : public Object {
private:

public:
  Player();
  ~Player() = default;

  void update();
  void draw();
};
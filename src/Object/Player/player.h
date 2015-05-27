
#pragma once
#include "../object.h"
#include "../../MyLib/ci_app.h"


class Player : public Object {
private:
  struct Face {
    Vec3f v1, v2, v3;
    ColorA color;
  };
  std::vector<Face> faces;

  float ry;

public:
  Player();
  ~Player() = default;

  void update();
  void draw();
};
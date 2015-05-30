
#pragma once
#include "../../MyLib/ci_app.h"
#include "../Model/model.h"
#include "../object.h"


class Player : public Object {
private:
  Model m_model;

  float ry;

public:
  Player();
  ~Player() = default;

  void update();
  void draw();
};
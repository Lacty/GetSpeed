
#pragma once
#include "../../MyLib/ci_app.h"
#include "../Model/model.h"
#include "../object.h"
#include <memory>


class PlayerAdvancer;

class Player : public Object {
private:
  Model m_model;
  std::shared_ptr<PlayerAdvancer> adv;

  float ry;

public:
  Player();
  ~Player() = default;

  void update();
  void draw();
};
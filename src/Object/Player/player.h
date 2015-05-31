
#pragma once
#include "../../MyLib/ci_app.h"
#include "../Model/model.h"
#include "../object.h"
#include <memory>


class PlayerAdvancer;
class PlayerRotater;

class Player : public Object {
private:
  Model m_model;
  std::shared_ptr<PlayerAdvancer> advance;
  std::shared_ptr<PlayerRotater> rotate;

  float ry;

public:
  Player();
  ~Player() = default;

  void update();
  void draw();
};
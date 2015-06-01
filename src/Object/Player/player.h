
#pragma once
#include "../../MyLib/ci_app.h"
#include "../Model/model.h"
#include "../object.h"
#include <memory>


class PlayerAdvancer;
class PlayerMover;
class PlayerRotater;

class Player : public Object {
private:
  Model m_model;
  std::shared_ptr<PlayerAdvancer> advance;
  std::shared_ptr<PlayerMover> move;
  std::shared_ptr<PlayerRotater> rotate;

  Vec3f m_pos;
  Vec3f m_rotate;
  Vec3f m_scale;

public:
  Player();
  ~Player() = default;

  void update();
  void draw();
};
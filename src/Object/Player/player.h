
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
  std::shared_ptr<PlayerAdvancer> p_advance;
  std::shared_ptr<PlayerMover>    p_move;
  std::shared_ptr<PlayerRotater>  p_rotate;

  Vec3f m_pos;
  Vec3f m_rotate;
  Vec3f m_scale;

  float m_angle;
  float m_pitch;
  void  pitch();

public:
  Player();
  ~Player() = default;

  void update();
  void draw();

  Vec3f& getPos();
  Vec3f& getRotate();
  float& getPitch();
  float& getSpeed();
};

#pragma once
#include "../../MyLib/ci_app.h"
#include "../object.h"
#include <memory>


class Player;

class PlayerEffect : public Object {
private:
  Vec3f m_pos;

  struct Circle {
    bool  isActive;
    Vec3f pos;
    Vec3f scale;
  };

  std::shared_ptr<Player> p_player;

  void createCircle();
  void scaleCircle();
  void killCircle();

public:
  PlayerEffect();
  ~PlayerEffect();

  void update();
  void draw();
};
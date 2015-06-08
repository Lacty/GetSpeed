
#pragma once
#include "../../MyLib/ci_app.h"
#include "../object.h"
#include <memory>


class Player;

class PlayerEffect : public Object {
private:
  Vec3f m_pos;
  Vec3f m_rotate;

  Vec3f m_left_pos;
  Vec3f m_right_pos;

  struct Effect {
    float anim;
    float pos_z;
    Vec3f rotate;
    Vec3f scale;
  };
  std::list<Effect> left;
  std::list<Effect> right;

  std::shared_ptr<Player> p_player;

  void dataAcquisition();
  void effectTrigger();
  Effect createEffect();
  void increaseAnim();
  void scaleEffect();
  void moveEffect();

public:
  PlayerEffect();
  ~PlayerEffect();

  void update();
  void draw();
};
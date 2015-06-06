
#pragma once
#include "../../MyLib/ci_app.h"
#include "../object.h"
#include <memory>


class Player;

class Booster : public Object {
private:
  Vec3f m_rotate;
  Vec3f m_scale;

  enum { Boost_Num = 1 };
  struct Boost {
    Vec3f pos;
    Vec3f size;
    bool isHit;
  } boost[Boost_Num];

  std::shared_ptr<Player> p_player;
  Vec3f player_last_pos;

  void isCollision();
  void loop();

public:
  Booster();
  ~Booster();

  void update();
  void draw();

  bool isCollisionToBooster();
};
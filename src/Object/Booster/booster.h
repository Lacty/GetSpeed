
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

  enum { PlusSpeed = 300 };
  float m_eye_anim_z;
  float m_eye_anim;
  bool isEyeAnim;
  bool isSpeedUp;
  void moveCamera();

public:
  Booster();
  ~Booster();

  void update();
  void draw();

  bool isCollisionToBooster();
  float getEyePosZ() const;
};
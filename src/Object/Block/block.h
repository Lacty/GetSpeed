
#pragma once
#include "../../MyLib/ci_app.h"
#include "../object.h"
#include <memory>


class Player;

class Block : public Object {
private:
  enum { Block_Num = 4 };
  struct sBlock {
    Vec3f pos;
    Vec3f size;
    bool isHit;
  } block[Block_Num];

  std::shared_ptr<Player> p_player;
  Vec3f player_last_pos;

  void Collision();
  void loop();

  enum { MinusSpeed = -1000 };
  float m_eye_anim_z;
  float m_eye_anim;
  bool isEyeAnim;
  bool isSpeedUp;
  void moveCamera();


public:
  Block();
  ~Block();

  void update();
  void draw();

  float getEyePosZ() const;
  bool isCollisionToPlayer() const;
};
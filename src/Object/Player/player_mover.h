
#pragma once
#include "../../MyLib/ci_app.h"
#include "../object.h"


class PlayerMover : public Object {
private:
  Vec3f m_pos;

  // ˆÚ“®‚ÍŠï”‚ğg‚¤‚Æƒkƒ‹ƒkƒ‹“®‚­
  // ‹ô”‚¾‚ÆƒJƒN‚Â‚¢‚Ä‚¢‚é‚æ‚¤‚ÉŒ©‚¦‚é
  const float Move_Speed = 3;

  void move();
  void bound();

public:
  PlayerMover();
  ~PlayerMover();

  void update();
  void draw();

  float& getPos();
};
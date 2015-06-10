
#pragma once
#include "../../MyLib/ci_app.h"
#include "../object.h"
#include <memory>


class PlayerLife;

class PlayerMover : public Object {
private:
  std::shared_ptr<PlayerLife> p_life;

  Vec3f m_pos;

  // ˆÚ“®‚ÍŠï”‚ğg‚¤‚Æƒkƒ‹ƒkƒ‹“®‚­
  // ‹ô”‚¾‚ÆƒJƒN‚Â‚¢‚Ä‚¢‚é‚æ‚¤‚ÉŒ©‚¦‚é
  const float Move_Speed = 5;

  void move();
  void bound();

public:
  PlayerMover();
  ~PlayerMover();

  void update();
  void draw();

  float& getPos();
};
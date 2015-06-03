
#pragma once
#include "../../object.h"
#include <memory>


class Player;

class SpeedMeter : public Object {
private:
  std::shared_ptr<Player> p_player;
  Vec3f m_pos;
  Vec3f m_rotate;
  Vec3f m_scale;

  std::unique_ptr<Font> m_font;

public:
  SpeedMeter();
  ~SpeedMeter();

  void update();
  void draw();
};
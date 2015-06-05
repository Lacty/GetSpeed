
#pragma once
#include "../../../MyLib/ci_app.h"
#include "../../object.h"
#include <memory>


class Player;

class OdoMeter : public Object {
private:
  Vec3f m_pos;
  Vec3f m_rotate;
  Vec3f m_scale;
  std::unique_ptr<Font> p_font;

  std::shared_ptr<Player> p_player;


public:
  OdoMeter();
  ~OdoMeter();

  void update();
  void draw();
};
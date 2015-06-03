
#pragma once
#include "../../MyLib/ci_app.h"
#include "../object.h"
#include <memory>


class Player;

class StageRing : public Object {
private:
  enum { Ring_Max = 8 };

  Vec3f m_pos[Ring_Max];
  Color m_color[Ring_Max];
  Vec3f m_rotate;
  Vec3f m_scale;

  std::shared_ptr<Player> p_player;

  void loop();

public:
  StageRing();
  ~StageRing();

  void update();
  void draw();
};
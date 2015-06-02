
#pragma once
#include "../../MyLib/ci_app.h"
#include "../Model/model.h"
#include "../object.h"
#include <memory>


class Player;

class Road : public Object {
private:
  enum { Model_Max = 20 };
  Model m_model;

  Vec3f m_rotate;
  Vec3f m_scale;
  Vec3f m_pos[Model_Max];

  std::shared_ptr<Player> p_player;

public:
  Road();
  ~Road() = default;

  void update();
  void draw();
};
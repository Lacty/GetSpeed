
#pragma once
#include "../../MyLib/ci_app.h"
#include "../object.h"
#include <memory>
#include <chrono>


class Player;

class TimeCounter : public Object {
private:
  Vec3f m_pos;
  Vec3f m_rotate;
  Vec3f m_scale;

  bool isStart;

  Font default_font;
  std::shared_ptr<Player> p_player;

  typedef std::chrono::time_point<std::chrono::system_clock, std::chrono::system_clock::duration> time_point;
  time_point m_start;
  time_point m_now;

  std::string count();

public:
  TimeCounter();
  ~TimeCounter();

  void update();
  void draw();
};
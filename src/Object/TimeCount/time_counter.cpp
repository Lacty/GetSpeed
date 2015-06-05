
#include "../Player/player.h"
#include "time_counter.h"
#include "../task.h"
#include <sstream>


TimeCounter::TimeCounter() :
m_pos(Vec3f::zero()),
m_rotate(Vec3f(180, 0, 20)),
m_scale(Vec3f(1, 1, 1)),
isStart(false),
p_font(std::make_unique<Font>(Font("", 60)))
{
  m_name = std::string("Counter");
  p_player = std::dynamic_pointer_cast<Player>(Task::getInstance().find("Player"));

  Vec3f offset = Vec3f(140, 40, -600);
  Vec3f pos = Vec3f(0, 0, p_player->getPos().z);
  m_pos = offset + pos;
}

TimeCounter::~TimeCounter() {}


void TimeCounter::update() {
  Vec3f offset = Vec3f(140, 40, -600);
  Vec3f pos = Vec3f(0, 0, p_player->getPos().z);
  m_pos = offset + pos;

  if (isStart) {
    m_now = std::chrono::system_clock::now();
  } else {
    m_start = std::chrono::system_clock::now();
    isStart = true;
  }
}


std::string TimeCounter::count() {
  auto count = m_now - m_start;
  int millisec;
  millisec = std::chrono::duration_cast<std::chrono::milliseconds>(count).count() / 100 % 10;
  int sec;
  sec = std::chrono::duration_cast<std::chrono::milliseconds>(count).count() / 1000 % 60;
  int minute;
  minute = std::chrono::duration_cast<std::chrono::minutes>(count).count();
  std::ostringstream str_count;
  str_count << minute << ":" << sec << ":" << millisec;
  return str_count.str();
}

void TimeCounter::draw() {
  gl::pushModelView();
  {
    gl::translate(m_pos);
    gl::scale(m_scale);
    gl::rotate(m_rotate);
    gl::drawStringCentered(count(), Vec2f::zero(), Color(0.6, 0.6, 0.6), *p_font);
  }
  gl::popModelView();
}
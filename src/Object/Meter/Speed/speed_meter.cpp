
#include "../../Player/player.h"
#include "../../task.h"
#include <sstream>
#include "speed_meter.h"


SpeedMeter::SpeedMeter() :
m_pos(Vec3f::zero()),
m_rotate(Vec3f(180, 0, 0)),
m_scale(Vec3f(0.3f, 0.3f, 0.3f)),
m_font(std::make_unique<Font>(Font("", 60)))
{
  m_name = std::string("SpeedMeter");
  p_player = std::dynamic_pointer_cast<Player>(Task::getInstance().find("Player"));
}

SpeedMeter::~SpeedMeter() {}


void SpeedMeter::update() {
  m_pos = Vec3f(p_player->getPos());
}

void SpeedMeter::draw() {
  std::ostringstream speed;
  speed << int(p_player->getSpeed());

  gl::pushModelView();
  {
    gl::translate(m_pos);
    gl::scale(m_scale);
    gl::rotate(m_rotate);
    gl::drawStringCentered(speed.str(), Vec2f::zero(), Color::white(), *m_font);
  }
  gl::popModelView();
}
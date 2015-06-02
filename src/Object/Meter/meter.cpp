
#include "../../MyLib/graph.h"
#include "../Player/player.h"
#include "../task.h"
#include <sstream>
#include "meter.h"


Meter::Meter() :
m_pos(Vec3f::zero()),
m_rotate(Vec3f(180, 0, 0)),
m_scale(Vec3f(0.4f, 0.4f, 0.4f)),
m_font(std::make_unique<Font>(Font("", 60)))
{
  m_name = std::string("Meter");
  player = std::dynamic_pointer_cast<Player>(Task::getInstance().find("Player"));
}

Meter::~Meter() {}


void Meter::update() {
  m_pos = Vec3f(player->getPos());
}

void Meter::draw() {
  std::ostringstream speed;
  speed << int(player->getSpeed());

  gl::pushModelView();
  {
    gl::translate(m_pos);
    gl::scale(m_scale);
    gl::rotate(m_rotate);
    gl::drawStringCentered(speed.str(), Vec2f(0, 0), Color::white(), *m_font);
  }
  gl::popModelView();
}
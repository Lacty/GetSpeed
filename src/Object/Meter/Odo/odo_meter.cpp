
#include "../../Player/player.h"
#include "../../task.h"
#include "odo_meter.h"
#include <sstream>


OdoMeter::OdoMeter() :
m_pos(Vec3f::zero()),
m_rotate(Vec3f(180, 0, 0)),
m_scale(Vec3f(1, 1, 1)),
m_font(std::make_unique<Font>(Font("", 60)))
{
  m_name = std::string("OdoMeter");
  p_player = std::dynamic_pointer_cast<Player>(Task::getInstance().find("Player"));
}

OdoMeter::~OdoMeter() {}


void OdoMeter::update() {
  Vec3f offset = Vec3f(0, 78, -600);
  Vec3f pos    = Vec3f(0,  0, p_player->getPos().z);
  m_pos = pos + offset;
}

void OdoMeter::draw() {
  std::ostringstream odo;
  odo << int(p_player->getPos().z) * -1;

  gl::pushModelView();
  {
    gl::translate(m_pos);
    gl::scale(m_scale);
    gl::rotate(m_rotate);
    gl::drawStringCentered(odo.str(), Vec2f::zero(), Color(0.6, 0.6, 0.6), *m_font);
  }
  gl::popModelView();
}
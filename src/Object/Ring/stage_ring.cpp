
#include "../../MyLib/ci_app.h"
#include "../Player/player.h"
#include "stage_ring.h"
#include "../task.h"


StageRing::StageRing() :
m_rotate(Vec3f::zero()),
m_scale(Vec3f(12, 10, 100))
{
  m_name = std::string("StageRing");
  p_player = std::dynamic_pointer_cast<Player>(Task::getInstance().find("Player"));
  for (int i = 0; i < Ring_Max; ++i) {
    m_pos[i] = Vec3f(0, 0, -i * 6);
  }
}

StageRing::~StageRing() {}


void StageRing::loop() {
  float offset = -150;
  for (int i = 0; i < Ring_Max; ++i) {
    if (m_pos[i].z * m_scale.z + offset > p_player->getPos().z) {
      m_pos[i].z -= Ring_Max * 6;
    }
  }
}

void StageRing::update() {
  loop();
}

void StageRing::draw() {
  gl::pushModelView();
  gl::enableDepthRead();

  gl::rotate(m_rotate);
  gl::scale(m_scale);

  for (int i = 0; i < Ring_Max; ++i) {
    gl::pushModelView();
    {
      gl::translate(m_pos[i]);
      gl::drawTorus(10, 1, 12, 40);
    }
    gl::popModelView();
  }

  gl::disableDepthRead();
  gl::popModelView();
}
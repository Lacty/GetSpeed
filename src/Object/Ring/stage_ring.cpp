
#include "../../MyLib/ci_app.h"
#include "../Booster/booster.h"
#include "../Player/player.h"
#include "stage_ring.h"
#include "../task.h"


StageRing::StageRing() :
m_rotate(Vec3f::zero()),
m_scale(Vec3f(12, 10, 100)),
count(0.f),
red(0.5f),
green(0.5f),
isBoost(false)
{
  m_name = std::string("StageRing");
  p_player = std::dynamic_pointer_cast<Player>(Task::getInstance().find("Player"));
  p_booster = std::dynamic_pointer_cast<Booster>(Task::getInstance().find("Booster"));
  for (int i = 0; i < Ring_Max; ++i) {
    m_pos[i] = Vec3f(0, 0, -i * 6);
  }
}

StageRing::~StageRing() {}


void StageRing::boost() {
  if (!isBoost) return;

  count += 0.04f;
  red = 0.5f + sin(count) * 0.5f;
  green = 0.5f - sin(count) * 0.5f;
  if (red <= 0.5f) {
    red = 0.5f;
    green = 0.5f;
    count = 0;
    isBoost = false;
  }
}

void StageRing::loop() {
  float offset = -150;
  for (int i = 0; i < Ring_Max; ++i) {
    if (m_pos[i].z * m_scale.z + offset > p_player->getPos().z) {
      m_pos[i].z -= Ring_Max * 6;
    }
  }
}

void StageRing::update() {
  if (p_booster->isCollisionToPlayer()) { isBoost = true; }
  boost();
  loop();
}

void StageRing::draw() {
  gl::pushModelView();
  gl::enableDepthRead();

  gl::color(ColorA(red, 0.5f, green, 0.5f));
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
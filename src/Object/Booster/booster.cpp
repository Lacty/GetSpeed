
#include "../../Collision/collision.h"
#include "../Player/player.h"
#include "../../road_size.h"
#include "cinder/Rand.h"
#include "../task.h"
#include "booster.h"


Booster::Booster() :
m_eye_anim_z(0.0f),
m_eye_anim(0.0f),
isEyeAnim(false),
isSpeedUp(false)
{
  m_name = std::string("Booster");
  p_player = std::dynamic_pointer_cast<Player>(Task::getInstance().find("Player"));

  //-------------------------------------------------------
  // BoostÇÃèâä˙âª
  for (int i = 0; i < Boost_Num; ++i) {
    boost[i].pos = Vec3f(Rand::randFloat(LeftEdge + boost[i].size.x * 0.5f,
                                         RightEdge - boost[i].size.x * 0.5f),
                          0,
                          Rand::randFloat(Depth, Depth * 2));
    boost[i].size = Vec3f(30, 30, 30);
    boost[i].isHit = false;
  }
  player_last_pos = p_player->getPos();
}

Booster::~Booster() {}


void Booster::Collision() {
  for (int i = 0; i < Boost_Num; ++i) {
    if (ly::collisionLineToLine(Vec2f(boost[i].pos.x - boost[i].size.x, boost[i].pos.z),
                                Vec2f(boost[i].pos.x + boost[i].size.x, boost[i].pos.z),
                                Vec2f(p_player->getPos().x, p_player->getPos().z),
                                Vec2f(player_last_pos.x, player_last_pos.z)))
    {
      boost[i].isHit = true;
    } else {
      boost[i].isHit = false;
    }
  }
  player_last_pos = p_player->getPos();
}

void Booster::loop() {
  float bound_line = p_player->getPos().z + p_player->getSpeed() * 2;
  for (int i = 0; i < Boost_Num; ++i) {
    if (boost[i].pos.z > bound_line) {
      boost[i].pos = Vec3f(Rand::randFloat(LeftEdge + boost[i].size.x * 0.5f,
                                           RightEdge - boost[i].size.x * 0.5f),
                           0,
                           Rand::randFloat(Depth, Depth * 2) + p_player->getPos().z);
    }
  }
}

void Booster::update() {
  loop();
  Collision();
  moveCamera();
}

void Booster::draw() {
  gl::enableDepthRead();
  for (int i = 0; i < Boost_Num; ++i) {
    gl::pushModelView();
    gl::color(Color(1, 0.6, 0));
    gl::translate(boost[i].pos);
    gl::drawTorus(30, 3, 12, 10);
    gl::popModelView();
  }
  gl::disableDepthRead();
}

bool Booster::isCollisionToPlayer() {
  for (int i = 0; i < Boost_Num; ++i) {
    if (boost[i].isHit) return true;
  }
  return false;
}

void Booster::moveCamera() {
  if (isCollisionToPlayer()) {
    isEyeAnim = true;
  }

  if (isEyeAnim) {
    if (!isSpeedUp) {
      p_player->getSpeed() += PlusSpeed;
      isSpeedUp = true;
    }

    m_eye_anim += 0.04;
    m_eye_anim_z = sin(m_eye_anim) * 10;
    if (m_eye_anim_z <= 0) {
      m_eye_anim = 0;
      m_eye_anim_z = 0;
      isEyeAnim = false;
      isSpeedUp = false;
    }
  }
}

float Booster::getEyePosZ() const{
  return m_eye_anim_z;
}
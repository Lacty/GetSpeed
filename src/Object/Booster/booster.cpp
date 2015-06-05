
#include "../../Collision/collision.h"
#include "../Player/player.h"
#include "../../road_size.h"
#include "cinder/Rand.h"
#include "../task.h"
#include "booster.h"


Booster::Booster() :
m_rotate(Vec3f::zero()),
m_scale(Vec3f(1, 1, 1))
{
  m_name = std::string("Booster");
  p_player = std::dynamic_pointer_cast<Player>(Task::getInstance().find("Player"));
  for (int i = 0; i < Boost_Num; ++i) {
    boost[i].pos  = Vec3f(Rand::randFloat(LeftEdge, RightEdge),
                          15,
                          Rand::randFloat(Depth, Depth * 2));
    boost[i].size = Vec3f(30, 30, 30);
  }
  player_last_pos = p_player->getPos();
}

Booster::~Booster() {}


void Booster::isCollision() {
  for (int i = 0; i < Boost_Num; ++i) {
    if (ly::collisionLineToLine(Vec2f(boost[i].pos.x - boost[i].size.x, boost[i].pos.z),
                                Vec2f(boost[i].pos.x + boost[i].size.x, boost[i].pos.z),
                                Vec2f(p_player->getPos().x, p_player->getPos().z),
                                Vec2f(player_last_pos.x, player_last_pos.z)))
    {
      // デバッグ用サイズ変更
      boost[i].size = Vec3f(10, 10, 10);
    }
  }
  player_last_pos = p_player->getPos();
}

void Booster::loop() {
  float bound_line = p_player->getPos().z + p_player->getSpeed();
  for (int i = 0; i < Boost_Num; ++i) {
    if (boost[i].pos.z > bound_line) {
      boost[i].pos = Vec3f(Rand::randFloat(LeftEdge, RightEdge),
                           15,
                           Rand::randFloat(Depth, Depth * 2) + p_player->getPos().z);
    }
  }
}

void Booster::update() {
  loop();
  isCollision();
}

void Booster::draw() {
  for (int i = 0; i < Boost_Num; ++i) {
    gl::drawStrokedCube(boost[i].pos, boost[i].size);
  }
}
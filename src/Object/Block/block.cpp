
#include "../../Collision/collision.h"
#include "../Player/player.h"
#include "../../road_size.h"
#include "cinder/Rand.h"
#include "../task.h"
#include "block.h"


Block::Block() :
m_eye_anim_z(0.0f),
m_eye_anim(0.0f),
isEyeAnim(false),
isSpeedUp(false)
{
  m_name = std::string("Block");
  p_player = std::dynamic_pointer_cast<Player>(Task::getInstance().find("Player"));

  //-------------------------------------------------------
  // BlockÇÃèâä˙âª
  for (int i = 0; i < Block_Num; ++i) {
    block[i].pos = Vec3f(Rand::randFloat(LeftEdge + block[i].size.x * 0.2,
                                         RightEdge - block[i].size.x * 0.2),
                         15,
                         Rand::randFloat(Depth, Depth * 3));
    block[i].size = Vec3f(60, 30, 30);
    block[i].isHit = false;
  }
  player_last_pos = p_player->getPos();
}

Block::~Block() {}


void Block::Collision() {
  for (int i = 0; i < Block_Num; ++i) {
    if (ly::collisionLineToLine(Vec2f(block[i].pos.x - block[i].size.x * 0.5f, block[i].pos.z),
                                Vec2f(block[i].pos.x + block[i].size.x * 0.5f, block[i].pos.z),
                                Vec2f(p_player->getPos().x, p_player->getPos().z),
                                Vec2f(player_last_pos.x, player_last_pos.z))) {
      block[i].isHit = true;
    } else {
      block[i].isHit = false;
    }
  }
  player_last_pos = p_player->getPos();
}

void Block::loop() {
  float bound_line = p_player->getPos().z + p_player->getSpeed() * 2;
  for (int i = 0; i < Block_Num; ++i) {
    if (block[i].pos.z > bound_line) {
      block[i].pos = Vec3f(Rand::randFloat(LeftEdge + block[i].size.x * 0.2,
                                           RightEdge - block[i].size.x * 0.2),
                           15,
                           Rand::randFloat(Depth, Depth * 3) + p_player->getPos().z);
    }
  }
}

void Block::update() {
  loop();
  Collision();
  moveCamera();
}

void Block::draw() {
  gl::enableDepthRead();
  for (int i = 0; i < Block_Num; ++i) {
    gl::pushModelView();
    gl::color(ColorA(0.4, 0.4, 0.4, 0.6));
    gl::drawCube(block[i].pos, block[i].size);
    gl::popModelView();
  }
  gl::disableDepthRead();
}

bool Block::isCollisionToPlayer() {
  for (int i = 0; i < Block_Num; ++i) {
    if (block[i].isHit) return true;
  }
  return false;
}

void Block::moveCamera() {
  if (isCollisionToPlayer()) {
    isEyeAnim = true;
  }

  if (isEyeAnim) {
    if (!isSpeedUp) {
      if (p_player->getSpeed() < (MinusSpeed * -1)) {
        p_player->getSpeed() = 0.0f;
      } else {
        p_player->getSpeed() += MinusSpeed;
      }
      isSpeedUp = true;
    }

    m_eye_anim += 0.04;
    m_eye_anim_z = -sin(m_eye_anim) * 10;
    if (m_eye_anim_z >= 0) {
      m_eye_anim = 0;
      m_eye_anim_z = 0;
      isEyeAnim = false;
      isSpeedUp = false;
    }
  }
}

float Block::getEyePosZ() const {
  return m_eye_anim_z;
}
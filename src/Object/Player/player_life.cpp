
#include "../../MyLib/key.h"
#include "../Block/block.h"
#include "player_life.h"
#include "../task.h"
#include "player.h"


PlayerLife::PlayerLife() :
m_rotate(0, 0, 0),
m_scale(5, 5, 5),
m_life(Life_Max),
m_model("Normal")
{
  m_name = std::string("PlayerLife");
  p_block = std::dynamic_pointer_cast<Block>(Task::getInstance().find("Block"));
  p_player = std::dynamic_pointer_cast<Player>(Task::getInstance().find("Player"));

  Vec3f offset = Vec3f(-100, 40, -600);
  m_pos = Vec3f(0, 0, p_player->getPos().z) + offset;
}

PlayerLife::~PlayerLife() {}


void PlayerLife::lifeManage() {
  if (m_life != 0) {
    if (p_block->isCollisionToPlayer()) {
      --m_life;
    }
  }
  //-------------------------------------------------------
  // デバッグ用 z を押すとLifeが増える
  if (Key::get().isPush(KeyEvent::KEY_z)) m_life++;
}

void PlayerLife::moveGuage() {
  Vec3f pos = Vec3f(0, 0, p_player->getPos().z);
  Vec3f offset = Vec3f(-100, 40, -600);
  m_pos = pos + offset;
}

void PlayerLife::update() {
  lifeManage();
  moveGuage();
}

void PlayerLife::draw() {
  gl::pushModelView();

  gl::translate(m_pos);
  gl::rotate(m_rotate);
  gl::rotate(Vec3f(0, 0, 30));
  gl::scale(m_scale);
  
  for (int i = 0; i < m_life; ++i) {
    gl::pushModelView();
    {
      gl::translate(Vec3f(-6*i, 0, 0));
      gl::draw(m_model.get());
      m_model.drawWire();
    }
    gl::popModelView();
  }

  gl::popModelView();
}


int PlayerLife::getLife() const {
  return m_life;
}
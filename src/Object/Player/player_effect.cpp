
#include "player_effect.h"
#include "../task.h"
#include "player.h"

#include "../../MyLib/key.h"


PlayerEffect::PlayerEffect() :
m_left_pos(-8, 2, 0),
m_right_pos(8, 2, 0),
trigger(0)
{
  m_name = std::string("PlayerEffect");
  p_player = std::dynamic_pointer_cast<Player>(Task::getInstance().find("Player"));
  m_pos = p_player->getPos();
  m_rotate = p_player->getRotate();
}

PlayerEffect::~PlayerEffect() {}


void PlayerEffect::dataAcquisition() {
  float offset = 20;
  m_pos = Vec3f(p_player->getPos().x,
                p_player->getPos().y + p_player->getPitch(),
                p_player->getPos().z + offset);
  m_rotate = Vec3f(0, 0, -p_player->getRotate().y);
}

void PlayerEffect::effectTrigger() {

}

PlayerEffect::Effect PlayerEffect::createEffect() {
  Effect effect;
  effect.anim  = 0.0f;
  effect.pos_z = 0.0f;
  effect.rotate = m_rotate;
  effect.scale = Vec3f::one();
  return effect;
}

void PlayerEffect::increaseAnim() {
  for (auto& it : left) {
    it.anim += 0.04f;
  }
  for (auto& it : right) {
    it.anim += 0.04f;
  }
}

void PlayerEffect::scaleEffect() {
  for (auto& it : left) {
    it.cos = cos(it.anim);
    it.scale = Vec3f(it.cos, it.cos, 0);
  }
  for (auto& it : right) {
    it.cos = cos(it.anim);
    it.scale = Vec3f(it.cos, it.cos, 0);
  }
}

void PlayerEffect::moveEffect() {
  for (auto& it : left) {
    it.pos_z += it.anim;
  }
  for (auto& it : right) {
    it.pos_z += it.anim;
  }
}

void PlayerEffect::destroyEffect() {
  std::list<Effect>::iterator it = left.begin();
  while (it != left.end()) {
    if (it->Destroy()) {
      it = left.erase(it);
    }
    ++it;
  }

  it = right.begin();
  while (it != right.end()) {
    if (it->Destroy()) {
      it = right.erase(it);
    }
    ++it;
  }
}

void PlayerEffect::update() {}

void PlayerEffect::draw() {
  dataAcquisition();

  trigger++;
  if (trigger % 6 == 1) {
    left.emplace_back(createEffect());
    right.emplace_back(createEffect());
  }

  increaseAnim();
  scaleEffect();
  moveEffect();
  destroyEffect();

  gl::pushModelView();
  gl::color(Color(0.4f, 0.4f, 0.4f));

  for (auto it : left) {
    gl::pushModelView();
    {
      gl::translate(Vec3f(m_pos.x, m_pos.y, m_pos.z + it.pos_z));
      gl::rotate(it.rotate);
      gl::translate(m_left_pos);
      gl::scale(it.scale);
      gl::drawSolidCircle(Vec2f::zero(), 2, 10);
    }
    gl::popModelView();
  }

  for (auto it : right) {
    gl::pushModelView();
    {
      gl::translate(Vec3f(m_pos.x, m_pos.y, m_pos.z + it.pos_z));
      gl::rotate(it.rotate);
      gl::translate(m_right_pos);
      gl::scale(it.scale);
      gl::drawSolidCircle(Vec2f::zero(), 2, 10);
    }
    gl::popModelView();
  }

  gl::popModelView();
}
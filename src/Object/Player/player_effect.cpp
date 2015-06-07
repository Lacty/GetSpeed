
#include "player_effect.h"
#include "../task.h"
#include "player.h"


PlayerEffect::PlayerEffect()
{
  m_name = std::string("PlayerEffect");
  p_player = std::dynamic_pointer_cast<Player>(Task::getInstance().find("Player"));
  Vec3f offset = Vec3f(0, 7, 30);
  m_pos = p_player->getPos() + offset;
}

PlayerEffect::~PlayerEffect() {}


void PlayerEffect::createCircle() {
  Vec3f offset = Vec3f(0, 7, 30);
  m_pos = p_player->getPos() + offset;
}

void PlayerEffect::scaleCircle() {

}

void PlayerEffect::killCircle() {

}

void PlayerEffect::update() {
  createCircle();
  scaleCircle();
  killCircle();
}

void PlayerEffect::draw() {

}
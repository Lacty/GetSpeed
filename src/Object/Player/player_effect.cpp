
#include "player_effect.h"
#include "../task.h"


PlayerEffect::PlayerEffect()
{
  m_name = std::string("PlayerEffect");
  p_player = std::dynamic_pointer_cast<Player>(Task::getInstance().find("Player"));
}

PlayerEffect::~PlayerEffect() {}


void PlayerEffect::update() {

}

void PlayerEffect::draw() {

}
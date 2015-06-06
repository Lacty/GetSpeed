
#pragma once
#include "../object.h"
#include <memory>


class Player;

class PlayerEffect : public Object {
private:
  std::shared_ptr<Player> p_player;

public:
  PlayerEffect();
  ~PlayerEffect();

  void update();
  void draw();
};
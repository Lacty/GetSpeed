
#pragma once
#include "../Model/model.h"
#include "../object.h"
#include <memory>


class Block;
class Player;

class PlayerLife : public Object {
private:
  Vec3f m_pos;
  Vec3f m_rotate;
  Vec3f m_scale;

  enum { Life_Max = 3 };
  int m_life;
  Model m_model;

  std::shared_ptr<Block> p_block;
  std::shared_ptr<Player> p_player;

  void lifeManage();
  void moveGuage();

public:
  PlayerLife();
  ~PlayerLife();

  void update();
  void draw();

  int getLife() const;
};
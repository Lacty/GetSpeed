
#include "../../MyLib/graph.h"
#include "../Player/player.h"
#include "../task.h"
#include "road.h"


Road::Road() :
m_model("Road"),
m_rotate(-90, 0, 0),
m_scale(100, 100, 100)
{
  m_name = std::string("Road");
  for (int i = 0; i < Model_Max; ++i) {
    m_pos[i] = Vec3f(0, i * 2, 0);
  }
}


void Road::update() {
  if (player == nullptr) {
    player = std::dynamic_pointer_cast<Player>(Task::getInstance().find("Player"));
  }
  for (int i = 0; i < Model_Max; ++i) {
    if (m_pos[i].y * -100 -100 > player->getPos().z) {
      m_pos[i].y += Model_Max * 2;
    }
  }
}

void Road::draw() {
  gl::pushModelView();

  gl::enableDepthRead();


  gl::rotate(m_rotate);
  gl::scale(m_scale);

  for (int i = 0; i < Model_Max; ++i) {
    gl::pushModelView();
    {
      gl::translate(m_pos[i]);
      gl::draw(m_model.get());
      m_model.drawWire();
    }
    gl::popModelView();
  }


  gl::disableDepthRead();

  gl::popModelView();
}
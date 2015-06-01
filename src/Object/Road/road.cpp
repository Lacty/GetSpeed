
#include "../../MyLib/graph.h"
#include "road.h"


Road::Road() :
m_model("Road")
{
  m_name = std::string("Road");
}


void Road::update() {}

void Road::draw() {
  gl::pushModelView();

  gl::rotate(Vec3f(-90, 0, 0));
  gl::scale(Vec3f(100, 100, 100));

  for (int i = 0; i < 100; ++i) {
    gl::pushModelView();
    {
      gl::translate(0, i * 2, 0);
      gl::draw(m_model.get());
      m_model.drawWire();
    }
    gl::popModelView();
  }

  gl::popModelView();
}
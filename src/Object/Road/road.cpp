
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

  gl::scale(Vec3f(100, 100, 100));

  gl::draw(m_model.get());
  m_model.drawWire();

  gl::popModelView();
}
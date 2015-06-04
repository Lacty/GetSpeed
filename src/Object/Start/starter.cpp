
#include "starter.h"


Starter::Starter() :
font(std::make_shared<Font>(Font("", 120))),
m_count(0),
state(Status::Set) {}


void Starter::update() {
  if (state == Status::Go) return;
  m_count++;
  const int CountMax = 100;
  if (m_count > CountMax) {
    if (state == Status::Ready) {
      state = Status::Go;
      return;
    }
    state = Status::Ready;
    m_count = 0;
  } 
}

void Starter::draw() {
  Vec2f pos = Vec2f(0, 0);
  gl::pushModelView();
  gl::rotate(Vec3f(180, 0, 0));
  gl::translate(Vec3f(0, -64, 300));

  switch (state) {
  case Starter::Set:
    gl::drawStringCentered("Set", pos, Color::white(), *font);
    break;
  case Starter::Ready:
    gl::drawStringCentered("Ready?", pos, Color::white(), *font);
    break;
  case Starter::Go:
    gl::drawStringCentered("Go!", pos, Color::white(), *font);
    break;
  default:
    break;
  }
  gl::popModelView();
}

bool Starter::isStart() const {
  return state == Go;
}
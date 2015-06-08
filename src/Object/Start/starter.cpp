
#include "starter.h"


Starter::Starter() :
font(std::make_unique<Font>(loadAsset("Font/planet.TTF"), 54.0f)),
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
  Vec2f pos = Vec2f(0, -80);
  gl::pushModelView();
  gl::translate(Vec3f(0, -10, -300));
  gl::rotate(Vec3f(180, 0, 0));

  switch (state) {
  case Starter::Set:
    gl::drawStringCentered("Set.", pos, Color(0.4f, 0.8f, 0.4f), *font);
    break;
  case Starter::Ready:
    gl::drawStringCentered("Ready?.", pos, Color(0.4f, 0.4f, 0.8f), *font);
    break;
  case Starter::Go:
    gl::drawStringCentered("Go!.", pos, Color(0.8, 0.4f, 0.4f), *font);
    break;
  default:
    break;
  }
  gl::popModelView();
}

bool Starter::isStart() const {
  return state == Go;
}
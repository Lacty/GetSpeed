
#include "star.h"
#include "cinder/Rand.h"


Star::Star() {}


Star::sStar Star::create() {
  sStar star;
  star.begin = Vec3f(-200, -200, 700);
  star.end   = Vec3f(Vec2f(Rand::randFloat(-200, 200), Rand::randFloat(-200, 200)),
                     Rand::randFloat(-300, 400));
  star.duaration = Rand::randFloat(1.f, 8.f);
  star.count = 0.0f;
  timeline().apply(&star.begin,
                   star.end.value(),
                   star.duaration, easeOutCirc);
  return star;
}

bool Star::trigger() {
  trigger_count++;
  if (trigger_count / 10) {
    return true;
  }
  return false;
}

void Star::update() {
  if (trigger()) {
    star.emplace_back(create());
  }
  for (auto& it : star) {
    it.count += it.duaration / 60.f;
  }

  std::list<sStar>::iterator it;
  it = star.begin();
  while (it != star.end()) {
    if (it->isStop()) {
      it = star.erase(it);
    }
    it++;
  }
}

void Star::draw() {
  for (auto& it : star) {
    gl::drawCube(it.begin, Vec3f(14, 14, 14));
  }
}
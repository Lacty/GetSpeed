
#pragma once
#include <list>
#include "../../MyLib/ci_app.h"

#include "cinder/Timeline.h"
#include "cinder/Tween.h"


class Star {
private:
  struct sStar {
    Anim<Vec3f> begin;
    Anim<Vec3f> end;
    float duaration;
    float count;
    bool isStop() {
      return count >= duaration;
    }
  };
  std::list<sStar> star;

  int  trigger_count;
  bool trigger();

  sStar create();

public:
  Star();

  void update();
  void draw();
};
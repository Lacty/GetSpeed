
#pragma once
#include "../../MyLib/ci_app.h"
#include "../scene.h"
#include <memory>

#include "cinder/audio/Context.h"
#include "cinder/audio/NodeEffects.h"
#include "cinder/audio/SamplePlayerNode.h"


class Result : public Scene {
private:
  Vec3f m_rotate;
  std::unique_ptr<Font> font1; // ƒiƒ“ƒoƒŠƒ“ƒO‚¢‚­‚È‚¢
  std::unique_ptr<Font> font2; // ŽžŠÔ‚È‚¢
  
  enum {
    Current,
    First,
    Second,
    Third,
    Sentinel
  };
  Vec2f font_pos[Sentinel];
  Vec2f score_pos[Sentinel];

  audio::BufferPlayerNodeRef bgm;
  audio::GainNodeRef         gain;

  void camera();

public:
  Result(SceneMgr*);
  ~Result() = default;

  void update();
  void draw(); 
};
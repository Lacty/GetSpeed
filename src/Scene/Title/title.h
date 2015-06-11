
#pragma once
#include "../../MyLib/ci_app.h"
#include "../scene.h"
#include <memory>

#include "cinder/audio/Context.h"
#include "cinder/audio/NodeEffects.h"
#include "cinder/audio/SamplePlayerNode.h"


class Title : public Scene {
private:
  Vec3f m_rotate;

  // ƒiƒ“ƒoƒŠƒ“ƒO‚¢‚­‚È‚¢
  // ŽžŠÔ‚È‚¢
  float alpha_count;
  std::unique_ptr<Font> font1;
  std::unique_ptr<Font> font2;
  std::unique_ptr<Font> font3;
  std::unique_ptr<Font> font4;

  audio::BufferPlayerNodeRef bgm;
  audio::GainNodeRef         gain;

  Vec3f eye;
  Vec3f target;
  bool isShiftScene;
  float fade_count;
  void shiftScene();

public:
  Title(SceneMgr*);
  ~Title() = default;

  void update();
  void draw();
};
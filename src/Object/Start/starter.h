
#pragma once
#include "../../MyLib/noncopyable.h"
#include "../../MyLib/ci_app.h"
#include <memory>

#include "cinder/audio/Context.h"
#include "cinder/audio/NodeEffects.h"
#include "cinder/audio/SamplePlayerNode.h"


class Starter : public ly::noncopyable {
private:
  std::shared_ptr<Font> font;
  int m_count;

  enum Status {
    Set,
    Ready,
    Go,
    Sentinel
  } state;

  audio::BufferPlayerNodeRef se_set;
  audio::BufferPlayerNodeRef se_ready;
  audio::BufferPlayerNodeRef se_go;
  audio::GainNodeRef         gain;
  bool isSe[Sentinel];

public:
  Starter();
  ~Starter() = default;

  void update();
  void draw();

  bool isStart() const;
};
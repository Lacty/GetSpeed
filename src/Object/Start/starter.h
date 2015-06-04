
#pragma once
#include "../../MyLib/noncopyable.h"
#include "../../MyLib/ci_app.h"
#include <memory>


class Starter : public ly::noncopyable {
private:
  std::shared_ptr<Font> font;
  int m_count;

  enum Status {
    Set,
    Ready,
    Go
  } state;

public:
  Starter();
  ~Starter() = default;

  void update();
  void draw();

  bool isStart() const;
};
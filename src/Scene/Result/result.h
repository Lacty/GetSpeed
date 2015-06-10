
#pragma once
#include "../../MyLib/ci_app.h"
#include "../scene.h"
#include <memory>


class Result : public Scene {
private:
  Vec3f m_rotate;
  std::unique_ptr<Font> font1; // �i���o�����O�����Ȃ�
  std::unique_ptr<Font> font2; // ���ԂȂ�
  
  enum {
    Current,
    First,
    Second,
    Third,
    Sentinel
  };
  Vec2f font_pos[Sentinel];
  Vec2f score_pos[Sentinel];

  void camera();

public:
  Result(SceneMgr*);
  ~Result() = default;

  void update();
  void draw(); 
};
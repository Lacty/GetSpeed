
#pragma once
#include "../MyLib/noncopyable.h"
#include <memory>

class Scene;


class SceneMgr : public ly::noncopyable {
private:
  std::shared_ptr<Scene> current_scene;

public:
  SceneMgr();
  ~SceneMgr() = default;

  void update();
  void draw();

  void shiftNextScene(std::shared_ptr<Scene> next_scene);
};
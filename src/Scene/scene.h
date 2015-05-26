
#pragma once
#include "../MyLib/noncopyable.h"

class SceneMgr;


class Scene : public ly::noncopyable {
protected:
  SceneMgr* m_mgr;

  Scene(SceneMgr*);
  ~Scene() = default;

public:
  virtual void update() = 0;
  virtual void draw()   = 0;
};
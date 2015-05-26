
#pragma once
#include <string>
#include "../MyLib/noncopyable.h"


class Object : public ly::noncopyable {
protected:
  std::string m_name;

public:
  Object();
  Object(const std::string& name);
  virtual ~Object() = default;

  std::string getName() const {
    return m_name;
  }

  virtual void update() = 0;
  virtual void draw()   = 0;
};
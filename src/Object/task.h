
#pragma once
#include "../MyLib/noncopyable.h"
#include <string>
#include <memory>
#include <list>
#include <map>


class Object;

class Task : public ly::noncopyable {
private:
  std::list<std::shared_ptr<Object>> m_list;
  std::map<std::string, std::shared_ptr<Object>> m_map;

  Task() = default;

public:
  static Task& getInstance() {
    static Task task;
    return task;
  }

  void add(const std::string&,
           const std::shared_ptr<Object>&);
  void kill(const std::string&);

  std::shared_ptr<Object>& find(const std::string&);

  void clear();

  void update() const;
  void draw()   const;
};
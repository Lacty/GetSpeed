
#include "object.h"
#include "task.h"


void Task::add(const std::string& name,
               const std::shared_ptr<Object>& object)
{
  m_list.emplace_back(object);
  m_map.emplace(std::make_pair(name, object));
}

void Task::kill(const std::string& name) {
  m_map.erase(m_map.find(name));
  m_list.remove_if([&](const std::weak_ptr<Object>& object){
    return object.lock()->getName() == name;
  });
}

std::shared_ptr<Object>& Task::find(const std::string& name) {
  return m_map.find(name)->second;
}

void Task::clear() {
  m_list.clear();
  m_map.clear();
}


void Task::update() const {
  for (const auto& it : m_list) {
    it->update();
  }
}

void Task::draw() const {
  for (const auto& it : m_list) {
    it->draw();
  }
}
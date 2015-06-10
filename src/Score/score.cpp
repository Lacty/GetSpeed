
#include "score.h"
#include <iostream>
#include <algorithm>
#include <functional>
#include "../MyLib/ci_app.h"
#include "cinder/Json.h"


void Score::sort() {
  int temp[4] = { m_first, m_second, m_third, m_current };
  std::sort(temp, temp + 4, std::greater<int>());
  m_first  = temp[0];
  m_second = temp[1];
  m_third  = temp[2];
}

void Score::load() {
  JsonTree data(loadAsset("SaveData/save_data.json"));
  m_first = data["First"].getValue<int>();
  m_second = data["Second"].getValue<int>();
  m_third = data["Third"].getValue<int>();
  console() << m_third << std::endl;
}

void Score::saveToJson() {
  JsonTree data;
  data.addChild(JsonTree("First", m_first));
  data.addChild(JsonTree("Second", m_second));
  data.addChild(JsonTree("Third", m_third));
  data.write(getAppPath() / "../../assets/SaveData/save_data.json", JsonTree::WriteOptions().createDocument(false));
}

void Score::setCurrent(const int& current) {
  m_current = current;
}


int Score::getFirst() const {
  return m_first;
}

int Score::getSecond() const {
  return m_second;
}

int Score::getThird() const {
  return m_third;
}

int Score::getCurrent() const {
  return m_current;
}
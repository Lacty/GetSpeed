
#pragma once
#include "../MyLib/noncopyable.h"


class Score : public ly::noncopyable {
private:
  Score() = default;

  int m_first;
  int m_second;
  int m_third;
  int m_current;

  void sort();

public:
  static Score& getInstance() {
    static Score score;
    return score;
  };

  void load();
  void saveToJson();
  void setCurrent(const int&);

  int getFirst();
  int getSecond();
  int getTherd();
  int getCurrent();
};
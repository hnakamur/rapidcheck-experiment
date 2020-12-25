#ifndef MOCKTURTLE_H_
#define MOCKTURTLE_H_

#include "turtle.h"
#include <gmock/gmock.h>

class MockTurtle : public Turtle {
public:
  ~MockTurtle() {}
  MOCK_METHOD(void, PenUp, (), (override));
  MOCK_METHOD(void, PenDown, (), (override));
  MOCK_METHOD(void, Forward, (int distance), (override));
  MOCK_METHOD(void, Turn, (int degrees), (override));
  MOCK_METHOD(void, GoTo, (int x, int y), (override));
  MOCK_METHOD(int, GetX, (), (const, override));
  MOCK_METHOD(int, GetY, (), (const, override));
};

#endif // MOCKTURTLE_H_

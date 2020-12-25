#include "mock-turtle.h"
#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include <rapidcheck/gtest.h>
#include <rapidcheck/gmock.h>

#include "painter.h"

using ::testing::AtLeast;

RC_GTEST_PROP(PainterTest,
              CanDrawSomething,
              (const int x)) {
  MockTurtle turtle;
  EXPECT_CALL(turtle, PenDown())
      .Times(AtLeast(1));

  Painter painter(&turtle);

  RC_ASSERT(painter.DrawCircle(x, 0, 10));
}

int main(int argc, char **argv) {
  ::testing::InitGoogleMock(&argc, argv);

  // This installs the RapidCheck listener.
  rc::gmock::RapidCheckListener::install();

  return RUN_ALL_TESTS();
}

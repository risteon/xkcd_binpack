//
// Created by christoph on 29.07.15.
//

#include <gtest/gtest.h>

#include <xkcd_binpack/ShapeAlignedRectangle.h>

using namespace xkcd_binpack;

TEST(test_ShapeAlignedRectangle, collision_simple)
{
  ShapeAlignedRectangle r1;
  r1.setPosition(Pixel(0,0));
  r1.setDimensions(1,1);

  ShapeAlignedRectangle r2;
  r2.setPosition(Pixel(0,0));
  r2.setDimensions(1,1);

  ASSERT_EQ(r1.checkCollision(r1), true);
  ASSERT_EQ(r1.checkCollision(r2), true);
}
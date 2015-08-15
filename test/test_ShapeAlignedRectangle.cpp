//
// Created by christoph on 29.07.15.
//

#include <gtest/gtest.h>

#include <xkcd_binpack/ShapeAlignedRectangle.h>

using namespace xkcd_binpack;

TEST(test_ShapeAlignedRectangle, collision_pixel)
{
  ShapeAlignedRectangle r1;

  ASSERT_EQ(r1.checkCollision(Pixel(0,0)), true);

  ASSERT_EQ(r1.checkCollision(Pixel(1,0)), false);
  ASSERT_EQ(r1.checkCollision(Pixel(1,1)), false);
  ASSERT_EQ(r1.checkCollision(Pixel(0,1)), false);
  ASSERT_EQ(r1.checkCollision(Pixel(-1,1)), false);
  ASSERT_EQ(r1.checkCollision(Pixel(-1,0)), false);
  ASSERT_EQ(r1.checkCollision(Pixel(-1,-1)), false);
  ASSERT_EQ(r1.checkCollision(Pixel(0,-1)), false);
  ASSERT_EQ(r1.checkCollision(Pixel(1,-1)), false);

  r1.setPosition(Pixel(10, -5));
  r1.setDimensions(4,2);

  ASSERT_EQ(r1.checkCollision(Pixel(11,-6)), false);
  ASSERT_EQ(r1.checkCollision(Pixel(11,-5)), true);
  ASSERT_EQ(r1.checkCollision(Pixel(11,-4)), true);
  ASSERT_EQ(r1.checkCollision(Pixel(11,-3)), false);

  ASSERT_EQ(r1.checkCollision(Pixel(14,-5)), false);
  ASSERT_EQ(r1.checkCollision(Pixel(14,-4)), false);
}

TEST(test_ShapeAlignedRectangle, collision_other)
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
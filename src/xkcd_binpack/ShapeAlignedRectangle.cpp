// this is for emacs file handling -*- mode: c++; indent-tabs-mode: nil -*-

// -- BEGIN LICENSE BLOCK ----------------------------------------------
// -- END LICENSE BLOCK ------------------------------------------------

//----------------------------------------------------------------------
/*!\file
 *
 * \author  Christoph Rist <rist.christoph@gmail.com>
 * \date    2014-12-28
 *
 */
//----------------------------------------------------------------------

#include "ShapeAlignedRectangle.h"

namespace xkcd_binpack {

ShapeAlignedRectangle::ShapeAlignedRectangle()
        : m_dimensions({1, 1})
{
  m_corners[UP_LEFT] = Pixel(0,0);
  updateCornerPixels();
}

bool ShapeAlignedRectangle::checkCollision(const ShapeAlignedRectangle &other) const
{
  return m_corners[UP_LEFT].x < other.getCornerPixels()[UP_RIGHT].x &&
         m_corners[UP_RIGHT].x > other.getCornerPixels()[UP_LEFT].x &&
         m_corners[UP_LEFT].y < other.getCornerPixels()[DOWN_LEFT].y &&
         m_corners[DOWN_LEFT].y > other.getCornerPixels()[UP_LEFT].y;
}

void ShapeAlignedRectangle::updateCornerPixels()
{
  m_corners[UP_RIGHT] = m_corners[UP_LEFT];
  m_corners[UP_RIGHT].x += m_dimensions.x - 1;

  m_corners[DOWN_LEFT] = m_corners[UP_LEFT];
  m_corners[DOWN_LEFT].y += m_dimensions.y - 1;

  m_corners[DOWN_RIGHT] = m_corners[UP_LEFT] + m_dimensions - Pixel(1,1);
}

bool ShapeAlignedRectangle::checkCollision(const Pixel &pixel) const
{
  return pixel.x >= m_corners[UP_LEFT].x && pixel.x <= m_corners[DOWN_RIGHT].x
          && pixel.y >= m_corners[UP_LEFT].y && pixel.y <= m_corners[DOWN_RIGHT].y;
}
} // ns

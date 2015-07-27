// this is for emacs file handling -*- mode: c++; indent-tabs-mode: nil -*-

// -- BEGIN LICENSE BLOCK ----------------------------------------------
// -- END LICENSE BLOCK ------------------------------------------------

//----------------------------------------------------------------------
/*!\file
 *
 * \author  Christoph Rist <rist.christoph@gmail.com>
 * \date    2014-11-17
 *
 */
//----------------------------------------------------------------------

#ifndef XKCD_BINPACK_POINT_H
#define XKCD_BINPACK_POINT_H

#include <cmath>
#include <stdint.h>

namespace xkcd_binpack {

//! Position aligned to pixel grid
typedef int32_t _pixel_position_t;

struct Pixel
{
  Pixel()
          : x(0), y(0) { }

  Pixel(_pixel_position_t _x, _pixel_position_t _y)
          : x(_x)
          , y(_y)
  {

  }

  virtual ~Pixel()
  {

  }

  //!
  Pixel operator+(const Pixel &rhs) const { return Pixel(x + rhs.x, y + rhs.y); }
  Pixel operator-(const Pixel &rhs) const { return Pixel(x - rhs.x, y - rhs.y); }

  Pixel &operator+=(const Pixel &rhs)
  {
    x += rhs.x;
    y += rhs.y;
    return *this;
  }

  Pixel &operator-=(const Pixel &rhs)
  {
    x -= rhs.x;
    y -= rhs.y;
    return *this;
  }

  _pixel_position_t x;
  _pixel_position_t y;


};

} // ns

#endif //XKCD_BINPACK_POINT_H

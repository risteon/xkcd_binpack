// this is for emacs file handling -*- mode: c++; indent-tabs-mode: nil -*-

// -- BEGIN LICENSE BLOCK ----------------------------------------------
// -- END LICENSE BLOCK ------------------------------------------------

//----------------------------------------------------------------------
/*!\file
 *
 * \author  Christoph Rist <rist@fzi.de>
 * \date    2014-11-17
 *
 */
//----------------------------------------------------------------------

#include "Point.h"

Point::Point(_position_type x, _position_type y)
  : m_x(x)
  , m_y(y)
{

}

_position_type Point::distanceToPoint(const Point& p)
{
  _position_type a = pow(getX() - p.getX(),2);
  _position_type b = pow(getY() - p.getY(),2);
  _position_type distance = sqrt(a + b);
  return distance;
}

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

#ifndef POINT_H
#define POINT_H

#include <cmath>
#include <stdint.h>

namespace xkcd_binpack {

typedef int32_t _position_type;

enum pointDirection
{
  onLine = 0,
  left = -1,
  right = 1
};

class Point
{
public:
  Point()
          : m_x(0), m_y(0) { }

  Point(_position_type x, _position_type y);

  virtual ~Point() { }

  //! Getter
  virtual _position_type getX() const { return m_x; }

  virtual _position_type getY() const { return m_y; }

  //! Setter
  virtual void setX(_position_type x) { m_x = x; }

  virtual void setY(_position_type y) { m_y = y; }

  //! Access via reference
  virtual _position_type &x() { return m_x; }

  virtual _position_type &y() { return m_y; }

  _position_type distanceToPoint(const Point &);

  //!
  Point operator+(const Point &rhs) const { return Point(m_x + rhs.getX(), m_y + rhs.getY()); }

  Point operator-(const Point &rhs) const { return Point(m_x - rhs.getX(), m_y - rhs.getY()); }

  Point &operator+=(const Point &rhs)
  {
    m_x += rhs.getX();
    m_y += rhs.getY();
    return *this;
  }

  Point &operator-=(const Point &rhs)
  {
    m_x -= rhs.getX();
    m_y -= rhs.getY();
    return *this;
  }

protected:
  _position_type m_x;
  _position_type m_y;

private:
};

} // ns

#endif //POINT_H

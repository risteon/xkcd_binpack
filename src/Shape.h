#ifndef SHAPE_H
#define SHAPE_H

#include <memory>
#include <tuple>

#include "Point.h"

class Shape
{
public:
  //! Pointer shorthand
  typedef std::shared_ptr<Shape> Ptr;

  //! Dimensions
  typedef std::tuple<_position_type, _position_type> Dimensions;

  //! Constructor
  Shape()              {}

  //! Destructor
  virtual ~Shape()     {}

  //!
  void setPosition(const Point& position)         { m_position = position; }

  //! Read Access
  const Point& getPosition() const                { return m_position; }
  const Dimensions& getDimensions() const         { return m_dimensions; }

private:
  //! Position of shape
  Point m_position;

  //! Dimensions
  Dimensions m_dimensions;
};


#endif //SHAPE_H

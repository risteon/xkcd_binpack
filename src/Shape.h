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

  //! Const Pointer shorthand
  typedef std::shared_ptr<const Shape> ConstPtr;

  //! Dimensions
  typedef u_int32_t _dimension_type;
  typedef std::array<_dimension_type, 2> Dimensions;

  //! Constructor
  Shape();

  //! Destructor
  virtual ~Shape()     {}

  //!
  void setPosition(const Point& position)                               { m_position = position; }

  //!
  void setDimensions(_dimension_type width, _dimension_type height)     { m_dimensions = { width, height }; }

  //!
  void setFilename(const std::string& filename)                         { m_filename = filename; }

  //! Read Access
  const Point& getPosition() const                { return m_position; }
  const Dimensions& getDimensions() const         { return m_dimensions; }
  const std::string& getFilename() const          { return m_filename; }

private:
  //! Position of shape
  Point m_position;

  //! Dimensions
  Dimensions m_dimensions;

  //! Data to identify picture
  std::string m_filename;
};


#endif //SHAPE_H

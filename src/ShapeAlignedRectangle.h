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

#ifndef SHAPE_H
#define SHAPE_H

#include <memory>
#include <tuple>
#include <vector>

#include "Point.h"

namespace xkcd_binpack {

/**
 * class ShapeAlignedRectangle: represents an aligned rectangle
 */
class ShapeAlignedRectangle
{
public:
  //! Pointer shorthand
  typedef std::shared_ptr<ShapeAlignedRectangle> Ptr;

  //! Const Pointer shorthand
  typedef std::shared_ptr<const ShapeAlignedRectangle> ConstPtr;

  //! Dimensions
  typedef u_int32_t _dimension_type;
  typedef std::array<_dimension_type, 2> Dimensions;

  //! Constructor
  ShapeAlignedRectangle();

  //! Destructor
  virtual ~ShapeAlignedRectangle() { }

  //!
  void setPosition(const Point &position) { m_position = position; }

  //!
  void setDimensions(_dimension_type width, _dimension_type height) { m_dimensions = {width, height}; }

  //!
  void setFilename(const std::string &filename) { m_filename = filename; }

  //! Read Access
  const Point &getPosition() const { return m_position; }

  const Dimensions &getDimensions() const { return m_dimensions; }

  const std::string &getFilename() const { return m_filename; }

private:
  //! Position of shape
  Point m_position;

  //! Dimensions
  Dimensions m_dimensions;

  //! Data to identify picture
  std::string m_filename;
};

//! Some typedefs
typedef std::vector<ShapeAlignedRectangle::Ptr> ShapeCollection;
typedef std::shared_ptr<ShapeCollection> ShapeCollectionPtr;
typedef std::shared_ptr<const ShapeCollection> ShapeCollectionConstPtr;

} // ns

#endif //SHAPE_H

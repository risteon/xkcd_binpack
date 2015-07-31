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

#include "Pixel.h"

namespace xkcd_binpack {

/**
 * class ShapeAlignedRectangle: represents an aligned rectangle
 *
 *
 *    --------> x
 *   |X
 *   |
 *   |
 *   V
 *   y
 *
 *
 */
class ShapeAlignedRectangle
{
public:
  //! Pointer shorthand
  typedef std::shared_ptr<ShapeAlignedRectangle> Ptr;

  //! Const Pointer shorthand
  typedef std::shared_ptr<const ShapeAlignedRectangle> ConstPtr;

  //! Dimensions
  typedef _pixel_position_t _dimension_type;
  typedef Pixel Dimensions;
  //! Corner pixels
  typedef std::array<Pixel, 4> CornerPixels;
  enum CORNER_PIXELS : u_int8_t
  {
    UP_LEFT=0,
    UP_RIGHT=1,
    DOWN_RIGHT=2,
    DOWN_LEFT=3
  };

  //! Constructor
  ShapeAlignedRectangle();

  //! Destructor
  virtual ~ShapeAlignedRectangle() { }

  //! Setter
  void setPosition(const Pixel &position)
  {
    m_corners[UP_LEFT] = position;
    updateCornerPixels();
  }
  void setDimensions(_dimension_type width, _dimension_type height)
  {
    m_dimensions = {width, height};
    updateCornerPixels();
  }

  void setFilename(const std::string &filename) { m_filename = filename; }

  //! Read Access
  const Pixel& getPosition() const                  { return m_corners[UP_LEFT]; }
  const Dimensions& getDimensions() const           { return m_dimensions; }
  const std::string& getFilename() const            { return m_filename; }
  const CornerPixels& getCornerPixels() const       { return m_corners; }

  //! Check for collision, returns true on collision
  bool checkCollision(const ShapeAlignedRectangle& other) const;
  bool checkCollision(const Pixel& pixel) const;


private:
  //! Calculate from position and dimensions
  void updateCornerPixels();

  //! Dimensions
  Dimensions m_dimensions;

  //! Corners
  CornerPixels m_corners;

  //! Data to identify picture
  std::string m_filename;
};

//! Some typedefs
typedef std::vector<ShapeAlignedRectangle::Ptr> ShapeCollection;
typedef std::shared_ptr<ShapeCollection> ShapeCollectionPtr;
typedef std::shared_ptr<const ShapeCollection> ShapeCollectionConstPtr;

} // ns

#endif //SHAPE_H

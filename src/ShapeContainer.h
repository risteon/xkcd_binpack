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

#ifndef SHAPE_CONTAINER_H
#define SHAPE_CONTAINER_H

#include <memory>
#include <vector>

#include "Shape.h"
#include "MessageException.h"

namespace xkcd_binpack {

class ShapeContainer
{
public:
  //! Pointer shorthand
  typedef std::shared_ptr<ShapeContainer> Ptr;

  //! Shapes
  typedef std::vector<Shape::Ptr> ShapeCollection;

  //! Constructor
  ShapeContainer()              {}

  //! Destructor
  virtual ~ShapeContainer()     {}

  //! Load from images file directory or XML-File
  void load(const std::string& directory);

  //! Write to xml
  void writeToXml(const std::string& filename);

private:
  //! Save shapes
  ShapeCollection m_shapes;

  //! XML constant strings
  static const constexpr char* XML_ROOT = "shape_collection";
  static const constexpr char* XML_NODE = "shape";
  static const constexpr char* XML_PATH = "path";
  static const constexpr char* XML_WIDTH = "width";
  static const constexpr char* XML_HEIGHT = "height";
};

} // ns

#endif //SHAPE_CONTAINER_H

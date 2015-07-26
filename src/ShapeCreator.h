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

class ShapeCreator
{
public:
  //! Load by interpreting string as arbitrary data source
  static void load(const std::string& data_access, ShapeCollection& sc);

  //! Load image shapes from xml_file
  static void loadFromXML(const std::string& xml_file, ShapeCollection& sc);

  //! Load from images in folder
  static void loadFromImageFolder(const std::string& directory, ShapeCollection& sc);

  //! Write to xml
  static void writeToXml(const std::string& filename, const ShapeCollection& sc);

private:

  //! XML constant strings
  static constexpr auto XML_ROOT = "shape_collection";
  static constexpr auto XML_NODE = "shape";
  static constexpr auto XML_PATH = "path";
  static constexpr auto XML_WIDTH = "width";
  static constexpr auto XML_HEIGHT = "height";
};

} // ns

#endif //SHAPE_CONTAINER_H

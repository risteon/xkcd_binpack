//
// Created by christoph on 26.07.15.
//

#ifndef XKCD_BINPACK_CANVAS_H
#define XKCD_BINPACK_CANVAS_H

#include "ShapeCreator.h"

namespace xkcd_binpack {

class Canvas
{
public:

  //! Set shapes
  void setShapes(const ShapeCollectionPtr& shape_container)        { m_shape_container = shape_container; }


private:

  //! Shapes
  ShapeCollectionPtr m_shape_container;
};

} // ns

#endif //XKCD_BINPACK_CANVAS_H

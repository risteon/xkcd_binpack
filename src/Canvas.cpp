//
// Created by christoph on 26.07.15.
//

#include "Canvas.h"

namespace xkcd_binpack {

void Canvas::rearrangeShapes(ShapePackerBase::Ptr shape_packer)
{
  shape_packer->rearrangeShapes(m_shape_container);
}

} // ns
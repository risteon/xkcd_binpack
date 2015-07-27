//
// Created by christoph on 27.07.15.
//

#ifndef XKCD_BINPACK_SHAPEPACKERBASE_H
#define XKCD_BINPACK_SHAPEPACKERBASE_H

#include "Shape.h"

namespace xkcd_binpack {

class ShapePackerBase
{
public:
  //! Pointer shorthand
  typedef std::shared_ptr<ShapePackerBase> Ptr;
  typedef std::shared_ptr<const ShapePackerBase> ConstPtr;

  //! Constructor
  ShapePackerBase()     {}

  //! Destructor
  virtual ~ShapePackerBase()  {};


  virtual void rearrangeShapes(ShapeCollectionPtr sc) = 0;

protected:

private:
};

} // ns

#endif //XKCD_BINPACK_SHAPEPACKERBASE_H

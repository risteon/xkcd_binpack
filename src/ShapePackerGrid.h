//
// Created by christoph on 27.07.15.
//

#ifndef XKCD_BINPACK_SHAPEPACKERGRID_H
#define XKCD_BINPACK_SHAPEPACKERGRID_H

#include "ShapePackerBase.h"

namespace xkcd_binpack {

class ShapePackerGrid : public ShapePackerBase
{
public:
  //! Constructor
  ShapePackerGrid()
    : ShapePackerBase()
  {

  }

  //! Destructor
  virtual ~ShapePackerGrid()    {}

  //!
  virtual void rearrangeShapes(ShapeCollectionPtr sc) override;

protected:

private:

};

} // ns

#endif //XKCD_BINPACK_SHAPEPACKERGRID_H

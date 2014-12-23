#ifndef SHAPE_CONTAINER_H
#define SHAPE_CONTAINER_H

#include <memory>

#include "Shape.h"

class ShapeContainer
{
public:
  //! Pointer shorthand
  typedef std::shared_ptr<ShapeContainer> Ptr;

  //! Constructor
  ShapeContainer()              {}

  //! Destructor
  virtual ~ShapeContainer()     {}

private:

};


#endif //SHAPE_CONTAINER_H

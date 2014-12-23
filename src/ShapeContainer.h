#ifndef SHAPE_CONTAINER_H
#define SHAPE_CONTAINER_H

#include <memory>
#include <vector>

#include "Shape.h"
#include "MessageException.h"

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

  //! Load from images file directory
  void load(const std::string& directory);

private:
  //! Save shapes
  ShapeCollection m_shapes;
};


#endif //SHAPE_CONTAINER_H

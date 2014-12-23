#ifndef PICTURE_DATA_H
#define PICTURE_DATA_H

#include <memory>

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


#endif //PICTURE_DATA_H

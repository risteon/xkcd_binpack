#include <boost/filesystem.hpp>
#include <opencv2/opencv.hpp>
#include <exception>

#include "ShapeContainer.h"

using namespace boost::filesystem;

void ShapeContainer::load(const std::string& directory)
{
  path p(directory);

  if (!exists(p))
  {
    throw MessageException(std::string("Directory <") + directory + std::string("> not found."));
  }

  // load from every image found
  if (is_directory(p))
  {
    for (directory_iterator it = directory_iterator(p); it != directory_iterator(); it++)
    {
      if (it->path().extension() == ".jpg" || it->path().extension() == ".png")
      {
        cv::Mat image = cv::imread( it->path().string(), CV_LOAD_IMAGE_GRAYSCALE );

        if ( !image.data )
        {
          throw MessageException(std::string("Could not open image <") + it->path().string() + std::string(">."));
        }
        else
        {
          Shape::Ptr shape = std::make_shared<Shape>();
          shape->setDimensions(image.size().width, image.size().height);
          shape->setFilename(it->path().string());
          m_shapes.push_back(shape);
        }

      }

    }
  }
  // load from XML
  else if (is_regular_file(p))
  {

  }
  else
  {
     throw MessageException(std::string("Cannot use file <") + directory + std::string("> to load image dimensions."));
  }
}

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

#include <boost/filesystem.hpp>
#include <opencv2/opencv.hpp>
#include <tinyxml2.h>
#include <exception>

#include "ShapeContainer.h"

using namespace boost::filesystem;

void ShapeContainer::load(const std::string& directory)
{
  path p(directory);

  if (!exists(p))
  {
    throw MessageException(std::string("Directory or file <") + directory + std::string("> not found."));
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
  else if (is_regular_file(p) && p.extension() == ".xml")
  {
    tinyxml2::XMLDocument doc;
    if (doc.LoadFile(p.string().c_str()) != tinyxml2::XML_SUCCESS)
      throw MessageException(std::string("Could not open shape data from <") + p.string() + std::string(">."));

    tinyxml2::XMLElement* root = doc.FirstChildElement(XML_ROOT);
    if (root == nullptr)
    {
      throw MessageException(std::string("Invalid XML File") );
    }
    for (tinyxml2::XMLElement* node = root->FirstChildElement(XML_NODE); node != nullptr; node = node->NextSiblingElement(XML_NODE))
    {
      Shape::Ptr shape = std::make_shared<Shape>();
      const char* file = node->Attribute(XML_PATH);
      if (file == nullptr)
        throw MessageException(std::string("Invalid XML File") );
      shape->setFilename(file);
      shape->setDimensions(node->IntAttribute(XML_WIDTH), node->IntAttribute(XML_HEIGHT));
      m_shapes.push_back(shape);
    }
  }
  else
  {
     throw MessageException(std::string("Cannot use file <") + directory + std::string("> to load image dimensions."));
  }
}

void ShapeContainer::writeToXml(const std::string& filename)
{
  tinyxml2::XMLDocument doc;
  tinyxml2::XMLElement* root = doc.NewElement(XML_ROOT);
  doc.InsertFirstChild(root);

  for (const Shape::ConstPtr& s : m_shapes)
  {
    tinyxml2::XMLElement* e = doc.NewElement(XML_NODE);
    root->InsertEndChild(e);
    e->SetAttribute(XML_PATH, s->getFilename().c_str());
    e->SetAttribute(XML_WIDTH, s->getDimensions()[0]);
    e->SetAttribute(XML_HEIGHT, s->getDimensions()[1]);
  }

  if (doc.SaveFile(filename.c_str()) != tinyxml2::XML_SUCCESS)
    throw MessageException(std::string("Could not write shape data to <") + filename + std::string(">."));
}

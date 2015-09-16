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
#include <tinyxml2/tinyxml2.h>
#include <exception>

#include "ShapeCreator.h"

namespace xkcd_binpack {

using namespace boost::filesystem;

void ShapeCreator::load(const std::string& data_access, ShapeCollection& sc)
{
  path p(data_access);

  if (!exists(p))
  {
    throw MessageException(std::string("Directory or file <") + data_access + std::string("> not found."));
  }

  // load from every image found
  if (is_directory(p))
  {
    loadFromImageFolder(data_access, sc);
  }
  // load from XML
  else if (is_regular_file(p) && p.extension() == ".xml")
  {
    loadFromXML(p.string(), sc);
  }
  else
  {
     throw MessageException(std::string("Cannot use file <") + data_access + std::string("> to load image dimensions."));
  }
}

void ShapeCreator::loadFromXML(const std::string &xml_file, ShapeCollection& sc)
{
  tinyxml2::XMLDocument doc;
  if (doc.LoadFile(xml_file.c_str()) != tinyxml2::XML_SUCCESS)
    throw MessageException(std::string("Could not open shape data from <") + xml_file + std::string(">."));

  tinyxml2::XMLElement* root = doc.FirstChildElement(XML_ROOT);
  if (root == nullptr)
  {
    throw MessageException(std::string("Invalid XML File") );
  }

  sc.clear();
  for (tinyxml2::XMLElement* node = root->FirstChildElement(XML_NODE); node != nullptr; node = node->NextSiblingElement(XML_NODE))
  {
    ShapeAlignedRectangle::Ptr shape = std::make_shared<ShapeAlignedRectangle>();
    const char* file = node->Attribute(XML_PATH);
    if (file == nullptr)
      throw MessageException(std::string("Invalid XML File") );
    shape->setFilename(file);
    shape->setDimensions(node->IntAttribute(XML_WIDTH), node->IntAttribute(XML_HEIGHT));
    sc.push_back(shape);
  }
}

void ShapeCreator::loadFromImageFolder(const std::string &directory, ShapeCollection& sc)
{
  path p(directory);

  sc.clear();
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
        ShapeAlignedRectangle::Ptr shape = std::make_shared<ShapeAlignedRectangle>();
        shape->setDimensions(image.size().width, image.size().height);
        shape->setFilename(it->path().string());
        sc.push_back(shape);
      }

    }

  }
}

void ShapeCreator::writeToXml(const std::string& filename, const ShapeCollection& sc)
{
  tinyxml2::XMLDocument doc;
  tinyxml2::XMLElement* root = doc.NewElement(XML_ROOT);
  doc.InsertFirstChild(root);

  for (const ShapeAlignedRectangle::ConstPtr& s : sc)
  {
    tinyxml2::XMLElement* e = doc.NewElement(XML_NODE);
    root->InsertEndChild(e);
    e->SetAttribute(XML_PATH, s->getFilename().c_str());
    e->SetAttribute(XML_WIDTH, s->getDimensions().x);
    e->SetAttribute(XML_HEIGHT, s->getDimensions().y);
  }

  if (doc.SaveFile(filename.c_str()) != tinyxml2::XML_SUCCESS)
    throw MessageException(std::string("Could not write shape data to <") + filename + std::string(">."));
}
} // ns

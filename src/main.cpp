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

#include <stdio.h>
#include <iostream>

#include "ShapeContainer.h"

using namespace xkcd_binpack;

int main(int argc, char** argv )
{
    if ( argc < 2 )
    {
        printf("usage: xkcd_binpack <Image_Path>\n       xkcd_binpack <ImageDescription.xml>\n");
        return -1;
    }

    ShapeContainer sc;
    try
    {
      sc.load(std::string(argv[1]));
      if (argc > 2)
        sc.writeToXml(argv[2]);
    }
    catch (MessageException& e)
    {
      std::cout <<e.what() <<std::endl;
    }

    return 0;
}

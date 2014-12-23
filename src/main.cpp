#include <stdio.h>
#include <iostream>

#include "ShapeContainer.h"

int main(int argc, char** argv )
{
    if ( argc != 2 )
    {
        printf("usage: xkcd_binpack <Image_Path>\n       xkcd_binpack <ImageDescription.xml>\n");
        return -1;
    }

    ShapeContainer sc;
    try
    {
      sc.load(std::string(argv[1]));
    }
    catch (MessageException& e)
    {
      std::cout <<e.what() <<std::endl;
    }

    return 0;
}

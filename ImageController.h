/*
 *  Obtain bitmap from linux system framebuffer and can save it to bmp-file
 * */
#ifndef IMAGECONTROLLER_H_
#define IMAGECONTROLLER_H_

#include "Image.h"
#include </usr/include/cairo/cairo.h>

class ImageController {
public: 
    ImageController();
    ~ImageController();

    Image * getImage();
    void saveImage(Image * aImage);
private:
    Image * m_image;
};

#endif // IMAGECONTROLLER_H_

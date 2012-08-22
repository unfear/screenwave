/*
 *  Obtain bitmap from linux system framebuffer and can save it to bmp-file
 * */

#include "Image.h"

class ImageController {
public: 
    ImageController();
    ~ImageController();

    Image * getImage();
    void saveImage(Image * aImage);
private:
    Image * m_image;
};

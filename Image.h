/*
 *  Representation of bitmap buffer
 * */
#ifndef IMAGE_H_
#define IMAGE_H_

class Image {
public:
    Image();
    ~Image();
    Image * createImage();
private:
    void * m_buffer;
};

#endif // IMAGE_H_

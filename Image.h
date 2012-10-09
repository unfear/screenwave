/*
 *  Representation of bitmap buffer
 * */
#ifndef IMAGE_H_
#define IMAGE_H_

#include <string>
#include <fstream>

class Image {
public:
    Image();
    ~Image();
    void Create();
    Image * createImage();
private:
//data members : coordinates, dimension, file name, and data stream
    short   x, y;
    short   h, w;
    std::string filename;
    std::fstream pic;

    struct Header {}header; //left out data members to save space
    struct Info  {}info;  //same here
    struct Color  { //this one is what I feel is causing the problem.
        unsigned char b;
        unsigned char g;
        unsigned char r;
        unsigned char a;
    } color;
    void * m_buffer;
};

#endif // IMAGE_H_

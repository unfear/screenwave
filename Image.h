/*
 *  Representation of bitmap buffer
 * */

class Image {
public:
    Image();
    ~Image();
    Image * createImage();
private:
    void * m_buffer;
};

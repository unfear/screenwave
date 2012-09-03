#include "ImageController.h"
#include <stdio.h>
#include <linux/fb.h>
#include <sys/ioctl.h>

#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/mman.h>

ImageController::ImageController() {

}

ImageController::~ImageController() {

}

Image * ImageController::getImage() {
    // Open the file for reading and writing
    int fbDescriptor = open("/dev/fb0", O_RDWR);
    if (fbDescriptor == -1) {
        printf("Error: cannot open framebuffer device!\n");
        return NULL;
    }

    struct fb_var_screeninfo vinfo;
    struct fb_fix_screeninfo finfo;

    //Get fixed screen information
    if (ioctl(fbDescriptor, FBIOGET_FSCREENINFO, &finfo) == -1) {
        perror("Error reading fixed information");
        return NULL;
    }

    // Get variable screen information
    if (ioctl(fbDescriptor, FBIOGET_VSCREENINFO, &vinfo) == -1) {
        perror("Error reading variable information");
        return NULL;
    }

    // Figure out the size of the screen in bytes
    long int screensize = vinfo.xres * vinfo.yres * vinfo.bits_per_pixel / 8;

    close(fbDescriptor);
    return new Image();
}

void ImageController::saveImage(Image * aImage) {

}

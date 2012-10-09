#include "ImageController.h"
#include <stdio.h>
#include <linux/fb.h>
#include <sys/ioctl.h>

#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <cstring>  // for strerror()
#include <errno.h>

ImageController::ImageController() {

}

ImageController::~ImageController() {

}

Image * ImageController::getImage() {
    // Open the file for reading and writing
    int fd = open("/dev/fb0", O_RDWR);
    if (fd == -1) {
        printf("Error: cannot open framebuffer device!\n");
        return NULL;
    }

    struct fb_var_screeninfo vinfo;
    struct fb_fix_screeninfo finfo;

    //Get fixed screen information
    if (ioctl(fd, FBIOGET_FSCREENINFO, &finfo) == -1) {
        perror("Error reading fixed information");
        return NULL;
    }

    // Get variable screen information
    if (ioctl(fd, FBIOGET_VSCREENINFO, &vinfo) == -1) {
        perror("Error reading variable information");
        return NULL;
    }

    // Figure out the size of the screen in bytes
    long int screensize = vinfo.xres * vinfo.yres * vinfo.bits_per_pixel / 8;

    // TODO: create cairo surface from raw data
    
    // FIXME: related to http://e2e.ti.com/support/dsp/davinci_digital_media_processors/f/100/t/8343.aspx
    /* Swap the working buffer for the displayed buffer */
    /*if (ioctl(fd, FBIOPAN_DISPLAY, &vinfo) == -1) {
        perror("Failed FBIOPAN_DISPLAY");
        return NULL;
    }*/

    char * data;

    data = (char *) mmap (NULL,
                         vinfo.yres_virtual * finfo.line_length,
                         PROT_READ | PROT_WRITE,
                         MAP_SHARED,
                         fd, 0);

    /* Map the video buffer to user space */
    if (data == MAP_FAILED) {
        perror("Failed mmap on");
        return NULL;
    }
    
    cairo_format_t format = CAIRO_FORMAT_A1;
    int stride = cairo_format_stride_for_width(format, vinfo.xres);
    cairo_surface_t * some_surface = cairo_image_surface_create_for_data ((unsigned char*)data,
                                                             format,
                                                             vinfo.xres,
                                                             vinfo.yres,
                                                             stride);

    cairo_status_t status = cairo_surface_write_to_png(some_surface, "/home/v-andrashko/Pictures/screen.png");
    printf("cairo status:%d\n", status);
    close(fd);
    return new Image();
}

void ImageController::saveImage(Image * aImage) {

}

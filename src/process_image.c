#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <math.h>
#include "image.h"

float get_pixel(image im, int x, int y, int c)
{
    // TODO Fill this in
    if (x < 0) x = 0;
    if (x >= im.w) x = im.w - 1;
    if (y < 0) y = 0;
    if (y >= im.h) y = im.h - 1;
    if (c < 0) c = 0;
    if (c >= im.c) c = im.c - 1;

    // Calculate the 1D index of the pixel in the data array
    int index = c * im.w * im.h + y * im.w + x;

    // Return the pixel value
    return im.data[index];
    //return 0;
}

void set_pixel(image im, int x, int y, int c, float v)
{
    // TODO Fill this in
    int index = c * im.w * im.h + y * im.w + x;
    im.data[index] = v;
}

image copy_image(image im)
{
    image copy = make_image(im.w, im.h, im.c);
    // TODO Fill this in
    for (int i = 0; i < im.c * im.w * im.h; ++i) {
        copy.data[i] = im.data[i];
    }
    return copy;
}

image rgb_to_grayscale(image im)
{
    assert(im.c == 3);
    image gray = make_image(im.w, im.h, 1);
    for (int i = 0; i < im.w * im.h; ++i) {
        float gray_val = 0.299 * im.data[i] + 0.587 * im.data[(im.w * im.h) + i] + 0.114 * im.data[(2 * im.w * im.h) + i];
        gray.data[i] = gray_val;
    }
    // TODO Fill this in
    return gray;
}

void shift_image(image im, int c, float v)
{
    // TODO Fill this in
    int st_index = c * im.w * im.h;
    //+y * im.w + x;
    for (int i = 0; i < (im.w * im.h); ++i) {
        im.data[st_index + i] += v;
    }

    //im.data[index] += v;
}

void clamp_image(image im)
{
    // TODO Fill this in
}


// These might be handy
float three_way_max(float a, float b, float c)
{
    return (a > b) ? ( (a > c) ? a : c) : ( (b > c) ? b : c) ;
}

float three_way_min(float a, float b, float c)
{
    return (a < b) ? ( (a < c) ? a : c) : ( (b < c) ? b : c) ;
}

void rgb_to_hsv(image im)
{
    // TODO Fill this in
}

void hsv_to_rgb(image im)
{
    // TODO Fill this in
}

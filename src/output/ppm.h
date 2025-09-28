/**
 * @file ppm.h
 * @brief PPM image format output
 */

#ifndef PPM_H
#define PPM_H

#include "../math/vector.h"

void ppm_write_header(FILE* file, int width, int height);
void ppm_write_pixel(FILE* file, Vec3 color);

#endif
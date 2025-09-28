#include <stdio.h>
#include "ppm.h"

void ppm_write_header(FILE* file, int width, int height) {
    fprintf(file, "P3\n%d %d\n255\n", width, height);
}

void ppm_write_pixel(FILE* file, Vec3 color) {
    int r = (int)(color.x * 255);
    int g = (int)(color.y * 255);
    int b = (int)(color.z * 255);
    fprintf(file, "%d %d %d\n", r, g, b);
}
/**
 * @file main.c
 * @brief Main entry point for the ray tracer
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "core/raytracer.h"
#include "core/scene.h"
#include "output/ppm.h"

void render(int width, int height, Scene scene, const char* output_file) {
    FILE* file = fopen(output_file, "w");
    if (!file) {
        fprintf(stderr, "Error: Cannot open output file %s\n", output_file);
        return;
    }
    
    ppm_write_header(file, width, height);
    
    float aspect_ratio = (float)width / height;
    
    for (int y = height - 1; y >= 0; y--) {
        fprintf(stderr, "\rRendering: %d%%", (height - y) * 100 / height);
        for (int x = 0; x < width; x++) {
            float u = (float)x / width * 2.0f - 1.0f;
            float v = (float)y / height * 2.0f - 1.0f;
            u *= aspect_ratio;
            
            Vec3 ray_dir = vec3_normalize((Vec3){u, v, -1});
            Ray ray = {scene.camera.position, ray_dir};
            
            Vec3 color = trace_ray(ray, scene.spheres, scene.sphere_count, 0);
            ppm_write_pixel(file, color);
        }
    }
    
    fprintf(stderr, "\nRendering completed!\n");
    fclose(file);
}

int main() {
    srand(time(NULL));
    
    printf("Mini Ray Tracer in C\n");
    printf("====================\n");
    
    Scene scene = create_default_scene();
    
    int width = 800;
    int height = 600;
    const char* output_file = "render.ppm";
    
    printf("Rendering %dx%d image to %s\n", width, height, output_file);
    render(width, height, scene, output_file);
    
    free_scene(scene);
    printf("Done! Open %s to view the result.\n", output_file);
    
    return 0;
}
#include "scene.h"
#include <stdlib.h>

Scene create_default_scene() {
    Scene scene;
    
    scene.sphere_count = 4;
    scene.spheres = malloc(sizeof(Sphere) * scene.sphere_count);
    
    // Define spheres
    scene.spheres[0] = (Sphere){{0, 0, -1}, 0.5, {0.8f, 0.3f, 0.3f}, 0.3f};
    scene.spheres[1] = (Sphere){{-1, 0, -1}, 0.5, {0.3f, 0.8f, 0.3f}, 0.5f};
    scene.spheres[2] = (Sphere){{1, 0, -1}, 0.5, {0.3f, 0.3f, 0.8f}, 0.8f};
    scene.spheres[3] = (Sphere){{0, -100.5, -1}, 100, {0.8f, 0.8f, 0.8f}, 0.1f};
    
    // Setup camera
    scene.camera = (Camera){
        .position = {0, 0, 3},
        .look_at = {0, 0, -1},
        .up = {0, 1, 0},
        .fov = 60.0f
    };
    
    return scene;
}

void free_scene(Scene scene) {
    free(scene.spheres);
}
/**
 * @file scene.h
 * @brief Scene definition and setup
 */

#ifndef SCENE_H
#define SCENE_H

#include "../math/vector.h"
#include "raytracer.h"

typedef struct {
    Vec3 position;
    Vec3 look_at;
    Vec3 up;
    float fov;
} Camera;

typedef struct {
    Sphere* spheres;
    int sphere_count;
    Camera camera;
} Scene;

// Scene setup functions
Scene create_default_scene();
void free_scene(Scene scene);

#endif
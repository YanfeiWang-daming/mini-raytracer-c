/**
 * @file raytracer.h
 * @brief Core ray tracing algorithms
 */

#ifndef RAYTRACER_H
#define RAYTRACER_H

#include "../math/vector.h"

typedef struct {
    Vec3 origin;
    Vec3 direction;
} Ray;

typedef struct {
    Vec3 center;
    float radius;
    Vec3 color;
    float reflectivity;
} Sphere;

// Ray-sphere intersection
int ray_sphere_intersect(Ray ray, Sphere sphere, float* t);

// Normal calculation
Vec3 sphere_normal(Sphere sphere, Vec3 point);

// Main tracing function
Vec3 trace_ray(Ray ray, Sphere* spheres, int sphere_count, int depth);

#endif
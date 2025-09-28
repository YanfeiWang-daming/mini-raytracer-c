#include "raytracer.h"
#include <math.h>
#include <float.h>
#include <stddef.h>

int ray_sphere_intersect(Ray ray, Sphere sphere, float* t) {
    Vec3 oc = vec3_sub(ray.origin, sphere.center);
    float a = vec3_dot(ray.direction, ray.direction);
    float b = 2.0f * vec3_dot(oc, ray.direction);
    float c = vec3_dot(oc, oc) - sphere.radius * sphere.radius;
    float discriminant = b * b - 4 * a * c;
    
    if (discriminant < 0) return 0;
    
    float sqrt_disc = sqrtf(discriminant);
    float t0 = (-b - sqrt_disc) / (2.0f * a);
    float t1 = (-b + sqrt_disc) / (2.0f * a);
    
    if (t0 > 0) {
        *t = t0;
        return 1;
    } else if (t1 > 0) {
        *t = t1;
        return 1;
    }
    return 0;
}

Vec3 sphere_normal(Sphere sphere, Vec3 point) {
    return vec3_normalize(vec3_sub(point, sphere.center));
}

Vec3 trace_ray(Ray ray, Sphere* spheres, int sphere_count, int depth) {
    if (depth >= 5) return (Vec3){0, 0, 0};
    
    float closest_t = FLT_MAX;
    Sphere* hit_sphere = NULL;
    Vec3 hit_point;
    
    // Find closest intersection
    for (int i = 0; i < sphere_count; i++) {
        float t;
        if (ray_sphere_intersect(ray, spheres[i], &t) && t < closest_t) {
            closest_t = t;
            hit_sphere = &spheres[i];
        }
    }
    
    if (!hit_sphere) {
        // Sky gradient background
        float t = 0.5f * (ray.direction.y + 1.0f);
        return vec3_lerp((Vec3){1.0f, 1.0f, 1.0f}, 
                        (Vec3){0.5f, 0.7f, 1.0f}, t);
    }
    
    hit_point = vec3_add(ray.origin, vec3_mul(ray.direction, closest_t));
    Vec3 normal = sphere_normal(*hit_sphere, hit_point);
    
    Vec3 color = hit_sphere->color;
    Vec3 ambient = vec3_mul(color, 0.1f);
    
    // Simple directional light
    Vec3 light_dir = vec3_normalize((Vec3){1, 1, -1});
    float diff = fmaxf(0.0f, vec3_dot(normal, light_dir));
    Vec3 diffuse = vec3_mul(color, diff);
    
    Vec3 result = vec3_add(ambient, diffuse);
    
    // Reflection
    if (hit_sphere->reflectivity > 0) {
        Vec3 reflect_dir = vec3_sub(ray.direction, 
                                   vec3_mul(normal, 2 * vec3_dot(ray.direction, normal)));
        Ray reflect_ray = {hit_point, vec3_normalize(reflect_dir)};
        Vec3 reflect_color = trace_ray(reflect_ray, spheres, sphere_count, depth + 1);
        result = vec3_add(vec3_mul(result, 1 - hit_sphere->reflectivity),
                         vec3_mul(reflect_color, hit_sphere->reflectivity));
    }
    
    return vec3_clamp(result, 0.0f, 1.0f);
}
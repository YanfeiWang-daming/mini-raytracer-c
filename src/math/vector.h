/**
 * @file vector.h
 * @brief 3D vector mathematics library
 * @author ICOOO
 * @date 2024
 */

#ifndef VECTOR_H
#define VECTOR_H

typedef struct {
    float x, y, z;
} Vec3;

// Vector operations
Vec3 vec3_add(Vec3 a, Vec3 b);
Vec3 vec3_sub(Vec3 a, Vec3 b);
Vec3 vec3_mul(Vec3 v, float scalar);
Vec3 vec3_div(Vec3 v, float scalar);
float vec3_dot(Vec3 a, Vec3 b);
float vec3_length(Vec3 v);
Vec3 vec3_normalize(Vec3 v);
Vec3 vec3_cross(Vec3 a, Vec3 b);

// Utility functions
Vec3 vec3_clamp(Vec3 v, float min, float max);
Vec3 vec3_lerp(Vec3 a, Vec3 b, float t);

#endif
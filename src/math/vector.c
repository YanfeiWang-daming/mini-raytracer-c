#include "vector.h"
#include <math.h>

Vec3 vec3_add(Vec3 a, Vec3 b) {
    return (Vec3){a.x + b.x, a.y + b.y, a.z + b.z};
}

Vec3 vec3_sub(Vec3 a, Vec3 b) {
    return (Vec3){a.x - b.x, a.y - b.y, a.z - b.z};
}

Vec3 vec3_mul(Vec3 v, float scalar) {
    return (Vec3){v.x * scalar, v.y * scalar, v.z * scalar};
}

Vec3 vec3_div(Vec3 v, float scalar) {
    if (scalar != 0) {
        return vec3_mul(v, 1.0f / scalar);
    }
    return v;
}

float vec3_dot(Vec3 a, Vec3 b) {
    return a.x * b.x + a.y * b.y + a.z * b.z;
}

float vec3_length(Vec3 v) {
    return sqrtf(v.x * v.x + v.y * v.y + v.z * v.z);
}

Vec3 vec3_normalize(Vec3 v) {
    float len = vec3_length(v);
    return (len > 0) ? vec3_div(v, len) : v;
}

Vec3 vec3_cross(Vec3 a, Vec3 b) {
    return (Vec3){
        a.y * b.z - a.z * b.y,
        a.z * b.x - a.x * b.z,
        a.x * b.y - a.y * b.x
    };
}

Vec3 vec3_clamp(Vec3 v, float min, float max) {
    return (Vec3){
        fminf(fmaxf(v.x, min), max),
        fminf(fmaxf(v.y, min), max),
        fminf(fmaxf(v.z, min), max)
    };
}

Vec3 vec3_lerp(Vec3 a, Vec3 b, float t) {
    return vec3_add(vec3_mul(a, 1.0f - t), vec3_mul(b, t));
}
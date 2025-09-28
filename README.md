# Mini Ray Tracer in C

A minimalistic real-time ray tracer implemented in pure C with zero dependencies.

![Ray Tracing Demo](images/demo.png)

## ✨ Features

- 🎯 Pure C implementation (C99 standard)
- 🌈 Realistic reflections and shadows
- ⚡ Optimized for performance
- 📐 Custom vector mathematics library
- 🖼️ PPM image format output
- 🏗️ Clean, modular architecture

## 🚀 Quick Start

### Prerequisites
- CMake 3.15 or higher
- C compiler (GCC, Clang, or MSVC)

### Build Instructions

```bash
# Clone and build
git clone https://github.com/your-username/mini-raytracer-c.git
cd mini-raytracer-c

# Configure with CMake
mkdir build && cd build
cmake ..

# Build the project
make -j4  # Use 4 parallel jobs

# Run the ray tracer
./bin/raytracer output.ppm /output.png
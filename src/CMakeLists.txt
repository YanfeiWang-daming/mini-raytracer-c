# 源文件列表
set(MATH_SOURCES
    math/vector.c
)

set(CORE_SOURCES
    core/raytracer.c
    core/scene.c
)

set(OUTPUT_SOURCES
    output/ppm.c
)

set(MAIN_SOURCES
    main.c
)

# 创建静态库
add_library(raytracer_math STATIC ${MATH_SOURCES})
target_include_directories(raytracer_math 
    PUBLIC 
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
        $<INSTALL_INTERFACE:include>
)

add_library(raytracer_core STATIC ${CORE_SOURCES})
target_include_directories(raytracer_core 
    PUBLIC 
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
        $<INSTALL_INTERFACE:include>
)
target_link_libraries(raytracer_core PUBLIC raytracer_math)

add_library(raytracer_output STATIC ${OUTPUT_SOURCES})
target_include_directories(raytracer_output 
    PUBLIC 
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
        $<INSTALL_INTERFACE:include>
)
target_link_libraries(raytracer_output PUBLIC raytracer_math)

# 创建可执行文件
add_executable(raytracer ${MAIN_SOURCES})
target_include_directories(raytracer 
    PRIVATE 
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
)

# 链接库
target_link_libraries(raytracer 
    PUBLIC 
        raytracer_math
        raytracer_core
        raytracer_output
        m  # 数学库
)

# 设置可执行文件属性
set_target_properties(raytracer PROPERTIES
    OUTPUT_NAME "raytracer"
    VERSION ${MINI_RAY_TRACER_VERSION}
    SOVERSION ${MINI_RAY_TRACER_VERSION_MAJOR}
)

# 安装目标
install(TARGETS raytracer
    RUNTIME DESTINATION bin
    LIBRARY DESTINATION lib
    ARCHIVE DESTINATION lib
)

install(TARGETS raytracer_math raytracer_core raytracer_output
    EXPORT MiniRayTracerTargets
    LIBRARY DESTINATION lib
    ARCHIVE DESTINATION lib
    INCLUDES DESTINATION include
)
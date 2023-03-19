add_subdirectory(math)
add_subdirectory(colour)

add_executable(RayTracing main.cpp)

target_link_libraries(RayTracing math colour)
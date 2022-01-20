cmake_minimum_required(VERSION 3.21)
project(ray-tracer-5k)

set(CMAKE_CXX_STANDARD 20)

add_executable(ray-tracer-5k main.cpp Maths/Vec3.cpp Maths/Vec3.h Maths/Color.cpp Maths/Color.h Ray/Ray.cpp Ray/Ray.h Hittable/Hittable.cpp Hittable/Hittable.h Hittable/Sphere.cpp Hittable/Sphere.h Hittable/HittableWrapper.cpp Hittable/HittableWrapper.h Maths/Utils.h Camera/Camera.cpp Camera/Camera.h)

cmake_minimum_required(VERSION 3.21)
project(pt)

set(CMAKE_CXX_STANDARD 23)

add_executable(pt main.cpp maths/Vec3.cpp maths/Vec3.h maths/Color.cpp maths/Color.h ray/Ray.cpp ray/Ray.h)

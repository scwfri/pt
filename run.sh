#!/usr/bin/bash
set -e

setup() {
    if [ ! -d "./build" ]; then
        mkdir ./build
        cd build && cmake .. && cd -
    fi
    if [ ! -d "./out" ]; then
        mkdir ./out
    fi
}

make_exec() {
    if command -v compiledb &> /dev/null
    then
        cd ./build && compiledb make -j5 && cd -
    else
        cd ./build && make -j5 && cd -
    fi
}

gen_image() {
    ./build/ray-tracer-5k > ./out/out.ppm
}

view_image() {
    gimp ./out/out.ppm
}

setup
make_exec
gen_image
view_image

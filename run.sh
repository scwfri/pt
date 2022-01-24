#!/usr/bin/bash
set -e

make_exec() {
    if command -v compiledb &> /dev/null
    then
        compiledb make -j5
    else
        make -j5
    fi
}

gen_image() {
    ./ray-tracer-5k > ./out/out.ppm
}

view_image() {
    gimp ./out/out.ppm
}

make_exec
gen_image
view_image

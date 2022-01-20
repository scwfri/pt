#/usr/bin/bash
set -e

make_exec() {
    make -j5
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

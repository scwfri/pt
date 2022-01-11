CMAKE=cmake

default: build
.PHONY: run build

build:
	$(CMAKE) --build cmake-build-debug --target pt
	./cmake-build-debug/pt > ./out/out.ppm

run:
	$(build)
	gimp ./out/out.ppm

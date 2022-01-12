CMAKE=cmake

default: build
.PHONY: run build clean

build:
	$(CMAKE) --build cmake-build-debug --target pt
	./cmake-build-debug/pt > ./out/out.ppm

run:
	$(build)
	gimp ./out/out.ppm

clean:
	rm -rf ./out/out.ppm
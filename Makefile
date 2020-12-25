all: build/Makefile
	cmake --build build

build/Makefile: CMakeLists.txt source/CMakeLists.txt
	cmake -v -S . -B build

clean:
	@rm -rf build

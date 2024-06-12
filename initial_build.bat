git clone https://github.com/KhronosGroup/OpenCL-SDK.git
git submodule init
git submodule update
vcpkg --triplet x64-windows install sfml tclap glm
cmake -A x64 -D BUILD_TESTING=OFF -D BUILD_DOCS=OFF -D BUILD_EXAMPLES=OFF -D BUILD_TESTS=OFF -D OPENCL_SDK_BUILD_SAMPLES=ON -D OPENCL_SDK_TEST_SAMPLES=OFF -D CMAKE_TOOLCHAIN_FILE=%USERPROFILE%\vcpkg\scripts\buildsystems\vcpkg.cmake -D VCPKG_TARGET_TRIPLET=x64-windows -B ./OpenCL-SDK/build -S ./OpenCL-SDK
cmake --build ./OpenCL-SDK/build
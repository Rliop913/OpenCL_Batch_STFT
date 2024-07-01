# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.18.4)

# We name the project and the target for the ExternalProject_Add() call
# to something that will highlight to the user what we are working on if
# something goes wrong and an error message is produced.

project(opencl-populate NONE)

include(ExternalProject)
ExternalProject_Add(opencl-populate
                     "UPDATE_DISCONNECTED" "False" "GIT_REPOSITORY" "https://github.com/KhronosGroup/OpenCL-SDK.git" "GIT_TAG" "v2024.05.08"
                    SOURCE_DIR          "/mnt/g/Dropbox/Dropbox/box_inside/git_branch/cpps/STFT_SYCL/STFT_SYCL/linux_build/_deps/opencl-src"
                    BINARY_DIR          "/mnt/g/Dropbox/Dropbox/box_inside/git_branch/cpps/STFT_SYCL/STFT_SYCL/linux_build/_deps/opencl-build"
                    CONFIGURE_COMMAND   ""
                    BUILD_COMMAND       ""
                    INSTALL_COMMAND     ""
                    TEST_COMMAND        ""
                    USES_TERMINAL_DOWNLOAD  YES
                    USES_TERMINAL_UPDATE    YES
)



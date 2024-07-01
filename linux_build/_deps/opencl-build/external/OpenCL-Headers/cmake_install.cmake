# Install script for directory: /mnt/g/Dropbox/Dropbox/box_inside/git_branch/cpps/STFT_SYCL/STFT_SYCL/linux_build/_deps/opencl-src/external/OpenCL-Headers

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/mnt/g/Dropbox/Dropbox/box_inside/git_branch/cpps/STFT_SYCL/STFT_SYCL/linux_build/_deps/opencl-src/install")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "Release")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Install shared libraries without execute permission?
if(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)
  set(CMAKE_INSTALL_SO_NO_EXE "1")
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

# Set default install directory permissions.
if(NOT DEFINED CMAKE_OBJDUMP)
  set(CMAKE_OBJDUMP "/usr/bin/objdump")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include" TYPE DIRECTORY FILES "/mnt/g/Dropbox/Dropbox/box_inside/git_branch/cpps/STFT_SYCL/STFT_SYCL/linux_build/_deps/opencl-src/external/OpenCL-Headers/CL")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/share/cmake/OpenCLHeaders/OpenCLHeadersTargets.cmake")
    file(DIFFERENT EXPORT_FILE_CHANGED FILES
         "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/share/cmake/OpenCLHeaders/OpenCLHeadersTargets.cmake"
         "/mnt/g/Dropbox/Dropbox/box_inside/git_branch/cpps/STFT_SYCL/STFT_SYCL/linux_build/_deps/opencl-build/external/OpenCL-Headers/CMakeFiles/Export/share/cmake/OpenCLHeaders/OpenCLHeadersTargets.cmake")
    if(EXPORT_FILE_CHANGED)
      file(GLOB OLD_CONFIG_FILES "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/share/cmake/OpenCLHeaders/OpenCLHeadersTargets-*.cmake")
      if(OLD_CONFIG_FILES)
        message(STATUS "Old export file \"$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/share/cmake/OpenCLHeaders/OpenCLHeadersTargets.cmake\" will be replaced.  Removing files [${OLD_CONFIG_FILES}].")
        file(REMOVE ${OLD_CONFIG_FILES})
      endif()
    endif()
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/cmake/OpenCLHeaders" TYPE FILE FILES "/mnt/g/Dropbox/Dropbox/box_inside/git_branch/cpps/STFT_SYCL/STFT_SYCL/linux_build/_deps/opencl-build/external/OpenCL-Headers/CMakeFiles/Export/share/cmake/OpenCLHeaders/OpenCLHeadersTargets.cmake")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/cmake/OpenCLHeaders" TYPE FILE FILES "/mnt/g/Dropbox/Dropbox/box_inside/git_branch/cpps/STFT_SYCL/STFT_SYCL/linux_build/_deps/opencl-build/external/OpenCL-Headers/OpenCLHeaders/OpenCLHeadersConfig.cmake")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/cmake/OpenCLHeaders" TYPE FILE FILES "/mnt/g/Dropbox/Dropbox/box_inside/git_branch/cpps/STFT_SYCL/STFT_SYCL/linux_build/_deps/opencl-build/external/OpenCL-Headers/OpenCLHeaders/OpenCLHeadersConfigVersion.cmake")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/pkgconfig" TYPE FILE FILES "/mnt/g/Dropbox/Dropbox/box_inside/git_branch/cpps/STFT_SYCL/STFT_SYCL/linux_build/_deps/opencl-build/external/OpenCL-Headers/OpenCL-Headers.pc")
endif()


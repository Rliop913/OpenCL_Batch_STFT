# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

file(MAKE_DIRECTORY
  "G:/Dropbox/Dropbox/box_inside/git_branch/cpps/STFT_SYCL/STFT_SYCL/win_build/_deps/opencl-src"
  "G:/Dropbox/Dropbox/box_inside/git_branch/cpps/STFT_SYCL/STFT_SYCL/win_build/_deps/opencl-build"
  "G:/Dropbox/Dropbox/box_inside/git_branch/cpps/STFT_SYCL/STFT_SYCL/win_build/_deps/opencl-subbuild/opencl-populate-prefix"
  "G:/Dropbox/Dropbox/box_inside/git_branch/cpps/STFT_SYCL/STFT_SYCL/win_build/_deps/opencl-subbuild/opencl-populate-prefix/tmp"
  "G:/Dropbox/Dropbox/box_inside/git_branch/cpps/STFT_SYCL/STFT_SYCL/win_build/_deps/opencl-subbuild/opencl-populate-prefix/src/opencl-populate-stamp"
  "G:/Dropbox/Dropbox/box_inside/git_branch/cpps/STFT_SYCL/STFT_SYCL/win_build/_deps/opencl-subbuild/opencl-populate-prefix/src"
  "G:/Dropbox/Dropbox/box_inside/git_branch/cpps/STFT_SYCL/STFT_SYCL/win_build/_deps/opencl-subbuild/opencl-populate-prefix/src/opencl-populate-stamp"
)

set(configSubDirs Debug)
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "G:/Dropbox/Dropbox/box_inside/git_branch/cpps/STFT_SYCL/STFT_SYCL/win_build/_deps/opencl-subbuild/opencl-populate-prefix/src/opencl-populate-stamp/${subDir}")
endforeach()
if(cfgdir)
  file(MAKE_DIRECTORY "G:/Dropbox/Dropbox/box_inside/git_branch/cpps/STFT_SYCL/STFT_SYCL/win_build/_deps/opencl-subbuild/opencl-populate-prefix/src/opencl-populate-stamp${cfgdir}") # cfgdir has leading slash
endif()

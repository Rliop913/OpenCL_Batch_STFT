# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

file(MAKE_DIRECTORY
  "G:/Dropbox/Dropbox/box_inside/git_branch/cpps/STFT_SYCL/STFT_SYCL/build/_deps/cargs-external-src"
  "G:/Dropbox/Dropbox/box_inside/git_branch/cpps/STFT_SYCL/STFT_SYCL/build/_deps/cargs-external-build"
  "G:/Dropbox/Dropbox/box_inside/git_branch/cpps/STFT_SYCL/STFT_SYCL/build/_deps/cargs-external-subbuild/cargs-external-populate-prefix"
  "G:/Dropbox/Dropbox/box_inside/git_branch/cpps/STFT_SYCL/STFT_SYCL/build/_deps/cargs-external-subbuild/cargs-external-populate-prefix/tmp"
  "G:/Dropbox/Dropbox/box_inside/git_branch/cpps/STFT_SYCL/STFT_SYCL/build/_deps/cargs-external-subbuild/cargs-external-populate-prefix/src/cargs-external-populate-stamp"
  "G:/Dropbox/Dropbox/box_inside/git_branch/cpps/STFT_SYCL/STFT_SYCL/build/_deps/cargs-external-subbuild/cargs-external-populate-prefix/src"
  "G:/Dropbox/Dropbox/box_inside/git_branch/cpps/STFT_SYCL/STFT_SYCL/build/_deps/cargs-external-subbuild/cargs-external-populate-prefix/src/cargs-external-populate-stamp"
)

set(configSubDirs )
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "G:/Dropbox/Dropbox/box_inside/git_branch/cpps/STFT_SYCL/STFT_SYCL/build/_deps/cargs-external-subbuild/cargs-external-populate-prefix/src/cargs-external-populate-stamp/${subDir}")
endforeach()
if(cfgdir)
  file(MAKE_DIRECTORY "G:/Dropbox/Dropbox/box_inside/git_branch/cpps/STFT_SYCL/STFT_SYCL/build/_deps/cargs-external-subbuild/cargs-external-populate-prefix/src/cargs-external-populate-stamp${cfgdir}") # cfgdir has leading slash
endif()

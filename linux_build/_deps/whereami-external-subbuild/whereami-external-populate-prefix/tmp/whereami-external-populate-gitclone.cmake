
if(NOT "/mnt/g/Dropbox/Dropbox/box_inside/git_branch/cpps/STFT_SYCL/STFT_SYCL/linux_build/_deps/whereami-external-subbuild/whereami-external-populate-prefix/src/whereami-external-populate-stamp/whereami-external-populate-gitinfo.txt" IS_NEWER_THAN "/mnt/g/Dropbox/Dropbox/box_inside/git_branch/cpps/STFT_SYCL/STFT_SYCL/linux_build/_deps/whereami-external-subbuild/whereami-external-populate-prefix/src/whereami-external-populate-stamp/whereami-external-populate-gitclone-lastrun.txt")
  message(STATUS "Avoiding repeated git clone, stamp file is up to date: '/mnt/g/Dropbox/Dropbox/box_inside/git_branch/cpps/STFT_SYCL/STFT_SYCL/linux_build/_deps/whereami-external-subbuild/whereami-external-populate-prefix/src/whereami-external-populate-stamp/whereami-external-populate-gitclone-lastrun.txt'")
  return()
endif()

execute_process(
  COMMAND ${CMAKE_COMMAND} -E rm -rf "/mnt/g/Dropbox/Dropbox/box_inside/git_branch/cpps/STFT_SYCL/STFT_SYCL/linux_build/_deps/whereami-external-src"
  RESULT_VARIABLE error_code
  )
if(error_code)
  message(FATAL_ERROR "Failed to remove directory: '/mnt/g/Dropbox/Dropbox/box_inside/git_branch/cpps/STFT_SYCL/STFT_SYCL/linux_build/_deps/whereami-external-src'")
endif()

# try the clone 3 times in case there is an odd git clone issue
set(error_code 1)
set(number_of_tries 0)
while(error_code AND number_of_tries LESS 3)
  execute_process(
    COMMAND "/usr/bin/git"  clone --no-checkout "https://github.com/gpakosz/whereami.git" "whereami-external-src"
    WORKING_DIRECTORY "/mnt/g/Dropbox/Dropbox/box_inside/git_branch/cpps/STFT_SYCL/STFT_SYCL/linux_build/_deps"
    RESULT_VARIABLE error_code
    )
  math(EXPR number_of_tries "${number_of_tries} + 1")
endwhile()
if(number_of_tries GREATER 1)
  message(STATUS "Had to git clone more than once:
          ${number_of_tries} times.")
endif()
if(error_code)
  message(FATAL_ERROR "Failed to clone repository: 'https://github.com/gpakosz/whereami.git'")
endif()

execute_process(
  COMMAND "/usr/bin/git"  checkout ba364cd54fd431c76c045393b6522b4bff547f50 --
  WORKING_DIRECTORY "/mnt/g/Dropbox/Dropbox/box_inside/git_branch/cpps/STFT_SYCL/STFT_SYCL/linux_build/_deps/whereami-external-src"
  RESULT_VARIABLE error_code
  )
if(error_code)
  message(FATAL_ERROR "Failed to checkout tag: 'ba364cd54fd431c76c045393b6522b4bff547f50'")
endif()

set(init_submodules TRUE)
if(init_submodules)
  execute_process(
    COMMAND "/usr/bin/git"  submodule update --recursive --init 
    WORKING_DIRECTORY "/mnt/g/Dropbox/Dropbox/box_inside/git_branch/cpps/STFT_SYCL/STFT_SYCL/linux_build/_deps/whereami-external-src"
    RESULT_VARIABLE error_code
    )
endif()
if(error_code)
  message(FATAL_ERROR "Failed to update submodules in: '/mnt/g/Dropbox/Dropbox/box_inside/git_branch/cpps/STFT_SYCL/STFT_SYCL/linux_build/_deps/whereami-external-src'")
endif()

# Complete success, update the script-last-run stamp file:
#
execute_process(
  COMMAND ${CMAKE_COMMAND} -E copy
    "/mnt/g/Dropbox/Dropbox/box_inside/git_branch/cpps/STFT_SYCL/STFT_SYCL/linux_build/_deps/whereami-external-subbuild/whereami-external-populate-prefix/src/whereami-external-populate-stamp/whereami-external-populate-gitinfo.txt"
    "/mnt/g/Dropbox/Dropbox/box_inside/git_branch/cpps/STFT_SYCL/STFT_SYCL/linux_build/_deps/whereami-external-subbuild/whereami-external-populate-prefix/src/whereami-external-populate-stamp/whereami-external-populate-gitclone-lastrun.txt"
  RESULT_VARIABLE error_code
  )
if(error_code)
  message(FATAL_ERROR "Failed to copy script-last-run stamp file: '/mnt/g/Dropbox/Dropbox/box_inside/git_branch/cpps/STFT_SYCL/STFT_SYCL/linux_build/_deps/whereami-external-subbuild/whereami-external-populate-prefix/src/whereami-external-populate-stamp/whereami-external-populate-gitclone-lastrun.txt'")
endif()


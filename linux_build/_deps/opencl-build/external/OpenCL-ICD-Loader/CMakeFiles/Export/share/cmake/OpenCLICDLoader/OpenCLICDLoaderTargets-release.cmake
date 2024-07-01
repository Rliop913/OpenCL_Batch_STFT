#----------------------------------------------------------------
# Generated CMake target import file for configuration "Release".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "OpenCL::OpenCL" for configuration "Release"
set_property(TARGET OpenCL::OpenCL APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(OpenCL::OpenCL PROPERTIES
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/lib/libOpenCL.so.1.2"
  IMPORTED_SONAME_RELEASE "libOpenCL.so.1"
  )

list(APPEND _IMPORT_CHECK_TARGETS OpenCL::OpenCL )
list(APPEND _IMPORT_CHECK_FILES_FOR_OpenCL::OpenCL "${_IMPORT_PREFIX}/lib/libOpenCL.so.1.2" )

# Import target "OpenCL::cllayerinfo" for configuration "Release"
set_property(TARGET OpenCL::cllayerinfo APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(OpenCL::cllayerinfo PROPERTIES
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/bin/cllayerinfo"
  )

list(APPEND _IMPORT_CHECK_TARGETS OpenCL::cllayerinfo )
list(APPEND _IMPORT_CHECK_FILES_FOR_OpenCL::cllayerinfo "${_IMPORT_PREFIX}/bin/cllayerinfo" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)

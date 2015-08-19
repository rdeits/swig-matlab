cmake_minimum_required(VERSION 2.8.6)

include(ExternalProject)

ExternalProject_Add(swig-matlab
    GIT_REPOSITORY https://github.com/jaeandersson/swig
    GIT_TAG 8b8ae6df4def16d1589c7d262e95c4247601f120
    DOWNLOAD_DIR ${CMAKE_CURRENT_SOURCE_DIR}/swig-matlab
    SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/swig-matlab
    PATCH_COMMAND ${CMAKE_CURRENT_SOURCE_DIR}/swig-matlab/autogen.sh
    CONFIGURE_COMMAND ${CMAKE_CURRENT_SOURCE_DIR}/swig-matlab/configure --prefix=${CMAKE_INSTALL_PREFIX}
    BUILD_COMMAND make
    INSTALL_COMMAND make install
    )
cmake_minimum_required(VERSION 2.8.6)

include(ExternalProject)

set(EXTERNALS_DIR ${CMAKE_CURRENT_SOURCE_DIR}/externals)
ExternalProject_Add(swig-matlab
    GIT_REPOSITORY https://github.com/jaeandersson/swig
    GIT_TAG 3586dbf18c4d407b8321e0dafd24335002e28dc1
    DOWNLOAD_DIR ${EXTERNALS_DIR}/swig-matlab
    SOURCE_DIR ${EXTERNALS_DIR}/swig-matlab
    UPDATE_COMMAND ""
    PATCH_COMMAND ${EXTERNALS_DIR}/swig-matlab/autogen.sh
    CONFIGURE_COMMAND ${EXTERNALS_DIR}/swig-matlab/configure --prefix=${CMAKE_INSTALL_PREFIX} --with-matlab=${MATLAB_ROOT}
    BUILD_COMMAND make
    INSTALL_COMMAND make install
    )

ExternalProject_Add(demo
    SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src
    CMAKE_ARGS -DCMAKE_INSTALL_PREFIX=${CMAKE_INSTALL_PREFIX} -DCMAKE_BUILD_TYPE=${CMAKE_BUILD_TYPE}
    INSTALL_DIR ${CMAKE_INSTALL_PREFIX}
    DEPENDS swig-matlab
    )
ExternalProject_Add_Step(demo forceconfigure
 		COMMAND ${CMAKE_COMMAND} -E echo "Force configure"
 		DEPENDEES update
 		DEPENDERS configure
 		ALWAYS 1)

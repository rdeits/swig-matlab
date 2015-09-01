cmake_minimum_required(VERSION 2.8.6)

find_package( Eigen3 3.2 )
if (EIGEN3_FOUND)
  include_directories( ${EIGEN3_INCLUDE_DIR} )
else()
  message(FATAL_ERROR "Could not find eigen, which is a required depedency")
endif()

add_library(example SHARED example.cpp)

include(../cmake/mex.cmake)
mex_setup(REQUIRED)

set(SWIG_EXECUTABLE ${CMAKE_INSTALL_PREFIX}/bin/swig)
include(UseSWIG)

set(CMAKE_SWIG_OUTDIR ${CMAKE_INSTALL_PREFIX}/matlab)
set(I_FILE example.i)

set_source_files_properties(${I_FILE} PROPERTIES CPLUSPLUS ON)

include_directories(${MATLAB_ROOT}/extern/include ${MATLAB_ROOT}/simulink/include )
include_directories(${CMAKE_CURRENT_SOURCE_DIR})
swig_add_module(exampleMATLAB_wrap matlab ${I_FILE} ${CMAKE_CURRENT_SOURCE_DIR}/Matlabdef.def)
swig_link_libraries(exampleMATLAB_wrap example)
add_definitions(/DMATLAB_MEX_FILE) #define matlab macros
add_definitions(/DMX_COMPAT_32)

if(WIN32) # 32-bit or 64-bit mex
	if (CMAKE_CL_64)
	    SET_TARGET_PROPERTIES(exampleMATLAB_wrap PROPERTIES PREFIX "" SUFFIX .mexw64)
	else()
	    SET_TARGET_PROPERTIES(exampleMATLAB_wrap PROPERTIES SUFFIX .mexw32)
	endif()
else()
	if (${CMAKE_SYSTEM_NAME} MATCHES "Darwin")
	    if (${BITNESS} EQUAL "32")
	        SET_TARGET_PROPERTIES(exampleMATLAB_wrap PROPERTIES PREFIX "" SUFFIX .mexmaci32 PREFIX "")
	    elseif((${BITNESS} EQUAL "64"))
	        SET_TARGET_PROPERTIES(exampleMATLAB_wrap PROPERTIES PREFIX "" SUFFIX .mexmaci64 PREFIX "")
	    endif()
	else()
	    if (CMAKE_SIZEOF_VOID_P MATCHES "8")
	        SET_TARGET_PROPERTIES(exampleMATLAB_wrap PROPERTIES PREFIX "" SUFFIX .mexa64 PREFIX "")
	    else()
	        SET_TARGET_PROPERTIES(exampleMATLAB_wrap PROPERTIES PREFIX "" SUFFIX .mexglx PREFIX "")
	    endif()
	endif()
endif()

install(TARGETS exampleMATLAB_wrap example DESTINATION matlab)



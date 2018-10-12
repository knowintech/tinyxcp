MESSAGE(STATUS "make for Linux")
SET(CMAKE_SYSTEM_NAME Linux)
SET(CMAKE_SYSTEM_VERSION 1)
SET(CMAKE_SYSTEM_PROCESSOR x86)
SET(CMAKE_FIND_ROOT_PATH_MODE_PROGRAM NEVER)
SET(CMAKE_FIND_ROOT_PATH_MODE_LIBRARY ONLY)
SET(CMAKE_FIND_ROOT_PATH_MODE_INCLUDE ONLY)

#----------------------------------------------------------------------------
#
# for GCC
#
#----------------------------------------------------------------------------
ADD_DEFINITIONS(-Wno-multichar)
ADD_DEFINITIONS(-Wno-pointer-to-int-cast)
ADD_DEFINITIONS(-O1)
ADD_DEFINITIONS(-fPIC)
ADD_DEFINITIONS(-std=c99)
ADD_DEFINITIONS(-D_GNU_SOURCE)
ADD_DEFINITIONS(-D__LINUX__)

#----------------------------------------------------------------------------
#
# dependence Libraries
#
#----------------------------------------------------------------------------
SET(DEPENDENCE_LIB tinycrypto tinyfx tinymdns tiny)

#----------------------------------------------------------------------------
#
# DEBUG INFORMATION
#
#----------------------------------------------------------------------------
ADD_DEFINITIONS(-DTINY_DEBUG)

#----------------------------------------------------------------------------
#
# SRP Remote
#
#----------------------------------------------------------------------------
SET(SRP_REMOTE_ENABLED 0)

#----------------------------------------------------------------------------
#
# Export library
#
#----------------------------------------------------------------------------
SET(EXPORT_STATIC_LIBRARY 1)
SET(EXPORT_SHARED_LIBRARY 1)
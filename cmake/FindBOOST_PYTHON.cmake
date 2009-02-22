
##
# Includes
##

INCLUDE( ${CMAKE_MODULE_PATH}/base_definitions.cmake )

##
# Clear variables/caches
##

SET( BOOST_PYTHON_DEFINITIONS "" )
SET( BOOST_PYTHON_INCLUDE_DIR "PYTHON_INCLUDE_DIR-NOTFOUND" CACHE FILEPATH "Cleared." FORCE)
SET( BOOST_PYTHON_LIBRARIES "PYTHON_LIBRARIES-NOTFOUND" CACHE FILEPATH "Cleared." FORCE)


##
# Defined package variable
##

IF( WIN32 )
  IF( OE_CROSS_BUILD )
    SET( BOOST_PYTHON_INCLUDE_DIR ${AL_DIR}/crosstoolchain/staging/i486-linux/usr/include )
    SET( BOOST_PYTHON_LIBRARIES ${AL_DIR}/crosstoolchain/staging/i486-linux/usr/lib/libboost_python-mt.so )
  ELSE( OE_CROSS_BUILD )
    SET( BOOST_PYTHON_INCLUDE_DIR /usr/include/boost )
    SET( BOOST_PYTHON_LIBRARIES /bin/cygboost_python-gcc-mt-1_33_1.dll )
  ENDIF( OE_CROSS_BUILD )
ELSE( WIN32 )
  IF( OE_CROSS_BUILD )
    SET( BOOST_PYTHON_INCLUDE_DIR ${AL_DIR}/crosstoolchain/staging/i486-linux/usr/include )
    SET( BOOST_PYTHON_LIBRARIES ${AL_DIR}/crosstoolchain/staging/i486-linux/usr/lib/libboost_python-mt.so )
  ELSE( OE_CROSS_BUILD )
    SET( BOOST_PYTHON_INCLUDE_DIR /usr/include/ )
    IF ( APPLE )
      SET( BOOST_PYTHON_LIBRARIES /sw/lib/libboost_python.dylib )
    ELSE ( APPLE )
      SET( BOOST_PYTHON_LIBRARIES /usr/lib/libboost_python.so )
    ENDIF( APPLE )
  ENDIF( OE_CROSS_BUILD )
ENDIF( WIN32 )



IF( BOOST_PYTHON_INCLUDE_DIR AND BOOST_PYTHON_LIBRARIES )
  IF ( EXISTS BOOST_PYTHON_INCLUDE_DIR AND EXISTS BOOST_PYTHON_LIBRARIES )
    SET( BOOST_PYTHON_FOUND TRUE )
  ENDIF ( EXISTS BOOST_PYTHON_INCLUDE_DIR AND EXISTS BOOST_PYTHON_LIBRARIES )
ENDIF( BOOST_PYTHON_INCLUDE_DIR AND BOOST_PYTHON_LIBRARIES )

IF( NOT BOOST_PYTHON_FOUND AND BOOST_PYTHON_FIND_REQUIRED )
  IF( NOT BOOST_PYTHON_INCLUDE_DIR OR NOT EXISTS ${BOOST_PYTHON_INCLUDE_DIR} )
    MESSAGE( STATUS "Required include not found" )
    MESSAGE( FATAL_ERROR "Could not find BOOST_PYTHON include!" )
  ENDIF( NOT BOOST_PYTHON_INCLUDE_DIR OR NOT EXISTS ${BOOST_PYTHON_INCLUDE_DIR} )
  IF( NOT BOOST_PYTHON_LIBRARIES OR NOT EXISTS ${BOOST_PYTHON_LIBRARIES} )
    MESSAGE( STATUS "Required libraries not found" )
    MESSAGE( FATAL_ERROR "Could not find BOOST_PYTHON libraries!" )
  ENDIF( NOT BOOST_PYTHON_LIBRARIES OR NOT EXISTS ${BOOST_PYTHON_LIBRARIES} )
ENDIF( NOT BOOST_PYTHON_FOUND AND BOOST_PYTHON_FIND_REQUIRED )

# Finally, display informations if not in quiet mode
IF( NOT BOOST_PYTHON_FIND_QUIETLY )
  MESSAGE( STATUS "BOOST_PYTHON found " )
  MESSAGE( STATUS "  includes   : ${BOOST_PYTHON_INCLUDE_DIR}" )
  MESSAGE( STATUS "  libraries  : ${BOOST_PYTHON_LIBRARIES}" )
  MESSAGE( STATUS "  definitions: ${BOOST_PYTHON_DEFINITIONS}" )
ENDIF( NOT BOOST_PYTHON_FIND_QUIETLY )



MARK_AS_ADVANCED(
  BOOST_PYTHON_DEFINITIONS
  BOOST_PYTHON_INCLUDE_DIR
  BOOST_PYTHON_LIBRARIES
)

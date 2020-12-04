########################################################################
# Cmake module for finding MercuryAPI
#
# The following variabled will be defined:
#
#  MERCURY_API_FOUND
#  MERCURY_API_INCLUDE_DIR
#  MERCURY_API_LIBRARY
#

#MERCURY_API
find_path(MERCURY_API_INCLUDE_DIR tm_reader.h
   PATHS /usr/include
	/usr/include/mercuryapi
         /user/local/include/)
if(MERCURY_API_INCLUDE_DIR)
   message("Found MERCURY_API_INCLUDE_DIR  on: ${MERCURY_API_INCLUDE_DIR}")
   include_directories(${MERCURY_API_INCLUDE_DIR})

   find_library (MERCURY_API_LIBRARIES
                NAMES mercuryapi libmercuryapi
                PATHS /usr/lib
                      /usr/local/lib
                      /user/local/lib)
   if(MERCURY_API_LIBRARIES)
      message("Found MERCURY_API_LIBRARIES on:" ${MERCURY_API_LIBRARIES})
      set(MERCURY_API_FOUND true)
   else(MERCURY_API_LIBRARIES)
      message(SEND_ERROR "Not found MERCURY_API_LIBRARIES")
   endif(MERCURY_API_LIBRARIES)
else(MERCURY_API_INCLUDE_DIR)
   message(SEND_ERROR "Not found MERCURY_API_INCLUDE_DIR")
endif(MERCURY_API_INCLUDE_DIR)


set(CMAKE_VERBOSE_MAKEFILE on)
set(MWLIB_SRC mwlib.c)

include_directories(${MERCURY_API_INCLUDE_DIR} 
			${READLINE_INCLUDE_DIR}
			${PROJECT_SOURCE_DIR}/include)

add_library(mwlib SHARED ${MWLIB_SRC})
target_link_libraries( mwlib ${MERCURY_API_LIBRARIES} ${READLINE_LIBRARY})


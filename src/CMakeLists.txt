set(CMAKE_VERBOSE_MAKEFILE on)
set(SOURCES mrfid.cpp rfid.cpp)
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -std=c99 -Wall")

include_directories(${PROJECT_SOURCE_DIR}/include)


add_subdirectory(mwlib)

#add_executable(mercuryrfid ${SOURCES} /src rfid.cpp)
#target_link_libraries(mercuryrfid mwlib) #${catkin_LIBRARIES})
#add_dependencies(mrfid mwlib)

add_library(mercuryrfid SHARED rfid.cpp ../include/mrfid/rfid.h)
target_link_libraries(mercuryrfid mwlib ${MERCURY_API_LIBRARIES} ${READLINE_LIBRARY} )
#add_dependencies(rfid
 # ${${PROJECT_NAME}_EXPORTED_TARGETS}
 # ${catkin_EXPORTED_TARGETS})

 #add_executable(mrfid ${SOURCES})
 #target_link_libraries(mrfid mwlib ${catkin_LIBRARIES})
 #add_dependencies(mrfid mwlib)

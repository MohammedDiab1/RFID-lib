#########################################################################
# CMakeLists.txt file for building  demo with CMake                     #
#                                                                       #
# Copyright (c) 2017 Leopold Palomo-Avellaneda <leopold.palomo@upc.edu> #
#                                                                       #
# This file is free software: you can redistribute it and/or modify     #
# it under the terms of the GNU General Public License as published by  #
# the Free Software Foundation, either version 3 of the License, or     #
# (at your option) any later version.                                   #
#                                                                       #
# This program is distributed in the hope that it will be useful,       #
# but WITHOUT ANY WARRANTY; without even the implied warranty of        #
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         #
# GNU General Public License for more details.                          #
#                                                                       #
# You should have received a copy of the GNU General Public License     #
# along with this program.  If not, see <http://www.gnu.org/licenses/>. #
#########################################################################

cmake_minimum_required (VERSION 2.8.12)

project(mercuryrfid)

## Find catkin macros and libraries
## if COMPONENTS list like find_package(catkin REQUIRED COMPONENTS xyz)
## is used, also find other catkin packages
find_package(catkin REQUIRED COMPONENTS roscpp rospy std_msgs message_generation)

## System dependencies are found with CMake's conventions
# find_package(Boost REQUIRED COMPONENTS system)


## Uncomment this if the package has a setup.py. This macro ensures
## modules and global scripts declared therein get installed
## See http://ros.org/doc/groovy/api/catkin/html/user_guide/setup_dot_py.html
# catkin_python_setup()

#######################################
## Declare ROS messages and services ##
#######################################

## Generate messages in the 'msg' folder
 add_message_files(
 #/home/users/mohammed.sharafeldeen/catkin_ws/mrfid/src/msg
   FILES
  # Num.msg
 )

## Generate services in the 'srv' folder
 add_service_files(
# /home/users/mohammed.sharafeldeen/catkin_ws/mrfid/src/msg
   FILES
   MemoryInfo.srv
   epcUpdate.srv
   InfoTag.srv
   MemoryUpdate.srv
 )

## Generate added messages and services with any dependencies listed here
 generate_messages(
#/home/users/mohammed.sharafeldeen/catkin_ws/mrfid/src/msg
 DEPENDENCIES
   std_msgs
 )



###################################
## catkin specific configuration ##
###################################
## The catkin_package macro generates cmake config files for your package
## Declare things to be passed to dependent projects
## LIBRARIES: libraries you create in this project that dependent projects also need
## CATKIN_DEPENDS: catkin_packages dependent projects also need
## DEPENDS: system dependencies of this project that dependent projects also need
catkin_package(
#   INCLUDE_DIRS include
   CATKIN_DEPENDS message_runtime
#  LIBRARIES beginner_tutorials
#  CATKIN_DEPENDS roscpp rospy std_msgs
#  DEPENDS system_lib
)

###########
## Build ##
###########

## Specify additional locations of header files
## Your package locations should be listed before other locations
include_directories(include
  ${catkin_INCLUDE_DIRS}
)

## Declare a cpp library
#add_library(mrfid
#   src/${PROJECT_NAME}/mrfid.cpp
# )

## Declare a cpp executable
# add_executable(mrfid_node src/mrfid_node.cpp)


## Add cmake target dependencies of the executable/library
## as an example, message headers may need to be generated before nodes
# add_dependencies(mrfid_node mrfid_generate_messages_cpp)

## Specify libraries to link a library or executable target against
# target_link_libraries(mrfid_node
 #  ${catkin_LIBRARIES}
#)

#############
## Install ##
#############

# all install targets should use catkin DESTINATION variables
# See http://ros.org/doc/groovy/api/catkin/html/adv_user_guide/variables.html

# Mark executable scripts (Python etc.) for installation
# in contrast to setup.py, you can choose the destination
 install(PROGRAMS
   scripts/talker.py
   scripts/listener.py
   DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION}
 )

## Mark executables and/or libraries for installation
# install(TARGETS beginner_tutorials beginner_tutorials_node
#   ARCHIVE DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
#   LIBRARY DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
#   RUNTIME DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION}
# )

## Mark cpp header files for installation
# install(DIRECTORY include/${PROJECT_NAME}/
#   DESTINATION ${CATKIN_PACKAGE_INCLUDE_DESTINATION}
#   FILES_MATCHING PATTERN "*.h"
#   PATTERN ".svn" EXCLUDE
# )

## Mark other files for installation (e.g. launch and bag files, etc.)
# install(FILES
#   # myfile1
#   # myfile2
#   DESTINATION ${CATKIN_PACKAGE_SHARE_DESTINATION}
# )

#############
## Testing ##
#############

## Add gtest based cpp test target and link libraries
# catkin_add_gtest(${PROJECT_NAME}-test test/test_beginner_tutorials.cpp)
# if(TARGET ${PROJECT_NAME}-test)
#   target_link_libraries(${PROJECT_NAME}-test ${PROJECT_NAME})
# endif()

## Add folders to be run by python nosetests
# catkin_add_nosetests(test)


# Needed Modules
include(GNUInstallDirs)
include(CMakePackageConfigHelpers)
include(FindPkgConfig)

# Set policy for LINK_INTERFACE
cmake_policy(SET CMP0022 NEW)

set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake-modules)

# All versions need MercuryAPI
find_package(MercuryAPI REQUIRED)
include_directories(${MERCURY_API_INCLUDE_DIR})


find_package(Readline REQUIRED)
include_directories(${READLINE_INCLUDE_DIR})

#add_definitions("-DBARE_METAL")
add_subdirectory(src)

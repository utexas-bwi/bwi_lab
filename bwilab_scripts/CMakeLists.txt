cmake_minimum_required(VERSION 2.8.3)
project(bwilab_scripts)

find_package(catkin REQUIRED COMPONENTS roslint)
find_package(Boost REQUIRED COMPONENTS filesystem system)

catkin_package()

catkin_python_setup()

###########
## Build ##
###########

include_directories(${Boost_INCLUDE_DIR} ${catkin_INCLUDE_DIRS})
add_executable(bwilab src/authorization/bwilab.cpp)
target_link_libraries(bwilab ${catkin_LIBRARIES} ${Boost_LIBRARIES})

#############
## Install ##
#############

# NOTE: the "bwilab" executable is installed setuid in /usr/local/bin,
# and not in the usual ${CATKIN_PACKAGE_BIN_DESTINATION}.
install(TARGETS bwilab
        RUNTIME DESTINATION bin
        PERMISSIONS
          OWNER_READ OWNER_WRITE OWNER_EXECUTE
          GROUP_READ GROUP_EXECUTE
          WORLD_READ WORLD_EXECUTE
          SETUID)

set(${PROJECT_NAME}_PY_SCRIPTS scripts/distance_traveled)
catkin_install_python(PROGRAMS ${${PROJECT_NAME}_PY_SCRIPTS}
                      DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION})

install(PROGRAMS
          scripts/clone_server
          scripts/keygen
          scripts/upload
        DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION})

#############
## Testing ##
#############

# Lint Python modules
file(GLOB_RECURSE ${PROJECT_NAME}_PY_SRCS
     RELATIVE ${PROJECT_SOURCE_DIR} src/${PROJECT_NAME}/*.py)
roslint_python(${${PROJECT_NAME}_PY_SCRIPTS} ${${PROJECT_NAME}_PY_SRCS})

#if (CATKIN_ENABLE_TESTING)
#  add_subdirectory(tests)
#endif()

cmake_minimum_required(VERSION 2.8.3)
project(bwilab_scripts)

find_package(catkin REQUIRED)
catkin_package()

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

# NOTE: all scripts installed in /usr/local/lib/bwilab_scripts can be
# run under the "bwilab" user ID.  Be careful what goes there.
install(PROGRAMS scripts/upload
        DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION})

#############
## Testing ##
#############

#if (CATKIN_ENABLE_TESTING)
#  add_subdirectory(tests)
#endif()

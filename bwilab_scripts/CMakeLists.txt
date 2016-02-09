cmake_minimum_required(VERSION 2.8.3)
project(bwilab_scripts)

find_package(catkin REQUIRED roslint)
catkin_package()

###########
## Build ##
###########

#############
## Install ##
#############

set(${PROJECT_NAME}_PY_SCRIPTS, scripts/distance_traveled)
catkin_install_python(PROGRAMS ${${PROJECT_NAME}_PY_SCRIPTS}
                      DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION})

install(PROGRAMS scripts/clone_server scripts/upload
        DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION})

#############
## Testing ##
#############

# Lint Python modules
roslint_python(${${PROJECT_NAME}_PY_SCRIPTS})

#if (CATKIN_ENABLE_TESTING)
#  add_subdirectory(tests)
#endif()

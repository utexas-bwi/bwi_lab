cmake_minimum_required(VERSION 2.8.3)
project(bwilab_scripts)

find_package(catkin REQUIRED roslint)
catkin_package()

catkin_python_setup()

###########
## Build ##
###########

#############
## Install ##
#############

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

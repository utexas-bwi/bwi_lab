cmake_minimum_required(VERSION 2.8.3)
project(bwi_local)

find_package(catkin REQUIRED COMPONENTS roslint)
catkin_package()
catkin_python_setup()

#############
## Install ##
#############

# NOTE: the "bwi" executable is installed directly in /usr/local/bin,
# and not in the usual ${CATKIN_PACKAGE_BIN_DESTINATION}.
install(PROGRAMS scripts/bwi
        DESTINATION bin)

# Python scripts
set(${PROJECT_NAME}_PY_SCRIPTS
    scripts/distance_traveled
    scripts/plot_distance
    scripts/trace_arguments
    scripts/yaml_index)
catkin_install_python(PROGRAMS ${${PROJECT_NAME}_PY_SCRIPTS}
                      DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION})

# Other shell scripts
set(${PROJECT_NAME}_SHELL_SCRIPTS
    scripts/authorize_local
    scripts/bags
    scripts/clone_server
    scripts/keygen
    scripts/list_bags
    scripts/update_local)
install(PROGRAMS
          ${${PROJECT_NAME}_SHELL_SCRIPTS}
        DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION})

install(FILES completion/${PROJECT_NAME}-completion.bash
        DESTINATION etc/bash_completion.d)

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

cmake_minimum_required(VERSION 3.0.0)
project(ROS2CAN VERSION 0.1.0)

include(CTest)
enable_testing()

add_subdirectory(Inc/CanHeaders)

add_library(ROS2CAN STATIC
    Inc/putm_can_id_templates.hpp
    Inc/putm_can_interface.hpp
)

set_target_properties(ROS2CAN PROPERTIES LINKER_LANGUAGE CXX)
set_target_properties(ROS2CAN PROPERTIES VERSION ${PROJECT_VERSION})
set_target_properties(ROS2CAN PROPERTIES PUBLIC_HEADER Inc/putm_can_interface.hpp)

target_include_directories(ROS2CAN PRIVATE Inc)

include(GNUInstallDirs)

install(TARGETS ROS2CAN
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    PUBLIC_HEADER DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})

install(DIRECTORY Inc DESTINATION "/usr/local/include")
 
set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
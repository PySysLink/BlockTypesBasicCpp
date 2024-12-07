cmake_minimum_required(VERSION 3.11)

# Project name and version
project(BlockTypesBasicCpp VERSION 0.0)


# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)


# Check if the user has already set CMAKE_INSTALL_PREFIX
if(CMAKE_INSTALL_PREFIX_INITIALIZED_TO_DEFAULT)
    # Configure default installation paths based on the platform
    if(WIN32)
        set(CMAKE_INSTALL_PREFIX "C:/Program Files" CACHE PATH "Install path" FORCE)
    elseif(APPLE)
        set(CMAKE_INSTALL_PREFIX "/Applications" CACHE PATH "Install path" FORCE)
    else() # Assume Linux or other Unix-like systems
        set(CMAKE_INSTALL_PREFIX "/usr/local" CACHE PATH "Install path" FORCE)
    endif()
endif()

# Print the chosen installation path
message(STATUS "Default install path: ${CMAKE_INSTALL_PREFIX}")



# Add subdirectories
add_subdirectory(src)
# add_subdirectory(Tests)


set(PY_SYS_LINK_BASE_INCLUDE_DIRS "${CMAKE_INSTALL_PREFIX}/include")
set(PY_SYS_LINK_BASE_LIBRARIES "${CMAKE_INSTALL_PREFIX}/lib/libBlockTypesBasicCpp.a")

message("CMAKE_INSTALL_PREFIX: ${CMAKE_INSTALL_PREFIX}")

# Define installation rules for the project
install(DIRECTORY src/                # Install headers
    DESTINATION include/BlockTypes/BasicCpp
    FILES_MATCHING PATTERN "*.h"
)

install(TARGETS BlockTypesBasicCpp
    EXPORT BlockTypesBasicCppTargets # Associate this target with the export
    ARCHIVE DESTINATION lib
    LIBRARY DESTINATION lib
    RUNTIME DESTINATION bin
)


include(CMakePackageConfigHelpers)

# Generate the package configuration file for BlockTypesBasicCpp
install(EXPORT BlockTypesBasicCppTargets
    FILE BlockTypesBasicCppTargets.cmake
    NAMESPACE BlockTypes::BasicCpp::
    DESTINATION lib/cmake/BlockTypesBasicCpp
)

# Set the include directories and libraries for the package
set(PACKAGE_INCLUDE_DIRS "${CMAKE_INSTALL_PREFIX}/include")
set(PACKAGE_LIBRARIES "${CMAKE_INSTALL_PREFIX}/lib")


# Create and install the config file
configure_package_config_file(
    ${CMAKE_CURRENT_SOURCE_DIR}/BlockTypesBasicCppConfig.cmake.in
    ${CMAKE_BINARY_DIR}/BlockTypesBasicCppConfig.cmake
    INSTALL_DESTINATION lib/cmake/BlockTypesBasicCpp
)
install(FILES ${CMAKE_CURRENT_BINARY_DIR}/BlockTypesBasicCppConfig.cmake
    DESTINATION lib/cmake/BlockTypesBasicCpp
)


# Ensure the libraries are installed correctly
install(TARGETS BlockTypesBasicCpp
        ARCHIVE DESTINATION lib
        LIBRARY DESTINATION lib)


if(UNIX AND NOT APPLE) # Linux-specific
    install(CODE "execute_process(COMMAND ldconfig)")
endif()

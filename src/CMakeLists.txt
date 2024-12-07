# Define a library
add_library(BlockTypesBasicCpp SHARED
    SampleTime.cpp
)

target_include_directories(BlockTypesBasicCpp PRIVATE ${CMAKE_SOURCE_DIR}/src)

target_include_directories(BlockTypesBasicCpp
    PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>  # Include path for the build tree
        $<INSTALL_INTERFACE:include>                   # Include path for the installed tree
)
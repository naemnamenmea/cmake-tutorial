cmake_minimum_required(VERSION 3.13)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set_property(GLOBAL PROPERTY USE_FOLDERS ON)

list(APPEND CMAKE_MODULE_PATH
    "${CMAKE_SOURCE_DIR}/cmake")
include(common)
include(CMakePrintHelpers)

list(APPEND CMAKE_PREFIX_PATH
    "C:/Users/Andrew/source/c++libraries")

set(CMAKE_FIND_LIBRARY_PREFIXES "")
set(CMAKE_FIND_LIBRARY_SUFFIXES "lib")

option(MY_USE_UNITY_BUILD "use unity build" OFF)
option(MY_RUN_TESTS "enable testing" ON)

if(MY_RUN_TESTS)
    add_compile_definitions(LOCAL_RUN)
endif()

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

if (MY_USE_UNITY_BUILD)
# quom dev\EntryPoint\main.cpp out.cpp -I dev\libraries\libStatic\public -I dev\libraries\libDynamic\public -I dev\libraries\libDynamic\private -I dev\libraries\libStatic\private
    set(CMAKE_UNITY_BUILD ON)
    set(CMAKE_UNITY_BUILD_BATCH_SIZE 228)
endif()

option(MW_PROJECT_NAME_FROM_DIRECTORY "Use the directory name  of the source directory as project name" ON)
if(MW_PROJECT_NAME_FROM_DIRECTORY)
	mw_set_project_name_from_source_dir(project_name)
else()
	set(project_name "mySolution")
endif()
project(${project_name} C CXX)

add_subdirectory(libraries/libBasic)
add_subdirectory(libraries/libStatic)
add_subdirectory(libraries/libDynamic)

# external libs
add_subdirectory("C:/Users/Andrew/source/c++libraries" outside_root)

add_subdirectory(EntryPoint)

# get_target_property(INC entryPoint LINK_LIBRARIES)
# message("")
# message("${INC}")
# message("")
# get_link_libraries(BLAH entryPoint)
# foreach(TARGET ${BLAH})
#     get_target_property(THIS_TARGET_INCLUDES ${TARGET} INCLUDE_DIRECTORIES)
#     message(${THIS_TARGET_INCLUDES})
#     message("")
# endforeach()
# message("")

mw_set_default_project_filters()

# !это работает!
# get_link_libraries(_deps entryPoint)
# foreach(_dep IN LISTS _deps)
#     get_target_property(_inc_dirs ${_dep} INCLUDE_DIRECTORIES)
#     foreach(_inc_dir IN LISTS _inc_dirs)
#         message("${_inc_dir}")
#     endforeach()
# endforeach()


# foreach(A $<TARGET_PROPERTY:entryPoint,INCLUDE_DIRECTORIES>)
#     message(${A})
# endforeach()
# message("")

# file(GENERATE OUTPUT <filename> CONTENT <string-with-generator-expression>)
# file(GENERATE OUTPUT "blah.txt" CONTENT "$<TARGET_PROPERTY:entryPoint,INCLUDE_DIRECTORIES>")

# add_custom_command(TARGET mytarget POST_BUILD
#   COMMAND ${CMAKE_COMMAND} -E echo 
#   "target dir = $<TARGET_FILE_DIR:mytarget> $<1:hello> $<0:world>")

set(CMAKE_SUPPRESS_REGENERATION OFF)

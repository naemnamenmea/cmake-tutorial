get_filename_component(THIS_TARGET_NAME ${CMAKE_CURRENT_LIST_DIR} NAME)

if (MSVC)
    add_compile_options(/W4)
else()
    add_compile_options(-Wall -Wextra -Wpedantic)
endif()

add_executable(${THIS_TARGET_NAME} 
    main.cpp

    main.hpp
)

target_include_directories(${THIS_TARGET_NAME} PRIVATE ./)

target_link_libraries(${THIS_TARGET_NAME} PUBLIC libStatic)
target_link_libraries(${THIS_TARGET_NAME} PUBLIC math)
target_link_libraries(${THIS_TARGET_NAME} PUBLIC libDynamic)

get_target_property(THIS_TARGET_NAME_INCLUDES ${THIS_TARGET_NAME} INCLUDE_DIRECTORIES)
# message(${THIS_TARGET_NAME_INCLUDES})

get_target_property(STATIC_LIB_INCLUDES libStatic INCLUDE_DIRECTORIES)
# message(${STATIC_LIB_INCLUDES})

if (MY_USE_UNITY_BUILD)
    set_target_properties(${THIS_TARGET_NAME} PROPERTIES UNITY_BUILD ON)
    set_target_properties(${THIS_TARGET_NAME} PROPERTIES UNITY_BUILD_BATCH_SIZE 228)
    # if (MSVC)
    #     target_compile_options(${THIS_TARGET_NAME} PRIVATE /E)
    # endif()
endif()

mw_target_end(${THIS_TARGET_NAME})
set(THIS_TARGET_NAME "libStatic")

file(GLOB SRC_FILES
    src/*
    public/*
    private/*
)

add_library(${THIS_TARGET_NAME} STATIC ${SRC_FILES})

target_include_directories(${THIS_TARGET_NAME} PUBLIC public)
target_include_directories(${THIS_TARGET_NAME} PRIVATE private)

target_link_libraries(${THIS_TARGET_NAME} PUBLIC libBasic)

if (MY_USE_UNITY_BUILD)
    set_target_properties(${THIS_TARGET_NAME} PROPERTIES UNITY_BUILD ON)
    set_target_properties(${THIS_TARGET_NAME} PROPERTIES UNITY_BUILD_BATCH_SIZE 228)
    # if (MSVC)
    #     target_compile_options(${THIS_TARGET_NAME} PRIVATE /E)
    # endif()
endif()

mw_target_end(${THIS_TARGET_NAME})
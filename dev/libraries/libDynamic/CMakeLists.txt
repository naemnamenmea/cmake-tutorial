set(THIS_TARGET_NAME "libDynamic")

file(GLOB SRC_FILES
    src/*
    public/*
    private/*
)

add_library(${THIS_TARGET_NAME} SHARED ${SRC_FILES})

target_include_directories(${THIS_TARGET_NAME} PUBLIC public)
target_include_directories(${THIS_TARGET_NAME} PRIVATE private)

mw_target_end(libDynamic)
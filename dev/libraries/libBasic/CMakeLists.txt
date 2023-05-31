file(GLOB THIS_TARGET_SOURCES
    public/*
    src/*
    include/*
)

add_library(libBasic STATIC ${THIS_TARGET_SOURCES})

target_include_directories(libBasic PRIVATE ./private)
target_include_directories(libBasic PUBLIC ./public)

mw_target_end(libBasic)
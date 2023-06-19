add_executable(add_extern_lib)
file(GLOB SOURCE_FILES
    public/*.hpp
    public/*.h
    private/*.hpp
    private/*.h
    src/*.cpp
    src/*.c
    *.hpp
    *.h
    *.cpp
    *.c
)
target_sources(add_extern_lib PUBLIC ${SOURCE_FILES})

target_include_directories(add_extern_lib
    PUBLIC public
    PRIVATE private
    PRIVATE .
)
target_link_libraries(add_extern_lib PUBLIC my_testing_tools)
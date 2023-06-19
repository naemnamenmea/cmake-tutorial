add_executable(unity_build)

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
target_sources(unity_build PUBLIC ${SOURCE_FILES})

if (MY_USE_UNITY_BUILD)
    set_target_properties(unity_build PROPERTIES UNITY_BUILD ON)
    set_target_properties(unity_build PROPERTIES UNITY_BUILD_BATCH_SIZE 228)
    # if (MSVC)
    #     target_compile_options(unity_build PRIVATE /E)
    # endif()
endif()

mw_target_end(unity_build)
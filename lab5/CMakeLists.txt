set(CMAKE_C_STANDARD 11)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)

add_definitions( -DLIBRARY1="${CMAKE_BINARY_DIR}/lab3/libmath-analysis1.so" )
add_definitions( -DLIBRARY2="${CMAKE_BINARY_DIR}/lab3/libmath-analysis2.so" )

add_executable(lab3
    main.cpp
    src/mathematical-analysis1.cpp
)

target_include_directories(lab3 PRIVATE include)

add_library(
    math-analysis1 SHARED
    src/mathematical-analysis1.cpp
)

target_include_directories(math-analysis1 PRIVATE include)

add_library(
    math-analysis2 SHARED
    src/mathematical-analysis2.cpp
)

target_include_directories(math-analysis2 PRIVATE include)

add_compile_options("-ldl")

add_dependencies(lab3 math-analysis1 math-analysis2)

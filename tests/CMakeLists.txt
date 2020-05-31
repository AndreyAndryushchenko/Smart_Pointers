project(Tests CXX)

FILE(GLOB_RECURSE TESTS_POINTER ${PROJECT_SOURCE_DIR}/*.cpp)

add_executable(${PROJECT_NAME} ${TESTS_POINTER})

target_link_libraries(${PROJECT_NAME} smart_pointers)
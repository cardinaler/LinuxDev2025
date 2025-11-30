cmake_minimum_required(VERSION 3.10)
project(buf_prog C)

set(CMAKE_C_STANDARD 11)

set(TEST_DIR ${CMAKE_SOURCE_DIR}/tests)
set(SRC_DIR ${CMAKE_SOURCE_DIR}/src)
option(ENABLE_COVERAGE "Enable coverage" ON)

add_compile_options(--coverage)
add_link_options(--coverage)

add_library(buf SHARED ${SRC_DIR}/buf.c)
target_include_directories(buf PUBLIC ${SRC_DIR})


set(GENERATED_TEST_C ${CMAKE_BINARY_DIR}/tests.c)

add_custom_command(
    OUTPUT ${GENERATED_TEST_C}
    COMMAND checkmk ${TEST_DIR}/tests.ts > ${GENERATED_TEST_C}
    DEPENDS ${TEST_DIR}/tests.ts
)


add_executable(buf_tests
    ${GENERATED_TEST_C}
)


target_link_libraries(buf_tests
    buf
    check
    pthread
    rt
    m
    subunit
)

include(CTest) 

add_custom_target(coverage
        COMMAND ${CMAKE_CTEST_COMMAND} --output-on-failure
        COMMAND find -name "buf.c.gcda" | xargs gcov
        WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
    )

add_test(NAME buf_tests COMMAND buf_tests)

set_target_properties(buf_tests PROPERTIES
    BUILD_RPATH "${CMAKE_BINARY_DIR}"
)

set_target_properties(buf_tests PROPERTIES
    INSTALL_RPATH "$ORIGIN"
)

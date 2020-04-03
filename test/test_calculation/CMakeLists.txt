set(PROJECT "test_calculation")

find_library(LIB_CALCULATION calculation ${CMAKE_BINARY_DIR}/bin)

include_directories("../libs/calculation")

find_package(Qt5Test REQUIRED)

enable_testing()

add_executable(${PROJECT} tst_calculation.cpp)
add_test(NAME test_calculation COMMAND test_calculation)

target_link_libraries(${PROJECT} PRIVATE Qt5::Test)
target_link_libraries(${PROJECT} PRIVATE ${LIB_CALCULATION})


set(PROJECT "calculation")

add_library(${PROJECT} SHARED
  calculation_global.h
  calculation.cpp
  calculation.h
)

target_link_libraries(${PROJECT} PRIVATE Qt5::Core)

target_compile_definitions(${PROJECT} PRIVATE CALCULATION_LIBRARY)

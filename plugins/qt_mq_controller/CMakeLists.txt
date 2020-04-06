set(PROJECT "qt_mq_controller")

find_package(Qt5 REQUIRED COMPONENTS Mqtt)

add_library(${PROJECT} MODULE
    qt_mq_controller.cpp
    qt_mq_controller.h
    ../../src/base_mq_interface.h
    ../../src/base_mq_interface.cpp
)

target_link_libraries(${PROJECT} Qt5::Core Qt5::Mqtt)

enable_plugin(${PROJECT})

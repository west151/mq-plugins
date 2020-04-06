set(PROJECT "em_mq_controller")

find_package(Qt5 REQUIRED COMPONENTS Qmqtt)

add_library(${PROJECT} MODULE
    em_mq_controller.cpp
    em_mq_controller.h
    ../../src/base_mq_interface.h
    ../../src/base_mq_interface.cpp
)

target_link_libraries(${PROJECT} Qt5::Core Qt5::Qmqtt)

enable_plugin(${PROJECT})

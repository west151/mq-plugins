set(PROJECT "ui_controller")

add_library(${PROJECT} MODULE
    ui_controller.cpp
    ui_controller.h
    ../../src/system_manager_ui_interface.h
    ../../src/system_manager_ui_interface.cpp
)

target_link_libraries(${PROJECT} Qt5::Core Qt5::Qml Qt5::Quick)

enable_plugin(${PROJECT})

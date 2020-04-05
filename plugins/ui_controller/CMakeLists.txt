set(PROJECT "ui_controller")

qt5_add_resources(RESOURCES ui_controller.qrc)

add_library(${PROJECT} MODULE
    ui_controller.cpp
    ui_controller.h
    ../../src/base_ui_interface.h
    ../../src/base_ui_interface.cpp
    ${RESOURCES}
)

target_link_libraries(${PROJECT} Qt5::Core Qt5::Qml Qt5::Quick)

enable_plugin(${PROJECT})

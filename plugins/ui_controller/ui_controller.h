#ifndef UI_CONTROLLER_H
#define UI_CONTROLLER_H

#include <QQmlEngine>

#include "../../src/system_manager_ui_interface.h"

class ui_controller : public system_manager_ui_interface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.soft.application.ui.interface" FILE "ui_controller.json")
    Q_INTERFACES(system_manager_ui_interface)
public:
    ui_controller();
    ~ui_controller(){};

private:
    QQmlEngine * ptr_engine;
};

#endif // UI_CONTROLLER_H

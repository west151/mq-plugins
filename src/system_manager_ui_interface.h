#ifndef SYSTEM_MANAGER_UI_INTERFACE_H
#define SYSTEM_MANAGER_UI_INTERFACE_H

#include <QObject>

class system_manager_ui_interface : public QObject
{
    Q_OBJECT
public:
    explicit system_manager_ui_interface(QObject *parent = nullptr);
    virtual ~system_manager_ui_interface() {}

};

Q_DECLARE_INTERFACE(system_manager_ui_interface, "com.soft.application.ui.interface")

#endif // SYSTEM_MANAGER_UI_INTERFACE_H

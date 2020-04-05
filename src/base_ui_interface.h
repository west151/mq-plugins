#ifndef BASE_UI_INTERFACE_H
#define BASE_UI_INTERFACE_H

#include <QObject>

class base_ui_interface : public QObject
{
    Q_OBJECT
public:
    explicit base_ui_interface(QObject *parent = nullptr);
    virtual ~base_ui_interface() {}

};

Q_DECLARE_INTERFACE(base_ui_interface, "com.soft.application.ui.interface")

#endif // BASE_UI_INTERFACE_H

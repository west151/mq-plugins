#ifndef QT_MQ_CONTROLLER_H
#define QT_MQ_CONTROLLER_H

#include "../../src/base_mq_interface.h"

class qt_mq_controller : public base_mq_interface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.soft.application.mq.interface" FILE "qt_mq_controller.json")
    Q_INTERFACES(base_mq_interface)

public:
    qt_mq_controller();
    ~qt_mq_controller(){};

public slots:
};

#endif // QT_MQ_CONTROLLER_H

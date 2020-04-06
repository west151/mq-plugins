#ifndef EM_MQ_CONTROLLER_H
#define EM_MQ_CONTROLLER_H

#include "../../src/base_mq_interface.h"

class em_mq_controller : public base_mq_interface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.soft.application.mq.interface" FILE "em_mq_controller.json")
    Q_INTERFACES(base_mq_interface)
public:
    em_mq_controller();
    ~em_mq_controller(){};
};

#endif // QT_MQ_CONTROLLER_H

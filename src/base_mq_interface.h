#ifndef BASE_MQ_INTERFACE_H
#define BASE_MQ_INTERFACE_H

#include <QObject>

class base_mq_interface : public QObject
{
    Q_OBJECT
public:
    explicit base_mq_interface(QObject *parent = nullptr);
    virtual ~base_mq_interface() {}

};

Q_DECLARE_INTERFACE(base_mq_interface, "com.soft.application.mq.interface")

#endif // BASE_MQ_INTERFACE_H

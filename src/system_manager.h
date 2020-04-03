#ifndef SYSTEM_MANAGER_H
#define SYSTEM_MANAGER_H

#include <QObject>

class system_manager : public QObject
{
    Q_OBJECT
public:
    explicit system_manager(QObject *parent = nullptr);

    bool initialization();
    void program_launch(bool is_init_state);

signals:

private:

};

#endif // SYSTEM_MANAGER_H

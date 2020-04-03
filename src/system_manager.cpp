#include "system_manager.h"

#include <QDebug>

system_manager::system_manager(QObject *parent) : QObject(parent)
{

}

bool system_manager::initialization()
{
    qDebug() << tr("Start initialization ...");

    return false;
}

void system_manager::program_launch(bool is_init_state)
{
    qDebug() << tr("Program launch ...");

    Q_UNUSED(is_init_state)
}

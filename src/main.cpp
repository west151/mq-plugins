#include <QGuiApplication>

#include "system_manager.h"

int main(int argc, char *argv[])
{
    QGuiApplication a(argc, argv);

    system_manager core_manager;
    bool init_state = core_manager.initialization();
    core_manager.program_launch(init_state);

    return a.exec();
}

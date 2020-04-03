#ifndef SYSTEM_MANAGER_H
#define SYSTEM_MANAGER_H

#include <QObject>
#include <QMap>

class QPluginLoader;

class system_manager : public QObject
{
    Q_OBJECT
public:
    explicit system_manager(QObject *parent = nullptr);

    bool initialization();
    void program_launch(bool is_init_state);

signals:

private:
    // Hardcoded list of known plugins.
    QMap<QString, QString> known_plugins;
    bool is_known_plugins(const QString &name, const QString &version);

    // Load all Plugins
    void load_plugins();
    void load_ui_controller_plugin(QPluginLoader &plugin_loader, const QString plugin_name, const QString plugin_version_number);
};

#endif // SYSTEM_MANAGER_H

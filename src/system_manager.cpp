#include "system_manager.h"

#include <QDebug>
#include <QDir>
#include <QTimer>
#include <QCoreApplication>
#include <QPluginLoader>

#include "base_ui_interface.h"

#ifdef Q_OS_WIN
static const QString lib_prefix = "";
static const QString lib_extension = "dll";
#elif defined Q_OS_MACX
static const QString lib_extension = "dylib";
static const QString lib_prefix = "lib";
#else
static const QString lib_extension = "so";
static const QString lib_prefix = "lib";
#endif

system_manager::system_manager(QObject *parent) : QObject(parent)
{
    known_plugins.insert("ui_controller", "1.0.0");
}

bool system_manager::initialization()
{
    qDebug() << Q_FUNC_INFO << tr("Start initialization ...");

    load_plugins();

    return false;
}

void system_manager::program_launch(bool is_init_state)
{
    qDebug() << Q_FUNC_INFO << tr("Program launch ...");

    Q_UNUSED(is_init_state)
}

bool system_manager::is_known_plugins(const QString &name, const QString &version)
{
    bool is_name(false);
    bool is_version(false);

    is_name = known_plugins.contains(name);

    if(is_name)
        if(known_plugins.value(name) == version)
            is_version = true;

    if(is_name && is_version)
        return true;
    else
        return false;
}

void system_manager::load_plugins()
{
    qDebug() << Q_FUNC_INFO << tr("Load all Plugins ...");

    QTimer plugin_load_time;
    plugin_load_time.start();

    QDir plugins_dir = QDir(qApp->applicationDirPath());
    plugins_dir.cd("plugins");

    qDebug() << Q_FUNC_INFO << "Loading plugins from:" << plugins_dir.path();

    QStringList plugin_filter;
    plugin_filter << QString("*.%1").arg(lib_extension);
    QStringList plugins_list = plugins_dir.entryList(plugin_filter);

    foreach (QString candidate, plugins_list)
    {
        QString file_name = QString("%1").arg(plugins_dir.absoluteFilePath(candidate));
        qDebug() << Q_FUNC_INFO << "Loading" << file_name;

        QPluginLoader plugin_loader(file_name);
        QJsonObject meta_data = plugin_loader.metaData();
        qDebug() << Q_FUNC_INFO << "MetaData:" << meta_data;

        QString plugin_name = meta_data.value("MetaData").toObject().value("name").toString();
        QString plugin_version = meta_data.value("MetaData").toObject().value("version").toString();

        qDebug() << Q_FUNC_INFO << "Plugin name:" << plugin_name;
        qDebug() << Q_FUNC_INFO << "Plugin version:" << plugin_version;

        // Hardcoded
        if(is_known_plugins(plugin_name, plugin_version))
        {
            if(plugin_name == "ui_controller")
                load_ui_controller_plugin(plugin_loader, plugin_name, plugin_version);
        }
    }

    qDebug() << Q_FUNC_INFO << tr("Finished loading:") << plugin_load_time.interval() << tr("ms");
}

void system_manager::load_ui_controller_plugin(QPluginLoader &plugin_loader, const QString plugin_name, const QString plugin_version_number)
{
    qDebug() << Q_FUNC_INFO;

    QObject *plugin = plugin_loader.instance();

    if (plugin)
    {
        base_ui_interface * ctrl_plugin = qobject_cast<base_ui_interface*>(plugin);

        if (!ctrl_plugin) {
            qWarning() << Q_FUNC_INFO << "Plugin not loaded. Name and version okay but plugin did not load.";
        } else {
            qDebug() << Q_FUNC_INFO << "Plugin" << plugin_name << "loaded." << "With pointer:" << ctrl_plugin;
        }
    } else {
        qDebug() << Q_FUNC_INFO << "Plugin Load Error:";
        qDebug() << Q_FUNC_INFO << plugin_loader.errorString();
    }
}

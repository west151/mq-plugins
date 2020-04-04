#include "ui_controller.h"

ui_controller::ui_controller()
    : ptr_engine(new QQmlEngine()),
      ptr_quick_view(new QQuickView())
{
    ptr_quick_view->setSource(QUrl(QStringLiteral("qrc:/qml/main.qml")));

    ptr_quick_view->setMinimumSize(QSize(600,380));
    ptr_quick_view->show();
}

#include "QCollapsibleWidget.h"
#include "QCollapsibleWidgetplugin.h"

#include <QtPlugin>

QCollapsibleWidgetPlugin::QCollapsibleWidgetPlugin(QObject *parent)
    : QObject(parent)
{
    m_initialized = false;
}

void QCollapsibleWidgetPlugin::initialize(QDesignerFormEditorInterface * /* core */)
{
    if (m_initialized)
        return;

    // Add extension registrations, etc. here

    m_initialized = true;
}

bool QCollapsibleWidgetPlugin::isInitialized() const
{
    return m_initialized;
}

QWidget *QCollapsibleWidgetPlugin::createWidget(QWidget *parent)
{
    return new QCollapsibleWidget(parent);
}

QString QCollapsibleWidgetPlugin::name() const
{
    return QLatin1String("QCollapsibleWidget");
}

QString QCollapsibleWidgetPlugin::group() const
{
    return QLatin1String("Custom");
}

QIcon QCollapsibleWidgetPlugin::icon() const
{
    return QIcon();
}

QString QCollapsibleWidgetPlugin::toolTip() const
{
    return QLatin1String("QCollapsibleWidget");
}

QString QCollapsibleWidgetPlugin::whatsThis() const
{
    return QLatin1String("QCollapsibleWidget");
}

bool QCollapsibleWidgetPlugin::isContainer() const
{
    return false;
}

QString QCollapsibleWidgetPlugin::domXml() const
{
    return QLatin1String(
        "<ui language=\"c++\">\n"
            "<widget class=\"QCollapsibleWidget\" name=\"qCollapsibleWidget\">\n"
                "<property name=\"geometry\">\n"
                    "<rect>\n"
                        "<x>0</x>\n"
                        "<y>0</y>\n"
                        "<width>200</width>\n"
                        "<height>200</height>\n"
                    "</rect>\n"
                "</property>\n"
                "<widget class=\"QWidget\" name=\"contentWidget\">\n"
                "</widget>\n"
            "</widget>\n"
        "</ui>"
        );
}

QString QCollapsibleWidgetPlugin::includeFile() const
{
    return QLatin1String("QCollapsibleWidget.h");
}
#if QT_VERSION < 0x050000
Q_EXPORT_PLUGIN2(QCollapsibleWidgetPlugin, QCollapsibleWidgetPlugin)
#endif // QT_VERSION < 0x050000

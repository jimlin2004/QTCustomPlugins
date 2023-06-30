#include "LineEditFloat.h"
#include "LineEditFloatPlugin.h"

#include <QtPlugin>

LineEditFloatPlugin::LineEditFloatPlugin(QObject *parent)
    : QObject(parent)
{
    m_initialized = false;
}

void LineEditFloatPlugin::initialize(QDesignerFormEditorInterface * /* core */)
{
    if (m_initialized)
        return;

    // Add extension registrations, etc. here

    m_initialized = true;
}

bool LineEditFloatPlugin::isInitialized() const
{
    return m_initialized;
}

QWidget *LineEditFloatPlugin::createWidget(QWidget *parent)
{
    return new LineEditFloat(parent);
}

QString LineEditFloatPlugin::name() const
{
    return QLatin1String("LineEditFloat");
}

QString LineEditFloatPlugin::group() const
{
    return QLatin1String("input");
}

QIcon LineEditFloatPlugin::icon() const
{
    return QIcon();
}

QString LineEditFloatPlugin::toolTip() const
{
    return QLatin1String("");
}

QString LineEditFloatPlugin::whatsThis() const
{
    return QLatin1String("");
}

bool LineEditFloatPlugin::isContainer() const
{
    return false;
}

QString LineEditFloatPlugin::domXml() const
{
    return QLatin1String("<widget class=\"LineEditFloat\" name=\"lineEditFloat\">\n</widget>\n");
}

QString LineEditFloatPlugin::includeFile() const
{
    return QLatin1String("LineEditFloat.h");
}
#if QT_VERSION < 0x050000
Q_EXPORT_PLUGIN2(LineEditFloatPlugin, LineEditFloatPlugin)
#endif // QT_VERSION < 0x050000

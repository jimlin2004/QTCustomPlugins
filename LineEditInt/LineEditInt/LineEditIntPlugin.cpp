#include "LineEditInt.h"
#include "LineEditIntPlugin.h"

#include <QtPlugin>

LineEditIntPlugin::LineEditIntPlugin(QObject *parent)
    : QObject(parent)
{
    m_initialized = false;
}

void LineEditIntPlugin::initialize(QDesignerFormEditorInterface * /* core */)
{
    if (m_initialized)
        return;

    // Add extension registrations, etc. here

    m_initialized = true;
}

bool LineEditIntPlugin::isInitialized() const
{
    return m_initialized;
}

QWidget *LineEditIntPlugin::createWidget(QWidget *parent)
{
    return new LineEditInt(parent);
}

QString LineEditIntPlugin::name() const
{
    return QLatin1String("LineEditInt");
}

QString LineEditIntPlugin::group() const
{
    return QLatin1String("input");
}

QIcon LineEditIntPlugin::icon() const
{
    return QIcon();
}

QString LineEditIntPlugin::toolTip() const
{
    return QLatin1String("");
}

QString LineEditIntPlugin::whatsThis() const
{
    return QLatin1String("");
}

bool LineEditIntPlugin::isContainer() const
{
    return false;
}

QString LineEditIntPlugin::domXml() const
{
    return QLatin1String("<widget class=\"LineEditInt\" name=\"lineEditInt\">\n</widget>\n");
}

QString LineEditIntPlugin::includeFile() const
{
    return QLatin1String("LineEditInt.h");
}
#if QT_VERSION < 0x050000
Q_EXPORT_PLUGIN2(LineEditIntPlugin, LineEditIntPlugin)
#endif // QT_VERSION < 0x050000

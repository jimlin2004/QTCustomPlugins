#ifndef QCOLLAPSIBLEWIDGETEXTENSIONFACTORY_H
#define QCOLLAPSIBLEWIDGETEXTENSIONFACTORY_H

#include <QExtensionFactory>
#include <QCollapsibleWidget.h>

class QCollapsibleWidgetExtensionFactory: public QExtensionFactory
{
    Q_OBJECT
public:
    QCollapsibleWidgetExtensionFactory(QExtensionManager* parent = nullpter);
protected:
    QObject *createExtension(QObject *object, const QString &iid, QObject *parent) const override;
};

#endif // QCOLLAPSIBLEWIDGETEXTENSIONFACTORY_H

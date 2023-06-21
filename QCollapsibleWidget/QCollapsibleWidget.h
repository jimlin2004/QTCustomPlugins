#ifndef QCOLLAPSIBLEWIDGET_H
#define QCOLLAPSIBLEWIDGET_H

#include <QWidget>
#include <QLayout>
#include <QPushButton>
#include <QVBoxLayout>
#include <QChildEvent>
#include <QList>

class QCollapsibleWidget : public QWidget
{
    Q_OBJECT
    Q_PROPERTY(QString Title READ getTitle WRITE setTitle)
public:
    QCollapsibleWidget(QWidget *parent = 0);

    QString getTitle() const;
    void setTitle(QString title);
    void setLayout(QLayout* layout);
protected:
    void childEvent(QChildEvent *event) override;
private:
    QVBoxLayout* verticalLayout;
    QPushButton* pushButton;
    QWidget* contentWidget;
};

#endif // QCOLLAPSIBLEWIDGET_H

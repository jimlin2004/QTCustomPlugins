#include "QCollapsibleWidget.h"

QCollapsibleWidget::QCollapsibleWidget(QWidget *parent) :
    QWidget(parent)
{
    this->verticalLayout = new QVBoxLayout(this);
    this->setObjectName("verticalLayout");
    this->pushButton = new QPushButton(this);
    this->pushButton->setObjectName("pushButton");
    this->verticalLayout->addWidget(this->pushButton);
    this->verticalLayout->setContentsMargins(0, 0, 0, 0);
    this->verticalLayout->setSpacing(0);
}

QString QCollapsibleWidget::getTitle() const
{
    return this->pushButton->text();
}

void QCollapsibleWidget::setTitle(QString title)
{
    this->pushButton->setText(title);
}

void QCollapsibleWidget::setLayout(QLayout* layout)
{
    this->contentWidget->setLayout(layout);
}

void QCollapsibleWidget::childEvent(QChildEvent *event)
{
    if (event->type() == QChildEvent::ChildAdded)
    {
        if (event->child()->isWidgetType())
        {
            QWidget* widget = qobject_cast<QWidget*>(event->child());
            if (widget != nullptr)
            {
                this->verticalLayout->addWidget(widget);
                this->contentWidget = widget;
            }
            else
            {
                this->setObjectName("Add child error!!");
                this->contentWidget = nullptr;
            }
        }
    }
}

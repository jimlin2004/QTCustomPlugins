#include "LineEditFloat.h"

LineEditFloat::LineEditFloat(QWidget *parent)
    : QLineEdit(parent)
    , _dataPtr(nullptr)
    , _isEditing(false)
{
    connect(this, &LineEditFloat::editingFinished, this, &LineEditFloat::onEditingFinished);
    this->setEnabled(false);
}

void LineEditFloat::bind(float* ptr)
{
    if (ptr == nullptr)
        return;
    this->_dataPtr = ptr;
    this->setEnabled(true);
    this->setText(QString::number(*(ptr)));
}

void LineEditFloat::onEditingFinished()
{
    if (this->_dataPtr == nullptr)
        return;
    this->setValue(this->text().toFloat());
}

float LineEditFloat::getValue() const
{
    if (this->_dataPtr == nullptr)
        throw std::runtime_error("must bind data pointer before get its value");
    return *(this->_dataPtr);
}

void LineEditFloat::setValue(float val)
{
    if (this->_dataPtr == nullptr)
        throw std::runtime_error("must bind data pointer before set its value");
    (*this->_dataPtr) = val;
    this->setText(QString::number(*(this->_dataPtr)));
}

void LineEditFloat::refresh()
{
    if (this->_dataPtr != nullptr)
        this->setText(QString::number(*(this->_dataPtr)));
}

void LineEditFloat::focusInEvent(QFocusEvent* event)
{
    this->_isEditing = true;
    QLineEdit::focusInEvent(event);
}

void LineEditFloat::focusOutEvent(QFocusEvent* event)
{
    this->_isEditing = false;
    QLineEdit::focusOutEvent(event);
}

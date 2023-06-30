#ifndef LINEEDITINT_H
#define LINEEDITINT_H

#include <QLineEdit>
#include <exception>

class LineEditFloat : public QLineEdit
{
    Q_OBJECT

public:
    LineEditFloat(QWidget *parent = 0);
    void bind(float* ptr);
    float getValue() const;
private:
    float* _dataPtr;
private slots:
    void onEditingFinished();
};

#endif // LINEEDITINT_H

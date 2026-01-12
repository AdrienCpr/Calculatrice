#ifndef EXPRESSIONMODEL_H
#define EXPRESSIONMODEL_H

#include <QObject>

class ExpressionModel : public QObject {
    Q_OBJECT
public:
    explicit ExpressionModel(QObject *parent = nullptr) : QObject(parent) {}

    double a() const { return m_a; }
    double b() const { return m_b; }
    double c() const { return m_c; }

    double xMin() const { return m_xMin; }
    double xMax() const { return m_xMax; }

public slots:
    void setA(double v) { if (m_a == v) return; m_a = v; emit changed(); }
    void setB(double v) { if (m_b == v) return; m_b = v; emit changed(); }
    void setC(double v) { if (m_c == v) return; m_c = v; emit changed(); }

    void setXMin(double v) { if (m_xMin == v) return; m_xMin = v; emit changed(); }
    void setXMax(double v) { if (m_xMax == v) return; m_xMax = v; emit changed(); }

signals:
    void changed();

private:
    double m_a = 1.0;
    double m_b = 0.0;
    double m_c = 0.0;
    double m_xMin = -20.0;
    double m_xMax =  20.0;
};

#endif

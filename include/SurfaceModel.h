#ifndef SURFACEMODEL_H
#define SURFACEMODEL_H

#include <QObject>

class SurfaceModel : public QObject
{
    Q_OBJECT
public:
    explicit SurfaceModel(QObject *parent = nullptr);

    // Getters
    double a() const { return m_a; }
    double b() const { return m_b; }
    double xMin() const { return m_xMin; }
    double xMax() const { return m_xMax; }
    double yMin() const { return m_yMin; }
    double yMax() const { return m_yMax; }
    int stepsX() const { return m_stepsX; }
    int stepsY() const { return m_stepsY; }

    // f(x, y) = a * sin(x) * cos(y) + b
    double evaluate(double x, double y) const;

public slots:
    void setA(double a);
    void setB(double b);
    void setXMin(double v);
    void setXMax(double v);
    void setYMin(double v);
    void setYMax(double v);

signals:
    void parametersChanged();

private:
    double m_a;
    double m_b;
    double m_xMin, m_xMax;
    double m_yMin, m_yMax;
    int m_stepsX;
    int m_stepsY;
};

#endif // SURFACEMODEL_H

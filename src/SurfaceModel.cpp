#include "surfacemodel.h"
#include <cmath>

SurfaceModel::SurfaceModel(QObject *parent)
    : QObject(parent)
    , m_a(1.0)
    , m_b(0.0)
    , m_xMin(-10.0)
    , m_xMax(10.0)
    , m_yMin(-10.0)
    , m_yMax(10.0)
    , m_stepsX(50)
    , m_stepsY(50)
{
}

void SurfaceModel::setA(double a)
{
    if (m_a == a) return;
    m_a = a;
    emit parametersChanged();
}

void SurfaceModel::setB(double b)
{
    if (m_b == b) return;
    m_b = b;
    emit parametersChanged();
}

void SurfaceModel::setXMin(double v)
{
    if (m_xMin == v) return;
    m_xMin = v;
    emit parametersChanged();
}

void SurfaceModel::setXMax(double v)
{
    if (m_xMax == v) return;
    m_xMax = v;
    emit parametersChanged();
}

void SurfaceModel::setYMin(double v)
{
    if (m_yMin == v) return;
    m_yMin = v;
    emit parametersChanged();
}

void SurfaceModel::setYMax(double v)
{
    if (m_yMax == v) return;
    m_yMax = v;
    emit parametersChanged();
}

double SurfaceModel::evaluate(double x, double y) const
{
    return m_a * std::sin(x) * std::cos(y) + m_b;
}

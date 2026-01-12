#include "Graph3dDialog.h"
#include "surfacemodel.h"

#include <QtDataVisualization/q3dsurface.h>
#include <QtDataVisualization/qsurface3dseries.h>
#include <QtDataVisualization/qsurfacedataproxy.h>
#include <QtDataVisualization/qvalue3daxis.h>

#include <QWidget>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QFormLayout>
#include <QDoubleSpinBox>
#include <QGroupBox>

#include <QVector3D>
#include <algorithm>

Graph3DDialog::Graph3DDialog(QWidget* parent)
    : QDialog(parent),
    m_model(new SurfaceModel(this)),
    m_graph(new Q3DSurface()),
    m_series(new QSurface3DSeries()),
    m_spinA(new QDoubleSpinBox(this)),
    m_spinB(new QDoubleSpinBox(this)),
    m_spinXmin(new QDoubleSpinBox(this)),
    m_spinXmax(new QDoubleSpinBox(this)),
    m_spinYmin(new QDoubleSpinBox(this)),
    m_spinYmax(new QDoubleSpinBox(this))
{
    setWindowTitle("Grapheur 3D (itération 1) : f(x,y)= a*sin(x)*cos(y) + b");
    resize(1100, 700);

    // Q3DSurface est un QWindow
    m_container = QWidget::createWindowContainer(m_graph, this);
    m_container->setMinimumSize(650, 520);

    // Série
    m_graph->addSeries(m_series);

    // Axes
    m_graph->axisX()->setTitle("x");
    m_graph->axisY()->setTitle("z");
    m_graph->axisZ()->setTitle("y");

    // ===== Spinbox init
    auto initSpin = [](QDoubleSpinBox* s, double minV, double maxV, double step, int decimals) {
        s->setRange(minV, maxV);
        s->setSingleStep(step);
        s->setDecimals(decimals);
    };

    initSpin(m_spinA,   -1000, 1000, 0.1, 4);
    initSpin(m_spinB,   -1000, 1000, 0.1, 4);
    initSpin(m_spinXmin, -100,  100, 0.5, 4);
    initSpin(m_spinXmax, -100,  100, 0.5, 4);
    initSpin(m_spinYmin, -100,  100, 0.5, 4);
    initSpin(m_spinYmax, -100,  100, 0.5, 4);

    m_spinA->setValue(m_model->a());
    m_spinB->setValue(m_model->b());
    m_spinXmin->setValue(m_model->xMin());
    m_spinXmax->setValue(m_model->xMax());
    m_spinYmin->setValue(m_model->yMin());
    m_spinYmax->setValue(m_model->yMax());

    // Vue -> Modèle
    connect(m_spinA,   QOverload<double>::of(&QDoubleSpinBox::valueChanged), m_model, &SurfaceModel::setA);
    connect(m_spinB,   QOverload<double>::of(&QDoubleSpinBox::valueChanged), m_model, &SurfaceModel::setB);
    connect(m_spinXmin,QOverload<double>::of(&QDoubleSpinBox::valueChanged), m_model, &SurfaceModel::setXMin);
    connect(m_spinXmax,QOverload<double>::of(&QDoubleSpinBox::valueChanged), m_model, &SurfaceModel::setXMax);
    connect(m_spinYmin,QOverload<double>::of(&QDoubleSpinBox::valueChanged), m_model, &SurfaceModel::setYMin);
    connect(m_spinYmax,QOverload<double>::of(&QDoubleSpinBox::valueChanged), m_model, &SurfaceModel::setYMax);

    // Modèle -> Vue
    connect(m_model, &SurfaceModel::parametersChanged, this, &Graph3DDialog::updateSurface);

    // UI gauche
    auto* form = new QFormLayout();
    form->addRow("a", m_spinA);
    form->addRow("b", m_spinB);
    form->addRow("x min", m_spinXmin);
    form->addRow("x max", m_spinXmax);
    form->addRow("y min", m_spinYmin);
    form->addRow("y max", m_spinYmax);

    auto* box = new QGroupBox("Paramètres", this);
    box->setLayout(form);

    auto* leftLayout = new QVBoxLayout();
    leftLayout->addWidget(box);
    leftLayout->addStretch(1);

    auto* left = new QWidget(this);
    left->setLayout(leftLayout);

    auto* hl = new QHBoxLayout(this);
    hl->addWidget(left);
    hl->addWidget(m_container, 1);
    setLayout(hl);

    updateSurface();
}

Graph3DDialog::~Graph3DDialog() = default;

void Graph3DDialog::updateSurface()
{
    double xMin = m_model->xMin();
    double xMax = m_model->xMax();
    double yMin = m_model->yMin();
    double yMax = m_model->yMax();

    if (xMax == xMin) xMax = xMin + 0.01;
    if (yMax == yMin) yMax = yMin + 0.01;

    const double xmin = std::min(xMin, xMax);
    const double xmax = std::max(xMin, xMax);
    const double ymin = std::min(yMin, yMax);
    const double ymax = std::max(yMin, yMax);

    const int stepsX = m_model->stepsX();
    const int stepsY = m_model->stepsY();

    auto* dataArray = new QSurfaceDataArray;
    dataArray->reserve(stepsY);

    const float stepX = float((xmax - xmin) / double(stepsX - 1));
    const float stepY = float((ymax - ymin) / double(stepsY - 1));

    float zMin =  1e9f;
    float zMax = -1e9f;

    for (int j = 0; j < stepsY; ++j) {
        auto* row = new QSurfaceDataRow(stepsX);
        const float y = float(ymin + j * stepY);

        for (int i = 0; i < stepsX; ++i) {
            const float x = float(xmin + i * stepX);
            const float z = float(m_model->evaluate(x, y));

            (*row)[i].setPosition(QVector3D(x, z, y));

            zMin = std::min(zMin, z);
            zMax = std::max(zMax, z);
        }
        *dataArray << row;
    }

    m_series->dataProxy()->resetArray(dataArray);

    m_graph->axisX()->setRange(float(xmin), float(xmax));
    m_graph->axisZ()->setRange(float(ymin), float(ymax));
    if (zMin == zMax) { zMin -= 1.f; zMax += 1.f; }
    m_graph->axisY()->setRange(zMin, zMax);
}

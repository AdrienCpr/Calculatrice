#include "Graph2dDialog.h"
#include "ExpressionModel.h"
#include <QDoubleSpinBox>
#include <QFormLayout>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QWidget>

#include <algorithm>

static double f(double x, double a, double b, double c)
{
    return a * x * x + b * x + c;
}

Graph2DDialog::Graph2DDialog(QWidget* parent)
    : QDialog(parent),
    m_model(new ExpressionModel(this)),
    m_series(new QLineSeries()),
    m_chart(new QChart()),
    m_axisX(new QValueAxis()),
    m_axisY(new QValueAxis()),
    m_spinA(new QDoubleSpinBox()),
    m_spinB(new QDoubleSpinBox()),
    m_spinC(new QDoubleSpinBox()),
    m_spinXmin(new QDoubleSpinBox()),
    m_spinXmax(new QDoubleSpinBox())
{
    setWindowTitle("Grapheur 2D (itération 1) : a*x^2 + b*x + c");
    resize(900, 600);

    // ===== Chart
    m_chart->addSeries(m_series);
    m_chart->setTitle("a*x^2 + b*x + c");

    m_axisX->setTitleText("x");
    m_axisY->setTitleText("f(x)");

    m_chart->addAxis(m_axisX, Qt::AlignBottom);
    m_chart->addAxis(m_axisY, Qt::AlignLeft);

    m_series->attachAxis(m_axisX);
    m_series->attachAxis(m_axisY);

    auto* chartView = new QChartView(m_chart);
    chartView->setRenderHint(QPainter::Antialiasing);

    // ===== Controls
    for (auto* s : {m_spinA, m_spinB, m_spinC, m_spinXmin, m_spinXmax}) {
        s->setRange(-100000, 100000);
        s->setDecimals(4);
        s->setSingleStep(1);
    }

    m_spinA->setValue(m_model->a());
    m_spinB->setValue(m_model->b());
    m_spinC->setValue(m_model->c());
    m_spinXmin->setValue(m_model->xMin());
    m_spinXmax->setValue(m_model->xMax());

    connect(m_spinA, QOverload<double>::of(&QDoubleSpinBox::valueChanged), m_model, &ExpressionModel::setA);
    connect(m_spinB, QOverload<double>::of(&QDoubleSpinBox::valueChanged), m_model, &ExpressionModel::setB);
    connect(m_spinC, QOverload<double>::of(&QDoubleSpinBox::valueChanged), m_model, &ExpressionModel::setC);

    connect(m_spinXmin, QOverload<double>::of(&QDoubleSpinBox::valueChanged), m_model, &ExpressionModel::setXMin);
    connect(m_spinXmax, QOverload<double>::of(&QDoubleSpinBox::valueChanged), m_model, &ExpressionModel::setXMax);

    auto* form = new QFormLayout();
    form->addRow("a", m_spinA);
    form->addRow("b", m_spinB);
    form->addRow("c", m_spinC);
    form->addRow("x min", m_spinXmin);
    form->addRow("x max", m_spinXmax);

    auto* left = new QWidget();
    left->setLayout(form);

    auto* root = new QWidget();
    auto* hl = new QHBoxLayout(root);
    hl->addWidget(left);
    hl->addWidget(chartView, 1);

    auto* mainLayout = new QVBoxLayout(this);
    mainLayout->addWidget(root);

    connect(m_model, &ExpressionModel::changed, this, &Graph2DDialog::recompute);

    recompute();
}

void Graph2DDialog::recompute()
{
    m_series->clear();

    const double xmin = std::min(m_model->xMin(), m_model->xMax());
    const double xmax = std::max(m_model->xMin(), m_model->xMax());
    m_axisX->setRange(xmin, xmax);

    double ymin = 1e100;
    double ymax = -1e100;

    const int N = 800;
    for (int i = 0; i <= N; ++i) {
        const double t = double(i) / double(N);
        const double x = xmin + (xmax - xmin) * t;
        const double y = f(x, m_model->a(), m_model->b(), m_model->c());

        m_series->append(x, y);
        ymin = std::min(ymin, y);
        ymax = std::max(ymax, y);
    }

    if (ymin == ymax) { ymin -= 1; ymax += 1; }
    m_axisY->setRange(ymin, ymax);
}

#ifndef GRAPH2DDIALOG_H
#define GRAPH2DDIALOG_H

#include <QDialog>

#include <QtCharts/QChart>
#include <QtCharts/QChartView>
#include <QtCharts/QLineSeries>
#include <QtCharts/QValueAxis>

class QDoubleSpinBox;
class ExpressionModel;

class Graph2DDialog : public QDialog
{
    Q_OBJECT
public:
    explicit Graph2DDialog(QWidget* parent = nullptr);

private slots:
    void recompute();

private:
    ExpressionModel* m_model;

    QLineSeries* m_series;
    QChart*      m_chart;
    QValueAxis*  m_axisX;
    QValueAxis*  m_axisY;

    QDoubleSpinBox* m_spinA;
    QDoubleSpinBox* m_spinB;
    QDoubleSpinBox* m_spinC;
    QDoubleSpinBox* m_spinXmin;
    QDoubleSpinBox* m_spinXmax;
};

#endif // GRAPH2DDIALOG_H

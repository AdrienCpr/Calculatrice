#ifndef GRAPH3DDIALOG_H
#define GRAPH3DDIALOG_H

#include <QDialog>

QT_BEGIN_NAMESPACE
class QDoubleSpinBox;
class QWidget;
QT_END_NAMESPACE

class Q3DSurface;
class QSurface3DSeries;

class SurfaceModel;

class Graph3DDialog : public QDialog
{
    Q_OBJECT
public:
    explicit Graph3DDialog(QWidget* parent = nullptr);
    ~Graph3DDialog() override;

private slots:
    void updateSurface();

private:
    SurfaceModel* m_model = nullptr;

    QWidget* m_container = nullptr;

    Q3DSurface*       m_graph  = nullptr;
    QSurface3DSeries* m_series = nullptr;

    QDoubleSpinBox* m_spinA = nullptr;
    QDoubleSpinBox* m_spinB = nullptr;
    QDoubleSpinBox* m_spinXmin = nullptr;
    QDoubleSpinBox* m_spinXmax = nullptr;
    QDoubleSpinBox* m_spinYmin = nullptr;
    QDoubleSpinBox* m_spinYmax = nullptr;
};

#endif // GRAPH3DDIALOG_H

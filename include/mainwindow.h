#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_actionSauvegarder_triggered();
    void on_actionCharger_triggered();

    void on_actionSaisieExpression_triggered();
    void on_actionAffichage_notation_classique_triggered();
    void on_actionAffichage_notation_P_I_triggered();
    void on_actionAffichage_valeur_triggered();
    void on_actionAffichage_graphique_2D_triggered();
    void on_actionAffichage_graphique_3D_triggered();

    void on_actionSimplification_triggered();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H

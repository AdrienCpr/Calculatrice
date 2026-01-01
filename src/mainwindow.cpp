#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionSauvegarder_triggered()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_actionCharger_triggered()
{
    ui->stackedWidget->setCurrentIndex(2);
}

void MainWindow::on_actionSaisieExpression_triggered()
{
    ui->stackedWidget->setCurrentIndex(3);
}

void MainWindow::on_actionAffichage_notation_classique_triggered()
{
    ui->stackedWidget->setCurrentIndex(4);
}

void MainWindow::on_actionAffichage_notation_P_I_triggered()
{
    ui->stackedWidget->setCurrentIndex(5);
}

void MainWindow::on_actionAffichage_valeur_triggered()
{
    ui->stackedWidget->setCurrentIndex(6);
}

void MainWindow::on_actionAffichage_graphique_2D_triggered()
{
    ui->stackedWidget->setCurrentIndex(7);
}

void MainWindow::on_actionAffichage_graphique_3D_triggered()
{
    ui->stackedWidget->setCurrentIndex(8);
}

void MainWindow::on_actionSimplification_triggered()
{
    ui->stackedWidget->setCurrentIndex(9);
}

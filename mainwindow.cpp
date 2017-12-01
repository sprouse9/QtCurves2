#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

// Change the background color for the render Area
void MainWindow::on_btnAstroid_clicked()
{
    //use the ui object that belongs to the main window to access our render area
    this->ui->renderArea->setShape(RenderArea::Astroid);
    this->ui->renderArea->repaint();
}

void MainWindow::on_btnCycloid_clicked()
{
    this->ui->renderArea->setShape(RenderArea::Cycloid);
    this->ui->renderArea->repaint();
}

void MainWindow::on_btnHuygens_clicked()
{
    this->ui->renderArea->setShape(RenderArea::HuygensCycloid);
    this->ui->renderArea->repaint();
}

void MainWindow::on_btnHypo_clicked()
{
    this->ui->renderArea->setShape(RenderArea::HypoCycloid);
    this->ui->renderArea->repaint();
}

void MainWindow::on_btnFutureCurve_clicked()
{
    this->ui->renderArea->setShape(RenderArea::FutureCurve);
    this->ui->renderArea->repaint();
}

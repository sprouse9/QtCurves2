#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QColorDialog>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->ui->spinScale->setValue( this->ui->renderArea->scale() );
    this->ui->spinInterval->setValue( this->ui->renderArea->intervalLength());
    this->ui->spinCount->setValue( this->ui->renderArea->stepCount() );
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
    update_ui();
}

void MainWindow::on_btnCycloid_clicked()
{
    this->ui->renderArea->setShape(RenderArea::Cycloid);
    this->ui->renderArea->repaint();
    update_ui();
}

void MainWindow::on_btnHuygens_clicked()
{
    this->ui->renderArea->setShape(RenderArea::HuygensCycloid);
    this->ui->renderArea->repaint();
    update_ui();
}

void MainWindow::on_btnHypo_clicked()
{
    this->ui->renderArea->setShape(RenderArea::HypoCycloid);
    this->ui->renderArea->repaint();
    update_ui();
}

void MainWindow::on_btnFutureCurve_clicked()
{
    this->ui->renderArea->setShape(RenderArea::FutureCurve);
    this->ui->renderArea->repaint();
    update_ui();
}

void MainWindow::on_btnLine_clicked()
{
    this->ui->renderArea->setShape(RenderArea::Line);
    this->ui->renderArea->repaint();
    update_ui();
}

void MainWindow::on_spinScale_valueChanged(double scale)
{
    this->ui->renderArea->setScale( scale );
}

void MainWindow::update_ui()
{
    this->ui->spinScale->setValue( this->ui->renderArea->scale() );
    this->ui->spinInterval->setValue( this->ui->renderArea->intervalLength());
    this->ui->spinCount->setValue( this->ui->renderArea->stepCount() );
}

void MainWindow::on_spinInterval_valueChanged(double interval)
{
    this->ui->renderArea->setInterval( interval );
}

void MainWindow::on_spinCount_valueChanged(int count)
{
    this->ui->renderArea->setStepCount( count );
}

void MainWindow::on_btnBackgroundColor_clicked()
{
    QColor color = QColorDialog::getColor(this->ui->renderArea->backgroundColor(), this, "Select Color", QColorDialog::DontUseNativeDialog);

    if( color.isValid() ){
        ui->renderArea->setBackgroundColor(color);
        ui->renderArea->repaint();
    }

}

void MainWindow::on_btnLineColor_clicked()
{
    QColor color = QColorDialog::getColor(this->ui->renderArea->shapeColor(), this, "Select Color");
    if( color.isValid() ){
        ui->renderArea->setShapeColor(color);
        ui->renderArea->repaint();
    }
}

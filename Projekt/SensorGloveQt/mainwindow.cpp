#include "includes.h"
#include "cmath"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->StartStopButton->setStyleSheet("background-color: rgb(225,240,80)");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::getScene(Scene *p_scene)
{
    scene3D = p_scene;
    AddWidgetToGlove3DLayout(scene3D->widget);
}

void MainWindow::AddWidgetToGlove3DLayout(QWidget *widget)
 {
     widget->resize(600,400);
     ui->centralWidget->width();
     ui->Glove3DLayout->addWidget(widget);
 }

void MainWindow::InitInputData(Input * data)
{
    InputData = data;
}

void MainWindow::on_StartStopButton_clicked()
{
    if(ui->StartStopButton->text() == "Start")
    {
        ui->StartStopButton->setText("Stop");
        ui->StartStopButton->setStyleSheet("background-color: rgb(240,125,70)");

    }
    else
    {
        ui->StartStopButton->setText("Start");
        ui->StartStopButton->setStyleSheet("background-color: rgb(225,240,80)");
    }
}

void MainWindow::on_CameraOrientationSlider_valueChanged(int value)
{
    ui->CameraOrientationLineEdit->setText(QString::number(value));
    //scene3D->cameraEntity->setPosition(QVector3D(10,10,value));
    int r = 50*ui->GloveZoomSlider->value() / 100 + 10;
    scene3D->cameraEntity->setPosition(QVector3D(sin(M_PI*value/180)*r, 10, cos(M_PI*value/180)*r));

    scene3D->camController->setCamera(scene3D->cameraEntity);

}

void MainWindow::on_CameraOrientationLineEdit_textEdited(const QString &arg1)
{
    bool isDgt = true;
    for (int i = 0; i < arg1.length(); ++i) {

        isDgt = arg1.at(i).isDigit() && isDgt;
    }
    if (!isDgt)
        ui->CameraOrientationLineEdit->setText(QString::number(ui->CameraOrientationSlider->value()));
}

void MainWindow::on_CameraOrientationLineEdit_editingFinished()
{
    QString arg = ui->CameraOrientationLineEdit->text();
    ui->CameraOrientationSlider->setValue(arg.toInt());
}

void MainWindow::on_GloveZoomSlider_valueChanged(int value)
{
    ui->GloveZoomLineEdit->setText(QString::number(value));

    int r = 50*value / 100 + 10;
    int angle = ui->CameraOrientationSlider->value();
    scene3D->cameraEntity->setPosition(QVector3D(sin(M_PI*angle/180)*r, 10, cos(M_PI*angle/180)*r));

    scene3D->camController->setCamera(scene3D->cameraEntity);
}

void MainWindow::on_GloveZoomLineEdit_textEdited(const QString &arg1)
{
    bool isDgt = true;
    for (int i = 0; i < arg1.length(); ++i) {

        isDgt = arg1.at(i).isDigit() && isDgt;
    }
    if (!isDgt)
        ui->GloveZoomLineEdit->setText(QString::number(ui->GloveZoomSlider->value()));
}

void MainWindow::on_GloveZoomLineEdit_editingFinished()
{
    QString arg = ui->GloveZoomLineEdit->text();
    ui->GloveZoomSlider->setValue(arg.toInt());
}

void MainWindow::on_par1_valueChanged(int value)
{
    scene3D->cameraEntity->setPosition(QVector3D(value,ui->par2->value(),ui->par3->value()));
    scene3D->camController->setCamera(scene3D->cameraEntity);
}

void MainWindow::on_par2_valueChanged(int value)
{
    scene3D->cameraEntity->setPosition(QVector3D(ui->par1->value(),value,ui->par3->value()));
    scene3D->camController->setCamera(scene3D->cameraEntity);
}

void MainWindow::on_par3_valueChanged(int value)
{
    //scene3D->cameraEntity->setPosition(QVector3D(ui->par1->value(),ui->par2->value(),value));
    //scene3D->camController->setCamera(scene3D->cameraEntity);
//    scene3D->camController->
}

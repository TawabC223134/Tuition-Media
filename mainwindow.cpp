#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ptrAddMember = new AddMember();
    ptrAddTutor = new AddTutor();
    ptrFindTution = new FindTution();
    ptrFindTutor = new FindTutor();
}

MainWindow::~MainWindow()
{
    delete ptrAddMember;
    delete ptrAddTutor;
    delete ptrFindTution;
    delete ptrFindTutor;
    delete ui;

}


void MainWindow::on_pushButton_5_clicked()
{
    ptrAddTutor->show();
}



void MainWindow::on_pushButton_7_clicked()
{
    ptrFindTutor->show();
}


void MainWindow::on_pushButton_3_clicked()
{
    ptrAddMember->show();
}


void MainWindow::on_pushButton_6_clicked()
{
    ptrFindTution->show();
}


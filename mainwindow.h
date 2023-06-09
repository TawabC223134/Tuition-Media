#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "addmember.h"
#include "addtutor.h"
#include "findtution.h"
#include "findtutor.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_5_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_6_clicked();

private:
    Ui::MainWindow *ui;
    AddTutor *ptrAddTutor;
    AddMember *ptrAddMember;
    FindTution *ptrFindTution;
    FindTutor *ptrFindTutor;

};
#endif // MAINWINDOW_H

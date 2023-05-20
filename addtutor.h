#ifndef ADDTUTOR_H
#define ADDTUTOR_H

#include <QDialog>
#include "databaseheader.h"

namespace Ui {
class AddTutor;
}

class AddTutor : public QDialog
{
    Q_OBJECT

public:
    explicit AddTutor(QWidget *parent = nullptr);
    ~AddTutor();

private slots:
    void on_btnSave_clicked();

    void on_btnReset_clicked();

private:
    Ui::AddTutor *ui;
};

#endif // ADDTUTOR_H

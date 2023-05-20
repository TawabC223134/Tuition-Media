#ifndef ADDMEMBER_H
#define ADDMEMBER_H

#include <QDialog>
#include "databaseheader.h"

namespace Ui {
class AddMember;
}

class AddMember : public QDialog
{
    Q_OBJECT

public:
    explicit AddMember(QWidget *parent = nullptr);
    ~AddMember();

private slots:
    void on_btnSave_clicked();

    void on_btnReset_clicked();

private:
    Ui::AddMember *ui;
};

#endif // ADDMEMBER_H

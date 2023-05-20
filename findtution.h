#ifndef FINDTUTION_H
#define FINDTUTION_H

#include <QDialog>
#include "databaseheader.h"

namespace Ui {
class FindTution;
}

class FindTution : public QDialog
{
    Q_OBJECT

public:
    explicit FindTution(QWidget *parent = nullptr);
    ~FindTution();

private slots:
    void on_btnFindTution_clicked();

    void on_btnReset_clicked();

private:
    Ui::FindTution *ui;
    QSqlQueryModel *model;
};

#endif // FINDTUTION_H

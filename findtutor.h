#ifndef FINDTUTOR_H
#define FINDTUTOR_H

#include <QDialog>
#include "databaseheader.h"

namespace Ui {
class FindTutor;
}

class FindTutor : public QDialog
{
    Q_OBJECT

public:
    explicit FindTutor(QWidget *parent = nullptr);
    ~FindTutor();

private slots:
    void on_btnFindTutor_clicked();

    void on_btnReset_clicked();

private:
    Ui::FindTutor *ui;
    QSqlQueryModel *model;
};

#endif // FINDTUTOR_H

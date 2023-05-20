#include "findtutor.h"
#include "ui_findtutor.h"

FindTutor::FindTutor(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::FindTutor)
{
    ui->setupUi(this);
}

FindTutor::~FindTutor()
{
    delete ui;
    delete model;
}

void FindTutor::on_btnFindTutor_clicked()
{
    QString permenantAddress = ui->txtTutorLocation->text();
        qDebug() << "Tutor Location : "<< permenantAddress  ;

    QSqlDatabase database = QSqlDatabase::addDatabase("QSQLITE");
    database.setDatabaseName("C:/Users/AC/OneDrive/Documents/QtProjects/TutionMedia/TutionMedia.db");

    if(QFile::exists("C:/Users/AC/OneDrive/Documents/QtProjects/TutionMedia/TutionMedia.db"))
    {
        qDebug() << "Database file exists";
    }
    else
    {
        qDebug() << "Database doesn't exists!";
        return;
    }

    if(!database.open())
    {
        qDebug() << "Error!Unable to open Database";
        return;
    }
    else
    {
        qDebug() << "Database open successfully";
    }

    QSqlQuery query(database);

    query.prepare("select * from Tutor where PermenantAddress like '%" + permenantAddress + "%'");
    query.exec();
    qDebug() << "Last query : " << query.lastQuery();
    qDebug() << "Last error : " << query.lastError().text();


    if(model == NULL)
    {
        model = new QSqlQueryModel();
    }
    model->setQuery(std::move(query));
    ui->tableView->setModel(model);
    ui->tableView->setColumnWidth(0,200);
    ui->tableView->setColumnWidth(1,200);
    ui->tableView->setColumnWidth(2,200);
    database.close();
}


void FindTutor::on_btnReset_clicked()
{
    ui->txtTutorLocation->clear();

}


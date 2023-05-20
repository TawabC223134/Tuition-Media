#include "findtution.h"
#include "ui_findtution.h"

FindTution::FindTution(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::FindTution)
{
    ui->setupUi(this);

}

FindTution::~FindTution()
{
    delete ui;
    delete model;
}

void FindTution::on_btnFindTution_clicked()
{

    QString memberAddress = ui->txtTutionLocation->text();
        qDebug() << "Tution Location : "<< memberAddress  ;

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

    query.prepare("select * from Member where Address like '%" + memberAddress + "%'");
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


void FindTution::on_btnReset_clicked()
{
    ui->txtTutionLocation->clear();
}


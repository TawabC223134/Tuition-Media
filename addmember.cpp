#include "addmember.h"
#include "ui_addmember.h"

AddMember::AddMember(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddMember)
{
    ui->setupUi(this);
}

AddMember::~AddMember()
{
    delete ui;
}

void AddMember::on_btnSave_clicked()
{
    QString memberName = ui->txtMemberName->text();
    QString memberPhone = ui->txtMemberPhone->text();
    QString memberAddress = ui->txtMemberAddress->text();

    qDebug() << "Member Name : " << memberName << "Member Phone No. : " << memberPhone << "Member Address : " << memberAddress;

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
    query.prepare("INSERT INTO Member (Name, PhoneNo, Address) VALUES('" + memberName + "','" + memberPhone + "','" + memberAddress + "')");
    //query.prepare("select * from Member where Name like '%" + memberName + "%'", database);[QSqlQuery te nai select form ta.]
    query.exec();
    qDebug() << "Last error : " << query.lastError().text();
    database.close();
    //on_btnReset_clicked();

}


void AddMember::on_btnReset_clicked()
{
    ui->txtMemberName->clear();
    ui->txtMemberPhone->clear();
    ui->txtMemberAddress->clear();
}


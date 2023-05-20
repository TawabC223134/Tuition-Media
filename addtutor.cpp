#include "addtutor.h"
#include "ui_addtutor.h"

AddTutor::AddTutor(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddTutor)
{
    ui->setupUi(this);
}

AddTutor::~AddTutor()
{
    delete ui;
}

void AddTutor::on_btnSave_clicked()
{
    QString firstName = ui->txtFirstName->text();
    QString middleName = ui->txtMiddleName->text();
    QString lastName = ui->txtLastName->text();
    QString phoneNo = ui->txtPhoneNo->text();
    QString nidNo = ui->txtNIDNo->text();
    QString permenantAddress = ui->txtPermenantAddress->text();
    QString chooseLocation = ui->cmbChooseLocation->currentText();

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
    query.prepare("INSERT INTO Tutor (FirstName, MiddleName, LastName, PhoneNo, NIDNo, PermenantAddress, ChooseLocation) "
                  "VALUES('" + firstName + "','" + middleName + "','" + lastName + "','" + phoneNo + "','" + nidNo + "','" + permenantAddress + "','" + chooseLocation + "')");
    query.exec();
    qDebug() << "last query : " << query.lastQuery();
    qDebug() << "last error : " << query.lastError().text();
    database.close();
    //on_btnReset_clicked();
}


void AddTutor::on_btnReset_clicked()
{
    ui->txtFirstName->clear();
    ui->txtMiddleName->clear();
    ui->txtLastName->clear();
    ui->txtPhoneNo->clear();
    ui->txtNIDNo->clear();
    ui->txtPermenantAddress->clear();
    ui->cmbChooseLocation->clear();

}


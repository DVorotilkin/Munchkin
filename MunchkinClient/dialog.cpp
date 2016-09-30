#include "dialog.h"
#include "ui_dialog.h"


Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_connectButton_clicked()
{
    //Network n;
    client = new ClientNetwork();
    //net = new Network();
    //ClientNetwork client();
    //client.Void();
    //ui->ipAddress->setText( client.objectName());
}

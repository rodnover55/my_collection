#include "fartistsadd.h"
#include "ui_fartistsadd.h"

FArtistsAdd::FArtistsAdd(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::FArtistsAdd)
{
    ui->setupUi(this);
}

FArtistsAdd::~FArtistsAdd()
{
    delete ui;
}

bool FArtistsAdd::get(Artist &value)
{
    this->ui->eName->setText(value.Name());

    if (this->exec() == QDialog::Accepted) {
        value.setName(this->ui->eName->text());
        return true;
    }

    return false;
}

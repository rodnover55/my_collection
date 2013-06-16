#include "falbumadd.h"
#include "ui_falbumadd.h"

FAlbumAdd::FAlbumAdd(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::FAlbumAdd)
{
    ui->setupUi(this);
}

FAlbumAdd::~FAlbumAdd()
{
    delete ui;
}

bool FAlbumAdd::get(Album &album)
{
    this->ui->eTitle->setText(album.Title());
    this->ui->cbYear->setCurrentText(album.Year());
    this->ui->cbLabel->setCurrentText(album.Label());
    this->ui->cbCountry->setCurrentText(album.Country());
    this->ui->cbFormat->setCurrentText(album.Format());

    if (this->exec() == QDialog::Accepted) {
        album.setTitle(this->ui->eTitle->text());
        album.setYear(this->ui->cbYear->currentText());
        album.setLabel(this->ui->cbLabel->currentText());
        album.setCountry(this->ui->cbCountry->currentText());
        album.setFormat(this->ui->cbFormat->currentText());

        return true;
    }

    return false;
}


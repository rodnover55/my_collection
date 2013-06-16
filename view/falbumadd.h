#ifndef FALBUMADD_H
#define FALBUMADD_H

#include <QDialog>

#include "model/album.h"

namespace Ui {
class FAlbumAdd;
}

class FAlbumAdd : public QDialog
{
    Q_OBJECT
    
public:
    explicit FAlbumAdd(QWidget *parent = 0);
    ~FAlbumAdd();

    bool get(Album &album);
private:
    Ui::FAlbumAdd *ui;
};

#endif // FALBUMADD_H

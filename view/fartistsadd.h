#ifndef FARTISTSADD_H
#define FARTISTSADD_H

#include <QDialog>

#include "model/artist.h"

namespace Ui {
class FArtistsAdd;
}

class FArtistsAdd : public QDialog
{
    Q_OBJECT
    
public:
    explicit FArtistsAdd(QWidget *parent = 0);
    ~FArtistsAdd();
    
    bool get(Artist &value);
private:
    Ui::FArtistsAdd *ui;
};

#endif // FARTISTSADD_H

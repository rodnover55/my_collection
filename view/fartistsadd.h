#ifndef FARTISTSADD_H
#define FARTISTSADD_H

#include <QDialog>

namespace Ui {
class FArtistsAdd;
}

class FArtistsAdd : public QDialog
{
    Q_OBJECT
    
public:
    explicit FArtistsAdd(QWidget *parent = 0);
    ~FArtistsAdd();
    
    bool get(QString &value);
private:
    Ui::FArtistsAdd *ui;
};

#endif // FARTISTSADD_H

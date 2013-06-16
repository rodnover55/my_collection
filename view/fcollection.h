#ifndef FCOLLECTION_H
#define FCOLLECTION_H

#include <QMainWindow>
#include <QSqlDatabase>
#include <QSqlTableModel>
#include <QDebug>
#include <QSqlQuery>
#include <QSqlError>

#include "fartistsadd.h"
#include "falbumadd.h"
#include "model/album.h"
#include "model/artist.h"

namespace Ui {
class FCollection;
}

class FCollection : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit FCollection(QWidget *parent = 0);
    ~FCollection();
    
private slots:
    void on_lineEdit_textChanged(const QString &value);

    void on_actionArtist_triggered();

    void on_actionAlbum_triggered();
    void on_lvArtists_clicked(const QModelIndex &index);

    void on_actionArtistEdit_triggered();

    void on_actionArtistDelete_triggered();

private:
    Ui::FCollection *ui;
    QSqlDatabase m_DB;
    QSqlTableModel *m_ArtistsModel;
    QSqlTableModel *m_AlbumsModel;

};

#endif // FCOLLECTION_H

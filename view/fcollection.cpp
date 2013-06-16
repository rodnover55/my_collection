#include "fcollection.h"
#include "ui_fcollection.h"

FCollection::FCollection(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::FCollection),
    m_DB(QSqlDatabase::database("my_collection"))
{
    this->ui->setupUi(this);

    this->m_ArtistsModel = new QSqlTableModel(this, this->m_DB);
    this->m_ArtistsModel->setTable("artists");
    this->m_ArtistsModel->select();
    this->m_ArtistsModel->removeColumn(0);

    this->m_AlbumsModel = new QSqlTableModel(this, this->m_DB);

    this->m_AlbumsModel->setTable("albums");
    this->m_AlbumsModel->removeColumns(0, 2);

    this->m_AlbumsModel->setHeaderData(0, Qt::Horizontal, tr("Title"));
    this->m_AlbumsModel->setHeaderData(1, Qt::Horizontal, tr("Year"));
    this->m_AlbumsModel->setHeaderData(2, Qt::Horizontal, tr("Label"));
    this->m_AlbumsModel->setHeaderData(3, Qt::Horizontal, tr("Country"));
    this->m_AlbumsModel->setHeaderData(4, Qt::Horizontal, tr("Format"));
    this->m_AlbumsModel->select();

    this->m_AlbumsModel->setFilter("albums.id_artist = null");

    this->ui->lvArtists->setModel(this->m_ArtistsModel);
    this->ui->splitter->setSizes(QList<int>() << 150 << 500);
    this->ui->cvAlbums->setModel(this->m_AlbumsModel);
}

FCollection::~FCollection()
{
    delete this->m_ArtistsModel;
    delete this->ui;
}

void FCollection::on_lineEdit_textChanged(const QString &value)
{
    this->m_ArtistsModel->setFilter(QString("artists.name like '%%1%'").arg(value));
}

void FCollection::on_actionArtist_triggered()
{
    FArtistsAdd f;
    QString artistName;
    QString sql =
            " insert into artists(name) "
            " values(:artist_name) ";

    // TODO: Moved to model
    if (f.get(artistName)) {
        QSqlQuery query(this->m_DB);
        query.prepare(sql);
        query.bindValue(":artist_name", artistName);
        query.exec();
        this->m_ArtistsModel->select();
    }
}

void FCollection::on_actionAlbum_triggered()
{
    FAlbumAdd f;
    Album album;
    QString artistName = this->m_ArtistsModel->data(this->ui->lvArtists->currentIndex()).toString();

    QString sql =
            " insert into albums(title, year, label, country, format, id_artist) "
            " values(:title, :year, :label, :country, :format, :id_artist) ";
    album.setIdArtist(this->getIdArtist(artistName));

    if (f.get(album)) {
        QSqlQuery query(this->m_DB);
        query.prepare(sql);
        query.bindValue(":title", album.Title());
        query.bindValue(":year", album.Year());
        query.bindValue(":label", album.Label());
        query.bindValue(":country", album.Country());
        query.bindValue(":format", album.Format());
        query.bindValue(":id_artist", album.IdArtist());
        query.exec();
        this->m_AlbumsModel->select();
    }
}

// TODO: Moved to model
int FCollection::getIdArtist(const QString &artistName)
{
    QString sql =
            " select artists.id_artist "
            " from artists "
            " where artists.name = :artist_name ";

    QSqlQuery query(this->m_DB);
    query.prepare(sql);
    query.bindValue(":artist_name", artistName);
    query.exec();

    if (query.next()) {
        return query.value(0).toInt();
    } else {
        return 0;
    }
}

void FCollection::on_lvArtists_clicked(const QModelIndex &index)
{
    QString artistName = this->m_ArtistsModel->data(index).toString();

    this->m_AlbumsModel->setFilter(QString("albums.id_artist = %1").arg(this->getIdArtist(artistName)));
}

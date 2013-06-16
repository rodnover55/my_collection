#include "artist.h"

Artist::Artist() :
    m_IdArtist(0)
{
}

Artist Artist::byID(QSqlDatabase &db, int id)
{
    return Artist();

}


Artist Artist::byName(QSqlDatabase &db, const QString &name)
{
    Artist artist;
    QString sql =
            " select artists.id_artist "
            " from artists "
            " where artists.name = :artist_name ";

    QSqlQuery query(db);
    query.prepare(sql);
    query.bindValue(":artist_name", QVariant(name));
    query.exec();

    if (query.next()) {
        artist.setIdArtist(query.value(0).toInt());
        artist.setName(name);
    }

    return artist;
}

QString Artist::Name() const
{
    return m_Name;
}

void Artist::setName(const QString &Name)
{
    m_Name = Name;
}

bool Artist::save(QSqlDatabase &db)
{
    QString sql;
    if (this->m_IdArtist != 0) {
        sql =
                " update artists set "
                " name = :artist_name "
                " where id_artist = :id_artist ";
    } else {
        sql =
                " insert into artists(name) "
                " values(:artist_name) ";
    }


    QSqlQuery query(db);
    query.prepare(sql);
    query.bindValue(":artist_name", this->m_Name);

    if (this->m_IdArtist != 0) {
        query.bindValue(":id_artist", this->m_IdArtist);
    }

    return query.exec();
}

bool Artist::remove(QSqlDatabase &db)
{
    if (this->m_IdArtist == 0) {
        return false;
    }
    QString sql =
            " delete from artists "
            " where id_artist = :id_artist ";

    QSqlQuery query(db);
    query.prepare(sql);
    query.bindValue(":id_artist", this->m_IdArtist);
    return query.exec();
}

int Artist::IdArtist() const
{
    return m_IdArtist;
}

void Artist::setIdArtist(int IdArtist)
{
    m_IdArtist = IdArtist;
}

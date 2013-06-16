#include "album.h"

Album::Album() :
    m_IdAlbum(0)
{
}

int Album::IdArtist() const
{
    return m_IdArtist;
}

void Album::setIdArtist(int IdArtist)
{
    m_IdArtist = IdArtist;
}

bool Album::save(QSqlDatabase &db)
{
    if (this->m_IdAlbum != 0) {
        return false;
    }

    QString sql =
            " insert into albums(title, year, label, country, format, id_artist) "
            " values(:title, :year, :label, :country, :format, :id_artist) ";
    QSqlQuery query(db);

    query.prepare(sql);
    query.bindValue(":title", this->Title());
    query.bindValue(":year", this->Year());
    query.bindValue(":label", this->Label());
    query.bindValue(":country", this->Country());
    query.bindValue(":format", this->Format());
    query.bindValue(":id_artist", this->IdArtist());
    return query.exec();
}

QString Album::Format() const
{
    return m_Format;
}

void Album::setFormat(const QString &Format)
{
    m_Format = Format;
}

QString Album::Country() const
{
    return m_Country;
}

void Album::setCountry(const QString &Country)
{
    m_Country = Country;
}

QString Album::Label() const
{
    return m_Label;
}

void Album::setLabel(const QString &Label)
{
    m_Label = Label;
}

QString Album::Year() const
{
    return m_Year;
}

void Album::setYear(const QString &Year)
{
    m_Year = Year;
}

QString Album::Title() const
{
    return m_Title;
}

void Album::setTitle(const QString &Title)
{
    m_Title = Title;
}

int Album::IdAlbum() const
{
    return m_IdAlbum;
}

void Album::setIdAlbum(int IdAlbum)
{
    m_IdAlbum = IdAlbum;
}

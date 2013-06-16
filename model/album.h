#ifndef ALBUM_H
#define ALBUM_H

#include <QString>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QVariant>

class Album
{
public:
    Album();

    QString Title() const;
    void setTitle(const QString &Title);

    QString Year() const;
    void setYear(const QString &Year);

    QString Label() const;
    void setLabel(const QString &Label);

    QString Country() const;
    void setCountry(const QString &Country);

    QString Format() const;
    void setFormat(const QString &Format);

    int IdArtist() const;
    void setIdArtist(int IdArtist);

    bool save(QSqlDatabase &db);
    int IdAlbum() const;
    void setIdAlbum(int IdAlbum);

private:
    int m_IdAlbum;
    QString m_Title;
    QString m_Year;
    QString m_Label;
    QString m_Country;
    QString m_Format;
    int m_IdArtist;
};

#endif // ALBUM_H

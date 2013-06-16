#ifndef ALBUM_H
#define ALBUM_H

#include <QString>
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

private:
    QString m_Title;
    QString m_Year;
    QString m_Label;
    QString m_Country;
    QString m_Format;
    int m_IdArtist;
};

#endif // ALBUM_H

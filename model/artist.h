#ifndef ARTIST_H
#define ARTIST_H

#include <QString>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QVariant>
#include <QSqlError>
#include <QDebug>

class Artist
{
public:
    Artist();

    static Artist byID(QSqlDatabase &db, int id);
    static Artist byName(QSqlDatabase &db, const QString &name);

    int IdArtist() const;
    void setIdArtist(int IdArtist);

    QString Name() const;
    void setName(const QString &Name);


    bool save(QSqlDatabase &db);
    bool remove(QSqlDatabase &db);

private:
    int m_IdArtist;
    QString m_Name;

};

#endif // ARTIST_H

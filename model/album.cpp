#include "album.h"

Album::Album()
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

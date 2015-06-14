#ifndef _FilmGenre_H
#define _FilmGenre_H

#include<iostream>

class FilmGenre{

  private:
    int _IDFilm = 0;
    int _IDGenre = 0;

  public:
    FilmGenre() =default;
    FilmGenre(int,int); 
    FilmGenre(const std::string&);

    FilmGenre(const FilmGenre&);
    ~FilmGenre()=default;

    FilmGenre& operator = (const FilmGenre&);

    const int& IDFilm () const;
    const int& IDGenre() const;
    int& IDFilm();
    int& IDGenre();

    bool operator == (const FilmGenre&) const;
    bool operator != (const FilmGenre&) const;
    bool operator <  (const FilmGenre&) const;
    bool operator >  (const FilmGenre&) const;
    bool operator <= (const FilmGenre&) const;
    bool operator >= (const FilmGenre&) const;

    bool byIDFilm (const FilmGenre&) const;
    bool byIDGenre (const FilmGenre&) const;

    friend std::ostream& operator << (std::ostream&,const FilmGenre&);
};

#endif

    












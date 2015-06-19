#ifndef _FILMACTOR_H
#define _FILMACTOR_H

#include<iostream>

class FilmActor{

  private:
    int _IDFilm = 0;
    int _IDActor = 0;

  public:
    FilmActor() =default;
    FilmActor(int,int); 
    FilmActor(const std::string&);

    FilmActor(const FilmActor&);
    ~FilmActor()=default;

    FilmActor& operator = (const FilmActor&);

    const int& IDFilm () const;
    const int& IDActor() const;
    int ID() const;
    int& IDFilm();
    int& IDActor();

    bool operator == (const FilmActor&) const;
    bool operator != (const FilmActor&) const;
    bool operator <  (const FilmActor&) const;
    bool operator >  (const FilmActor&) const;
    bool operator <= (const FilmActor&) const;
    bool operator >= (const FilmActor&) const;

    bool byIDFilm (const FilmActor&) const;
    bool byIDActor (const FilmActor&) const;

    friend std::ostream& operator << (std::ostream&,const FilmActor&);
};

#endif

    












#ifndef _FILM_H
#define _FILM_H

#include <iostream>

class Film {
  
  private:
    int _ID = 0;
    int _release_year;
    std::string _title;

  public:
    Film()=default;
    Film(int,const std::string&);
    
    Film(const Film&);
    Film(Film&&);
    ~Film()=default;
    
    Film& operator = (const Film&) ;
    Film& operator = (Film&&) ;

    void setID (int);
    void setReleaseYear (int);
    void setTitle (const std::string&);
    const int& getID () const;
    const int& getReleaseYear () const;
    const std::string& getTitle () const;

    bool operator ==(const Film&) const ;
    bool operator !=(const Film&) const ;
    bool operator < (const Film&) const ;
    bool operator > (const Film&) const ;
    bool operator <=(const Film&) const ;
    bool operator >=(const Film&) const ;

    bool byReleaseYear(const Film&) const;
    bool byTitle(const Film&) const;

    friend std::ostream& operator << (std::ostream&,const Film&);
};

#endif 

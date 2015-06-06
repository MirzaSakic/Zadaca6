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
    Film(const std::string&);
    
    Film(const Film&);
    ~Film()=default;
    
    Film& operator = (const Film&) ;

    int& ID ();
    int& release_year ();
    std::string& title ();
    const int& ID () const;
    const int& release_year () const;
    const std::string& title () const;

    bool operator ==(const Film&) const ;
    bool operator !=(const Film&) const ;
    bool operator < (const Film&) const ;
    bool operator > (const Film&) const ;
    bool operator <=(const Film&) const ;
    bool operator >=(const Film&) const ;

    bool byReleaseYear(const Film&) const;
    bool byTitle(const Film&) const;

    friend std::ostream& operator << (std::ostream&,const Film&);
    friend std::istream& operator >> (std::istream&,Film&);
};

#endif 

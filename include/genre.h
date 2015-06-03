#ifndef _GENRE_H
#define _GENRE_H

#include <iostream>

class Genre {
  
  private:
    int _ID = 0;
    std::string _genre_name;

  public:
    Genre() = default;
    Genre(const std::string&);

    Genre(const Genre&);
    Genre(Genre&&);

    Genre& operator = (const Genre&);
    Genre& operator = (Genre&&);

    void setID(int);
    void setGenreName(const std::string&);
    const int& getID() const;
    const std::string& getGenreName() const;

    bool operator == (const Genre&) const;
    bool operator != (const Genre&) const;
    bool operator < (const Genre&) const;
    bool operator > (const Genre&) const;
    bool operator <= (const Genre&) const;
    bool operator >= (const Genre&) const;

    friend std::ostream& operator << (std::ostream&,const Genre&);
};

#endif 







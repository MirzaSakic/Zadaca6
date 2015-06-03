#include <iostream>
#include "../include/film.h"

Film::Film(int year,const std::string& title) : _release_year(year), _title(title) {}

Film::Film(const Film& other) : _release_year(other._release_year), _title(other._title) {};
Film::Film(Film&& other) : _release_year(other._release_year), _title(other._title) {};

Film& Film::operator = (const Film& other) 
{
  _release_year=other._release_year;
  _title=other._title;
  return *this;
};

Film& Film::operator = (Film&& other)
{
  _release_year=other._release_year;
  _title=other._title;
  return *this;
}

void Film::setID(int ID) {_ID=ID;}
void Film::setReleaseYear(int year) {_release_year=year;}
void Film::setTitle(const std::string& title) {_title=title;}
const int& Film::getID() const {return _ID;}
const int& Film::getReleaseYear() const {return _release_year;}
const std::string& Film::getTitle() const {return _title;}

bool Film::operator== (const Film& other) const {return (_title == other._title);}
bool Film::operator!= (const Film& other) const {return (_title != other._title);}
bool Film::operator < (const Film& other) const {return (_title <  other._title);}
bool Film::operator > (const Film& other) const {return (_title >  other._title);}
bool Film::operator<= (const Film& other) const {return (_title <= other._title);}
bool Film::operator>= (const Film& other) const {return (_title != other._title);}

bool Film::byReleaseYear(const Film& other) const {return (_release_year < other._release_year);}
bool Film::byTitle(const Film& other) const  {return (_title < other._title);}

std::ostream& operator << (std::ostream& out,const Film& film)
{
  out<<film._title<<", "<<film._release_year<<std::endl;
  return out;
}



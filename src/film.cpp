#include <iostream>
#include "film.h"

Film::Film(int ID,int year,const std::string& title) : _ID(ID), _release_year(year), _title(title) {}
Film::Film(int year,const std::string& title) :  _release_year(year), _title(title) {}
Film::Film(int ID) : _ID(ID) {};
Film::Film(const std::string& film) 
{
  size_t pos = 0;
  std::string copy = film;
  std::string id,rel_year,title;
  
  pos=copy.find(',');
  id =copy.substr(0,pos);
  _ID=stoi(id);
  copy.erase(0,pos+1);

  rel_year=copy.substr(0,',');
  int year = stoi(rel_year);
  _release_year=year;

  pos=copy.find(',') + 1;
  title = copy.substr(pos,std::string::npos);
  _title = title;
}

Film::Film(const Film& other) : _release_year(other._release_year), _title(other._title) {};

Film& Film::operator = (const Film& other) 
{
  _release_year=other._release_year;
  _title=other._title;
  return *this;
};


int& Film::ID() {return _ID;}
int& Film::release_year() {return _release_year;}
std::string& Film::title() {return _title;}
const int& Film::ID() const {return _ID;}
const int& Film::release_year() const {return _release_year;}
const std::string& Film::title() const {return _title;}

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
  out<<film._ID<<","<<film._title<<","<<film._release_year<<std::endl;
  return out;
}

std::istream& operator >> (std::istream& in,Film& film)
{
  std::cout<<"Release year: ";
  in>>film._release_year;
  std::cout<<"Film title: ";
  in>>film._title;
  return in;
}

#include <iostream>
#include "film.h"

Film::Film(int ID,int year,const std::string& title) : _ID(ID), _release_year(year), _title(title) {}
Film::Film(int year,const std::string& title) :  _release_year(year), _title(title) {}
Film::Film(int ID) : _ID(ID) {};
Film::Film(const std::string& film) 
{
  char separator = ',';
  if (film.find(',') == std::string::npos)
      separator='/';
  int pos = 0;
  std::string copy = film;
  std::string id,rel_year,title;
  
  pos=copy.find(separator);
  id =copy.substr(0,pos);
  _ID=stoi(id);
  copy.erase(0,pos+1);

  rel_year=copy.substr(0,separator);
  int year = stoi(rel_year);
  _release_year=year;

  pos=copy.find(separator) + 1;
  title = copy.substr(pos,std::string::npos);
  _title = title;
}


int& Film::ID() {return _ID;}
int& Film::release_year() {return _release_year;}
std::string& Film::title() {return _title;}
const int& Film::ID() const {return _ID;}
const int& Film::release_year() const {return _release_year;}
const std::string& Film::title() const {return _title;}

bool Film::operator== (const Film& other) const {return (_ID == other._ID);}
bool Film::operator!= (const Film& other) const {return (_ID != other._ID);}
bool Film::operator < (const Film& other) const {return (_ID <  other._ID);}
bool Film::operator > (const Film& other) const {return (_ID >  other._ID);}
bool Film::operator<= (const Film& other) const {return (_ID <= other._ID);}
bool Film::operator>= (const Film& other) const {return (_ID != other._ID);}

bool Film::byReleaseYear(const Film& other) const {return (_release_year < other._release_year);}
bool Film::byTitle(const Film& other) const  {return (_title < other._title);}

std::ostream& operator << (std::ostream& out,const Film& film)
{
  if(out==std::cout)
  {
  out<<film._ID<<" "<<film._title<<" "<<film._release_year;
  return out;
  }
  out<<film._ID<<","<<film._title<<","<<film._release_year;
  return out;
}


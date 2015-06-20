#include "genre.h"
#include <iostream>

Genre::Genre(int ID,const std::string& genName) : _ID(ID), _genre_name(genName) {}
Genre::Genre(int ID) : _ID(ID) {}
Genre::Genre(const std::string& gen) 
{
  size_t pos;
  std::string id,genname;


  if(gen.find(',') == std::string::npos)
  {
    _genre_name=gen;
  }
  else
  {
   id=gen.substr(0,',');
  _ID=stoi(id);
  pos=gen.find(',') + 1;

  genname=gen.substr(pos,std::string::npos);
  _genre_name=genname;
  }
}

Genre::Genre(const Genre& other) : _ID(other._ID), _genre_name(other._genre_name) {}

Genre& Genre::operator = (const Genre& other) { _genre_name = other._genre_name; return *this;}


int& Genre::ID () {return _ID ;}
std::string& Genre::genre_name () { return _genre_name;}
const int& Genre::ID () const {return _ID;}
const std::string& Genre::genre_name () const {return _genre_name;}


bool Genre::operator == (const Genre& other) const {return (_genre_name == other._genre_name);}
bool Genre::operator != (const Genre& other) const {return (_genre_name != other._genre_name);}
bool Genre::operator <  (const Genre& other) const {return (_genre_name <  other._genre_name);}
bool Genre::operator >  (const Genre& other) const {return (_genre_name >  other._genre_name);}
bool Genre::operator <= (const Genre& other) const {return (_genre_name <= other._genre_name);}
bool Genre::operator >= (const Genre& other) const {return (_genre_name >= other._genre_name);}


std::ostream& operator << (std::ostream& out,const Genre& genre)
{
  if (out == cout)
  {
    out<<genre._ID<<" "<<genre._genre_name;
    return out;
  }
  out<<genre._ID<<","<<genre._genre_name;
  return out;
}

std::istream& operator >> (std::istream& in,Genre& genre)
{
  std::cout<<"Name of the genre: ";
  in>>genre._genre_name;
  return in ;
}


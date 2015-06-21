#include "genre.h"
#include <iostream>

Genre::Genre(int ID,const std::string& genName) : _ID(ID), _genre_name(genName) {}
Genre::Genre(int ID) : _ID(ID) {}
Genre::Genre(const std::string& gen) 
{
  char separator = ',';
  if (gen.find(',') == std::string::npos)
    separator = '/';

  if(gen.find(',')==std::string::npos && gen.find('/')==std::string::npos)
  {
    _genre_name=gen;
    return;
  }
  else
  {
    int pos;
    std::string id,genname; 
    id=gen.substr(0,separator);
    _ID=stoi(id);
    pos=gen.find(separator) + 1;

    genname=gen.substr(pos,std::string::npos);
    _genre_name=genname;
  }
}

int& Genre::ID () {return _ID ;}
std::string& Genre::genre_name () { return _genre_name;}
const int& Genre::ID () const {return _ID;}
const std::string& Genre::genre_name () const {return _genre_name;}


bool Genre::operator == (const Genre& other) const {return (_ID == other._ID);}
bool Genre::operator != (const Genre& other) const {return (_ID != other._ID);}
bool Genre::operator <  (const Genre& other) const {return (_ID <  other._ID);}
bool Genre::operator >  (const Genre& other) const {return (_ID >  other._ID);}
bool Genre::operator <= (const Genre& other) const {return (_ID <= other._ID);}
bool Genre::operator >= (const Genre& other) const {return (_ID >= other._ID);}


std::ostream& operator << (std::ostream& out,const Genre& genre)
{
  if (out == std::cout)
  {
    out<<genre._ID<<" "<<genre._genre_name;
    return out;
  }
  out<<genre._ID<<","<<genre._genre_name;
  return out;
}


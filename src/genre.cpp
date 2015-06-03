#include "../include/genre.h"
#include <iostream>

Genre::Genre(const std::string& genName) : _genre_name(genName) {}

Genre::Genre(const Genre& other) : _genre_name(other._genre_name) {}
Genre::Genre(Genre&& other) : _genre_name(other._genre_name) {}

Genre& Genre::operator = (const Genre& other) { _genre_name = other._genre_name; return *this;}
Genre& Genre::operator = (Genre&& other) { _genre_name = other._genre_name; return *this;}


void Genre::setID(int ID) {_ID = ID ;}
void Genre::setGenreName(const std::string& genName) { _genre_name = genName;}
const int& Genre::getID() const {return _ID;}
const std::string& Genre::getGenreName() const {return _genre_name;}


bool Genre::operator == (const Genre& other) const {return (_genre_name == other._genre_name);}
bool Genre::operator != (const Genre& other) const {return (_genre_name != other._genre_name);}
bool Genre::operator <  (const Genre& other) const {return (_genre_name <  other._genre_name);}
bool Genre::operator >  (const Genre& other) const {return (_genre_name >  other._genre_name);}
bool Genre::operator <= (const Genre& other) const {return (_genre_name <= other._genre_name);}
bool Genre::operator >= (const Genre& other) const {return (_genre_name >= other._genre_name);}


std::ostream& operator << (std::ostream& out,const Genre& genre)
{
  out<<genre._genre_name;
  return out;
}


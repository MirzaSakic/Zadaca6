#include <iostream>
#include "../include/filmgenre.h"

using namespace std;


FilmGenre::FilmGenre(int IDFilm,int IDGenre) : _IDFilm(IDFilm), _IDGenre(IDGenre) {};

FilmGenre::FilmGenre(const string& filmgenre) 
{
  size_t pos=0;
  string idfilm,idgenre;
  idfilm = filmgenre.substr(0,',');
  _IDFilm = stoi(idfilm);

  pos = filmgenre.find(',') + 1;
  idgenre = filmgenre.substr(pos,string::npos);
  _IDGenre = stoi(idgenre);
}

FilmGenre::FilmGenre(const FilmGenre& other) : _IDFilm(other._IDFilm), _IDGenre(other._IDGenre) {};

FilmGenre& FilmGenre::operator = (const FilmGenre& other) 
{
  _IDFilm=other._IDFilm;
  _IDGenre=other._IDGenre;
  return *this;
}

const int& FilmGenre::IDFilm() const {return _IDFilm;}
const int& FilmGenre::IDGenre() const {return _IDGenre;}
int& FilmGenre:: IDFilm() {return _IDFilm;}
int& FilmGenre::IDGenre() {return _IDGenre;}

bool FilmGenre::operator == (const FilmGenre& other) const {return _IDFilm == other._IDFilm;}
bool FilmGenre::operator != (const FilmGenre& other) const {return _IDFilm != other._IDFilm;}
bool FilmGenre::operator <  (const FilmGenre& other) const {return _IDFilm <  other._IDFilm;}
bool FilmGenre::operator >  (const FilmGenre& other) const {return _IDFilm >  other._IDFilm;}
bool FilmGenre::operator <= (const FilmGenre& other) const {return _IDFilm <= other._IDFilm;}
bool FilmGenre::operator >= (const FilmGenre& other) const {return _IDFilm >= other._IDFilm;}

bool FilmGenre::byIDFilm  (const FilmGenre& other) const {return _IDFilm < other._IDFilm;}
bool FilmGenre::byIDGenre (const FilmGenre& other) const {return _IDGenre <other._IDGenre;}

ostream& operator << (ostream& out,const FilmGenre& filmgen)
{
  out<<filmgen._IDFilm<<","<<filmgen._IDGenre;
  return out;
}




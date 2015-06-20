#include <iostream>
#include "filmactor.h"

using namespace std;


FilmActor::FilmActor(int IDFilm,int IDActor) : _IDFilm(IDFilm), _IDActor(IDActor) {};

FilmActor::FilmActor(const string& filmactor) 
{
  size_t pos=0;
  string idfilm,idactor;
  idfilm = filmactor.substr(0,',');
  _IDFilm = stoi(idfilm);

  pos = filmactor.find(',') + 1;
  idactor = filmactor.substr(pos,string::npos);
  _IDActor = stoi(idactor);
}

FilmActor::FilmActor(const FilmActor& other) : _IDFilm(other._IDFilm), _IDActor(other._IDActor) {};

FilmActor& FilmActor::operator = (const FilmActor& other) 
{
  _IDFilm=other._IDFilm;
  _IDActor=other._IDActor;
  return *this;
}

const int& FilmActor::IDFilm() const {return _IDFilm;}
const int& FilmActor::IDActor() const {return _IDActor;}
int& FilmActor::IDFilm() {return _IDFilm;}
int& FilmActor::IDActor() {return _IDActor;}
const int& FilmActor::ID() const { return _IDFilm; }
int& FilmActor::ID() { return _IDFilm; }

bool FilmActor::operator == (const FilmActor& other) const {return _IDFilm == other._IDFilm;}
bool FilmActor::operator != (const FilmActor& other) const {return _IDFilm != other._IDFilm;}
bool FilmActor::operator <  (const FilmActor& other) const {return _IDFilm <  other._IDFilm;}
bool FilmActor::operator >  (const FilmActor& other) const {return _IDFilm >  other._IDFilm;}
bool FilmActor::operator <= (const FilmActor& other) const {return _IDFilm <= other._IDFilm;}
bool FilmActor::operator >= (const FilmActor& other) const {return _IDFilm >= other._IDFilm;}

bool FilmActor::byIDFilm  (const FilmActor& other) const {return _IDFilm < other._IDFilm;}
bool FilmActor::byIDActor (const FilmActor& other) const {return _IDActor <other._IDActor;}

ostream& operator << (ostream& out,const FilmActor& filmact)
{
  if(out==std::cout)
  {
    out<<filmact._IDFilm<<" "<<filmact._IDActor;
    return out;
  }
  out<<filmact._IDFilm<<","<<filmact._IDActor;
  return out;
}




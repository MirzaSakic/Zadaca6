#include <iostream>
#include "../include/film_borrowed.h"

FilmBorrowed::FilmBorrowed(int IDUser,int IDFilm,const Date& date_of_borrowing):
				_IDUser(IDUser), _IDFilm(IDFilm), _date_of_borrowing(date_of_borrowing) {}

FilmBorrowed::FilmBorrowed(int IDUser,int IDFilm,const Date& date_of_borrowing,const Date& date_of_returning):
				_IDUser(IDUser), _IDFilm(IDFilm), _date_of_borrowing(date_of_borrowing), _date_of_returning(date_of_returning) {}
				
FilmBorrowed::FilmBorrowed(std::string& filmBorrowed) {
	int i=0;
	int temporary=0;
	
	while(filmBorrowed[i]!='\0'){
		if(filmBorrowed[i]==',' && temporary==0){
			int idUser=stoi(filmBorrowed.substr(0,i));
			IDUser()=idUser;
			filmBorrowed=filmBorrowed.substr(i+1);
			i=-1;
			++temporary;
			}
		if(filmBorrowed[i]==',' && temporary==1){
			int idFilm=stoi(filmBorrowed.substr(0,i));
			IDFilm()=idFilm;
			filmBorrowed=filmBorrowed.substr(i+1);
			i=-1;
			++temporary;
			}
		if(filmBorrowed[i]==',' && temporary==2){
			int day=stoi(filmBorrowed.substr(0,i));
			_date_of_borrowing.Day()=day;
			filmBorrowed=filmBorrowed.substr(i+1);
			i=-1;
			++temporary;
			}
		if(filmBorrowed[i]==',' && temporary==3){
			int month=stoi(filmBorrowed.substr(0,i));
			_date_of_borrowing.Month()=month;
			filmBorrowed=filmBorrowed.substr(i+1);
			i=-1;
			++temporary;
			}
	++i;
		}
	int year=stoi(filmBorrowed);
	_date_of_borrowing.Year()=year;
	}
            
const int& FilmBorrowed::IDUser() const {return _IDUser;}
const int& FilmBorrowed::IDFilm() const {return _IDFilm;}
const Date& FilmBorrowed::DateOfBorrowing() const {return _date_of_borrowing;}	
const Date& FilmBorrowed::DateOfReturning() const {return _date_of_returning;}

void FilmBorrowed::setFilmBorrowed(int IDUser,int IDFilm,const Date& dateOfBorrowing,const Date& dateOfReturning)
{
		_IDUser=IDUser;
		_IDFilm=IDFilm;
		_date_of_borrowing=dateOfBorrowing;
		_date_of_returning=dateOfReturning;
}

int& FilmBorrowed::IDUser() {return _IDUser;}
int& FilmBorrowed::IDFilm() {return _IDFilm;}
Date& FilmBorrowed::DateOfBorrowing() {return _date_of_borrowing;}
Date& FilmBorrowed::DateOfReturning() {return _date_of_returning;}

bool FilmBorrowed::operator<(const FilmBorrowed& other)  const {return _IDUser <  other._IDUser;}
bool FilmBorrowed::operator<=(const FilmBorrowed& other) const {return _IDUser <= other._IDUser;}
bool FilmBorrowed::operator>(const FilmBorrowed& other)  const {return _IDUser >  other._IDUser;}
bool FilmBorrowed::operator>=(const FilmBorrowed& other) const {return _IDUser >= other._IDUser;}
bool FilmBorrowed::operator==(const FilmBorrowed& other) const {return _IDUser == other._IDUser;}
bool FilmBorrowed::operator!=(const FilmBorrowed& other) const {return _IDUser != other._IDUser;}

bool FilmBorrowed::equal(const FilmBorrowed& other)              const {return _IDFilm == other._IDFilm;}
bool FilmBorrowed::lessThan(const FilmBorrowed& other)           const {return _IDFilm <  other._IDFilm;}
bool FilmBorrowed::greaterThan(const FilmBorrowed& other)        const {return _IDFilm >  other._IDFilm;}
bool FilmBorrowed::notEqual(const FilmBorrowed& other)           const {return _IDFilm != other._IDFilm;}
bool FilmBorrowed::greaterOrEqualThan(const FilmBorrowed& other) const {return _IDFilm >= other._IDFilm;}
bool FilmBorrowed::lessOrEqualThan(const FilmBorrowed& other)    const {return _IDFilm <= other._IDFilm;}

std::ostream& operator<<(std::ostream& out,const FilmBorrowed& filmBorrowed)
{
	if(out==std::cout){
		out<<"ID of user: "<<filmBorrowed._IDUser<<"\nID of film: "<<filmBorrowed._IDFilm;
		out<<"\nDate of borrowing: "<<filmBorrowed._date_of_borrowing<<std::endl;
		out<<"Date of returning: "<<filmBorrowed._date_of_returning<<std::endl;
	}
	else
		out<<filmBorrowed._IDUser<<","<<filmBorrowed._IDFilm<<","<<filmBorrowed._date_of_borrowing<<","<<filmBorrowed._date_of_returning;
	return out;	
}

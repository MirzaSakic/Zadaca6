#ifndef _FILM_BORROWED_H
#define _FILM_BORROWED_H
#include <string>
#include <iostream>
#include "date.h"

class FilmBorrowed{
	private:
		int _IDUser=0;
		int _IDFilm=0;
		Date _date_of_borrowing;
		Date _date_of_returning;
		friend std::ostream& operator<<(std::ostream& out,const FilmBorrowed& filmBorrowed);
	
	public:
		FilmBorrowed()=default;
		FilmBorrowed(int IDUser,int IDFilm,const Date& date_of_borrowing);
		FilmBorrowed(int IDUser,int IDFilm,const Date& date_of_borrowing,const Date& date_of_returning);
		FilmBorrowed(std::string& filmBorrowed);
				
		const int& IDUser() const;
		const int& IDFilm() const;
		const Date& DateOfBorrowing() const;
		const Date& DateOfReturning() const;
		
		void setFilmBorrowed(int IDUser,int IDFilm,const Date& dateOfBorrowing,const Date& dateOfReturning);
		int& IDUser();
		int& IDFilm();
		Date& DateOfBorrowing();	
		Date& DateOfReturning();
		
		bool operator<(const FilmBorrowed& other) const;
		bool operator<=(const FilmBorrowed& other) const;
		bool operator>(const FilmBorrowed& other) const;
		bool operator>=(const FilmBorrowed& other) const;
		bool operator==(const FilmBorrowed& other) const;
		bool operator!=(const FilmBorrowed& other) const;
		
		bool equal(const FilmBorrowed& other) const;
		bool lessThan(const FilmBorrowed& other) const;
		bool greaterThan(const FilmBorrowed& other) const;
		bool notEqual(const FilmBorrowed& other) const;
		bool greaterOrEqualThan(const FilmBorrowed& other) const;
		bool lessOrEqualThan(const FilmBorrowed& other) const;
	};

#endif

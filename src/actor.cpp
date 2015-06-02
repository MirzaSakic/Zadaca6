#include "../include/actor.h"


Actor::Actor(std::string firstName,std::string lastName,std::string Birthdate,std::string Birthplace){
	_FirstName=firstName;
	_LastName=lastName;
	_BirthDate=Birthdate;
	_BirthPlace=Birthplace;
	}
	
Actor::Actor(std::string firstName,std::string lastName){
	_FirstName=firstName;
	_LastName=lastName;
	
	}
	
int Actor::getID() const { return _ID; }
std::string Actor::getFirstName() const { return _FirstName;}
std::string Actor::getLastName() const { return _LastName;}
std::string Actor::getBirthDate() const { return _BirthDate;}
std::string Actor::getBirthPlace() const { return _BirthPlace;}

void Actor::setID(int ID) {
	_ID=ID;
	}
void Actor::setFirstName(std::string fName){
	_FirstName=fName;
	}
void Actor::setLastName(std::string lName){
	_LastName=lName;
	}
void Actor::setBirthDate(std::string Bdate){
	_BirthDate=Bdate;
	}
void Actor::setBirthPlace(std::string Bplace){
	_BirthPlace=Bplace;
	}

void Actor::setActor(std::string firstName,std::string lastName,std::string Birthdate,std::string Birthplace){
	_FirstName=firstName;
	_LastName=lastName;
	_BirthDate=Birthdate;
	_BirthPlace=Birthplace;

}
void Actor::setActor(std::string firstName,std::string lastName){
	_FirstName=firstName;
	_LastName=lastName;
}

bool Actor::operator<(const Actor& other) const {
	return _ID<other._ID;
	}
bool Actor::operator<=(const Actor& other)const{
	return _ID<=other._ID;
	}
bool Actor::operator>(const Actor& other)const {
	return _ID>other._ID;
	}
bool Actor::operator>=(const Actor& other)const{
	return _ID>=other._ID;
	}
bool Actor::operator==(const Actor& other)const{
	return _ID==other._ID;
	}
bool Actor::operator!=(const Actor& other) const{
	return _ID!=other._ID;
	}

std::ostream& operator<<(std::ostream& out,const Actor& actor) {
	out<<actor._FirstName<<" "<<actor._LastName<<" "<<actor._BirthDate<<" "<<actor._BirthPlace<<std::endl;
	return out;
	}





















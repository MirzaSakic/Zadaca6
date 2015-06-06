#include "../include/actor.h"

Actor::Actor(const int& ID,const std::string& firstName,const std::string& lastName,const std::string& Birthdate,const std::string& Birthplace){
	_ID=ID;	
	_FirstName=firstName;
	_LastName=lastName;
	_BirthDate=Birthdate;
	_BirthPlace=Birthplace;
	}
Actor::Actor(const std::string& firstName,const std::string& lastName,const std::string& Birthdate,const std::string& Birthplace){
	_FirstName=firstName;
	_LastName=lastName;
	_BirthDate=Birthdate;
	_BirthPlace=Birthplace;
	}
	
Actor::Actor(const std::string& firstName,const std::string& lastName){
	_FirstName=firstName;
	_LastName=lastName;
	
	}
Actor::Actor(std::string& actor){
		int i=0;
	
	int temporary=0;
	
	while(actor[i]!='\0'){
		if(actor[i]==',' && temporary==0){
			int ID=stoi(actor.substr(0,i));
			setID()=ID;
			actor=actor.substr(i+1);
			i=-1;
			++temporary;
			}
		if(actor[i]==',' && temporary==1){
			std::string name=actor.substr(0,i);
			setFirstName()=name;
			actor=actor.substr(i+1);
			i=-1;
			++temporary;
			}
		if(actor[i]==',' && temporary==2){
			std::string surname=actor.substr(0,i);
			setLastName()=surname;
			actor=actor.substr(i+1);
			i=-1;
			++temporary;
			}
		if(actor[i]==',' && temporary==3){
			std::string birthDate=actor.substr(0,i);
			setBirthDate()=birthDate;
			actor=actor.substr(i+1);
			i=-1;
			++temporary;
			}
	++i;
		}
	setBirthPlace()=actor;
	
	}
	
	
	
const int& Actor::getID() const { return _ID; }
const std::string& Actor::getFirstName() const { return _FirstName;}
const std::string& Actor::getLastName() const { return _LastName;}
const std::string& Actor::getBirthDate() const { return _BirthDate;}
const std::string& Actor::getBirthPlace() const { return _BirthPlace;}

int& Actor::setID() { return _ID;}
std::string& Actor::setFirstName(){ return _FirstName; }
std::string& Actor::setLastName(){ return _LastName; }
std::string& Actor::setBirthDate(){ return _BirthDate; }
std::string& Actor::setBirthPlace(){ return _BirthPlace;}

void Actor::setID(int ID) {
	_ID=ID;
	}
void Actor::setFirstName(const std::string& fName){
	_FirstName=fName;
	}
void Actor::setLastName(const std::string& lName){
	_LastName=lName;
	}
void Actor::setBirthDate(const std::string& Bdate){
	_BirthDate=Bdate;
	}
void Actor::setBirthPlace(const std::string& Bplace){
	_BirthPlace=Bplace;
	}

void Actor::setActor(const std::string& firstName,const std::string& lastName,const std::string& Birthdate,const std::string& Birthplace){
	_FirstName=firstName;
	_LastName=lastName;
	_BirthDate=Birthdate;
	_BirthPlace=Birthplace;

}
void Actor::setActor(const std::string& firstName,const std::string& lastName){
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

std::ostream& operator<<(std::ostream& out,Actor const& actor) {
	if(out==std::cout)
	out<<"First Name: "<<actor._FirstName<<"Last Name: "<<actor._LastName<<"Birth date: "<<actor._BirthDate<<"Birth place: "<<actor._BirthPlace<<std::endl;
	else {
	out<<actor._FirstName<<","<<actor._LastName<<","<<actor._BirthDate<<","<<actor._BirthPlace; }
	return out;
	}





















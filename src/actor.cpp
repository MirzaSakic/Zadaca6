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
			ID()=stoi(actor.substr(0,i));
			actor=actor.substr(i+1);
			i=-1;
			++temporary;
			}
		if(actor[i]==',' && temporary==1){
			FirstName()=actor.substr(0,i);
			actor=actor.substr(i+1);
			i=-1;
			++temporary;
			}
		if(actor[i]==',' && temporary==2){
			LastName()=actor.substr(0,i);
			actor=actor.substr(i+1);
			i=-1;
			++temporary;
			}
		if(actor[i]==',' && temporary==3){
			BirthDate()=actor.substr(0,i);
			actor=actor.substr(i+1);
			i=-1;
			++temporary;
			}
	++i;
		}
	BirthPlace()=actor;
	
	}
	
	
	
const int& Actor::ID() const { return _ID; }
const std::string& Actor::FirstName() const { return _FirstName;}
const std::string& Actor::LastName() const { return _LastName;}
const std::string& Actor::BirthDate() const { return _BirthDate;}
const std::string& Actor::BirthPlace() const { return _BirthPlace;}

int& Actor::ID() { return _ID;}
std::string& Actor::FirstName(){ return _FirstName; }
std::string& Actor::LastName(){ return _LastName; }
std::string& Actor::BirthDate(){ return _BirthDate; }
std::string& Actor::BirthPlace(){ return _BirthPlace;}


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





















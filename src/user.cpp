#include <iostream>
#include "../include/user.h"

User::User(int ID,const std::string& first_name,const std::string& last_name, 
			const std::string& phone,const std::string& adress): 
            _ID(ID),_first_name(first_name),_last_name(last_name),_phone(phone), _adress(adress) {}

User::User(int ID): _ID(ID) {}

User::User(const std::string& first_name,const std::string& last_name, 
			const std::string& phone,const std::string& adress): 
            _first_name(first_name),_last_name(last_name),_phone(phone), _adress(adress) {}
            
const int& User::getID() const {return _ID;}            
const std::string& User::getFirstName() const {return _first_name;}
const std::string& User::getLastName() const {return _last_name;}
const std::string& User::getAdress() const {return _adress;}
const std::string& User::getPhone() const {return _phone;}

void User::setUser(int ID,const std::string& first_name, const std::string& last_name,
						const std::string& adress, const std::string& phone) 
{	
	_ID =ID;
	_first_name =first_name;
	_last_name=last_name;
	_adress=adress;
	_phone=phone; 
}

void User::setID(int ID) { _ID=ID; }
void User::setFirstName(const std::string& first_name) { _first_name=first_name; }
void User::setLastName(const std::string& last_name) { _last_name=last_name; }
void User::setAdress(const std::string& adress) { _adress=adress; }
void User::setPhone(const std::string& phone) { _phone=phone; }

bool User::operator<(const User& other)  const {return (_ID<other._ID);}
bool User::operator<=(const User& other) const {return (_ID<=other._ID);}
bool User::operator>(const User& other)  const {return (_ID>other._ID);}
bool User::operator>=(const User& other) const {return (_ID>=other._ID);}
bool User::operator==(const User& other) const {return (_ID==other._ID);}
bool User::operator!=(const User& other) const {return (_ID!=other._ID);}

std::ostream& operator<<(std::ostream& out,const User& user)
{
	if(out==cout)
		out<<"First name: "<<user._first_name<<"\nLast name: "<<user._last_name<<std::endl;
	else
		out<<user._first_name<<","<<user._last_name;
	return out;	
}

bool User::byName(const User& other) const {return (_first_name<other._first_name);}
bool User::bySurname(const User& other) const {return (_last_name<other._last_name);}

bool User::byNameAndSurname(const User& other) const
{
	return ((_first_name+_last_name)<(other._first_name+other._last_name));
}

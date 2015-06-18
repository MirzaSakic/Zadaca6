#include <iostream>
#include "user.h"

User::User(int ID,const std::string& first_name,const std::string& last_name, 
			const std::string& phone,const std::string& adress): 
            _ID(ID),_first_name(first_name),_last_name(last_name),_phone(phone), _adress(adress) {}

User::User(int ID): _ID(ID) {}

User::User(const std::string& first_name,const std::string& last_name, 
			const std::string& phone,const std::string& adress): 
            _first_name(first_name),_last_name(last_name),_phone(phone), _adress(adress) {}

User::User(std::string& user) {
	int i=0;
	
	int temporary=0;
	
	while(user[i]!='\0'){
		if(user[i]==',' && temporary==0){
			int id=stoi(user.substr(0,i));
			ID()=id;
			user=user.substr(i+1);
			i=-1;
			++temporary;
			}
		if(user[i]==',' && temporary==1){
			std::string name=user.substr(0,i);
			FirstName()=name;
			user=user.substr(i+1);
			i=-1;
			++temporary;
			}
		if(user[i]==',' && temporary==2){
			std::string surname=user.substr(0,i);
			LastName()=surname;
			user=user.substr(i+1);
			i=-1;
			++temporary;
			}
		if(user[i]==',' && temporary==3){
			std::string adress=user.substr(0,i);
			Adress()=adress;
			user=user.substr(i+1);
			i=-1;
			++temporary;
			}
	++i;
		}
	Phone()=user;
	
	}
            
const int& User::ID() const {return _ID;}             
const std::string& User::FirstName() const {return _first_name;}
const std::string& User::LastName() const {return _last_name;}
const std::string& User::Adress() const {return _adress;}
const std::string& User::Phone() const {return _phone;}

void User::setUser(int ID,const std::string& first_name, const std::string& last_name,
						const std::string& adress, const std::string& phone) 
{	
	_ID =ID;
	_first_name =first_name;
	_last_name=last_name;
	_adress=adress;
	_phone=phone; 
}

int& User::ID() { return _ID; }
std::string& User::FirstName() { return _first_name;}
std::string& User::LastName() { return _last_name;}
std::string& User::Adress() { return _adress; }
std::string& User::Phone() { return _phone; }

bool User::operator<(const User& other)  const {return (_ID<other._ID);}
bool User::operator<=(const User& other) const {return (_ID<=other._ID);}
bool User::operator>(const User& other)  const {return (_ID>other._ID);}
bool User::operator>=(const User& other) const {return (_ID>=other._ID);}
bool User::operator==(const User& other) const {return (_ID==other._ID);}
bool User::operator!=(const User& other) const {return (_ID!=other._ID);}

std::ostream& operator<<(std::ostream& out,const User& user)
{
	if(out==std::cout){
		out<<"ID: "<<user._ID<<"\nFirst name: "<<user._first_name<<"\nLast name: "<<user._last_name<<std::endl;
		out<<"Adress: "<<user._adress<<"\nPhone: "<<user._phone<<std::endl;
	}
	else
		out<<user._ID<<","<<user._first_name<<","<<user._last_name<<","<<user._adress<<","<<user._phone;
	return out;	
}

bool User::byName(const User& other) const {return (_first_name<other._first_name);}
bool User::bySurname(const User& other) const {return (_last_name<other._last_name);}

bool User::byNameAndSurname(const User& other) const
{
	return ((_first_name+_last_name)<(other._first_name+other._last_name));
}

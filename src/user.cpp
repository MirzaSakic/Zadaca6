#include "user.h"

User::User(int ID,const std::string& first_name,const std::string& last_name, 
			const std::string& phone,const std::string& adress): 
            _ID(ID),_first_name(first_name),_last_name(last_name),_phone(phone), _adress(adress) {}
            
int User::getID() const {return _ID;}            
std::string User::getFirstName() const {return _first_name;}
std::string User::getLastName() const {return _last_name;}
std::string User::getAdress() const {return _adress;}
std::string User::getPhone() const {return _phone;}

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
void User::setFirstName(std::string first_name) { _first_name=first_name; }
void User::setLastName(std::string last_name) { _last_name=last_name; }
void User::setAdress(std::string adress) { _adress=adress; }
void User::setPhone(std::string phone) { _phone=phone; }

bool User::operator<(User& other)  {return _ID<other._ID;}
bool User::operator<=(User& other) {return _ID<=other._ID;}
bool User::operator>(User& other)  {return _ID>other._ID;}
bool User::operator>=(User& other) {return _ID>=other._ID;}
bool User::operator==(User& other) {return _ID==other._ID;}
bool User::operator!=(User& other) {return _ID!=other._ID;}

std::ostream& operator<<(std::ostream& out,const User& user)
{
	out<<user._ID<<" "<<user._first_name<<" "<<user._last_name<<std::endl;
	return out;	
}

bool User::byName(User& other) {return _first_name<other._first_name;}
bool User::bySurname(User& other){return _last_name<other._last_name;}

bool User::byNameAndSurname(User& other)
{
	return (_first_name+_last_name)<(other._first_name+other._last_name);
}

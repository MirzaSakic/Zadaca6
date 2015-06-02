#ifndef _ACTOR_H
#define _ACTOR_H
#include <iostream>
#include <string>

class Actor {
	private:
	
	int _ID=0;
	std::string _FirstName=" ";
	std::string _LastName=" ";
	std::string _BirthDate=" ";
	std::string _BirthPlace=" ";
	
	friend std::ostream& operator<<(std::ostream& out,const Actor& actor);
	
	public:
	Actor()=default;
	Actor(std::string firstName,std::string lastName,std::string Birthdate,std::string Birthplace);
	Actor(std::string firstName,std::string lastName);
	
	int getID() const;
	std::string getFirstName() const;
	std::string getLastName() const;
	std::string getBirthDate() const;
	std::string getBirthPlace() const;
	
	void setID(int );
	void setFirstName(std::string);
	void setLastName(std::string);
	void setBirthDate(std::string);
	void setBirthPlace(std::string);
	void setActor(std::string firstName,std::string lastName,std::string Birthdate,std::string Birthplace);
	void setActor(std::string firstName,std::string lastName);
	

	bool operator<(const Actor& other) const;
	bool operator<=(const Actor& other) const;
	bool operator>(const Actor& other) const;
	bool operator>=(const Actor& other) const;
	bool operator==(const Actor& other) const;
	bool operator!=(const Actor& other) const;
	


};


#endif

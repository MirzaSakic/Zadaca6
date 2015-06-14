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
	Actor(const int& ID,const std::string& firstName,const std::string& lastName,const std::string& Birthdate,
		const std::string& Birthplace);
	Actor(const std::string& firstName,const std::string& lastName,const std::string& Birthdate,const std::string& Birthplace);
	Actor(const std::string& firstName,const std::string& lastName);
	Actor(int ID);
	Actor(std::string& actor);

	const int& ID() const;
	const std::string& FirstName() const;
	const std::string& LastName() const;
	const std::string& BirthDate() const;
	const std::string& BirthPlace() const;
	
	int& ID();
	std::string&  FirstName();
	std::string&  LastName();
	std::string&  BirthDate();
	std::string&  BirthPlace();	

	
	void setActor(const std::string& firstName,const std::string& lastName,const std::string& Birthdate,const std::string& Birthplace);
	void setActor(const std::string& firstName,const std::string& lastName);
	

	bool operator<(const Actor& other) const;
	bool operator<=(const Actor& other) const;
	bool operator>(const Actor& other) const;
	bool operator>=(const Actor& other) const;
	bool operator==(const Actor& other) const;
	bool operator!=(const Actor& other) const;
	


};


#endif

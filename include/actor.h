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

	const int& getID() const;
	const std::string& getFirstName() const;
	const std::string& getLastName() const;
	const std::string& getBirthDate() const;
	const std::string& getBirthPlace() const;
	
	int& setID();
	std::string&  setFirstName();
	std::string&  setLastName();
	std::string&  setBirthDate();
	std::string&  setBirthPlace();	

	void setID(int );
	void setFirstName(const std::string&);
	void setLastName(const std::string&);
	void setBirthDate(const std::string&);
	void setBirthPlace(const std::string&);
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

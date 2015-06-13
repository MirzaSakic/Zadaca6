#ifndef _USER_H
#define _USER_H
#include <string>
#include <iostream>

class User
{
	private: 
		int _ID=0;
		std::string _first_name="";
		std::string _last_name="";
		std::string _adress="";
		std::string _phone="";
		friend std::ostream& operator<<(std::ostream& out,const User& user);

	public:
		User() = default;
		User(int ID,const std::string& first_name,const std::string& last_name, 
				const std::string& adress,const std::string& phone);
		User(int ID);
		User(const std::string& first_name,const std::string& last_name, 
				const std::string& adress,const std::string& phone);
		User(std::string& user);
				
		const int& ID() const;
		const std::string& FirstName() const;
		const std::string& LastName() const;
		const std::string& Adress() const;
		const std::string& Phone() const;
		
		void setUser(int ID,const std::string& first_name, const std::string& last_name,
						const std::string& adress,const std::string& phone);
		int& ID();
		std::string& FirstName();	
		std::string& LastName();
		std::string& Adress();
		std::string& Phone();
		
		bool operator<(const User& other) const;
		bool operator<=(const User& other) const;
		bool operator>(const User& other) const;
		bool operator>=(const User& other) const;
		bool operator==(const User& other) const;
		bool operator!=(const User& other) const;
		
		bool byName(const User& other) const;
		bool bySurname(const User& other) const;
		bool byNameAndSurname(const User& other) const;
};



#endif

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
				
		int getID() const;
		std::string getFirstName() const;
		std::string getLastName() const;
		std::string getAdress() const;
		std::string getPhone() const;
		
		void setUser(int ID,const std::string& first_name, const std::string& last_name,
						const std::string& adress,const std::string& phone);
		void setID(int ID);
		void setFirstName(std::string first_name);	
		void setLastName(std::string last_name);
		void setAdress(std::string adress);
		void setPhone(std::string phone);
		
		bool operator<(User& other);
		bool operator<=(User& other);
		bool operator>(User& other);
		bool operator>=(User& other);
		bool operator==(User& other);
		bool operator!=(User& other);
		
		bool byName(User& other);
		bool bySurname(User& other);
		bool byNameAndSurname(User& other);
};



#endif

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
				
		const int& getID() const;
		const std::string& getFirstName() const;
		const std::string& getLastName() const;
		const std::string& getAdress() const;
		const std::string& getPhone() const;
		
		void setUser(int ID,const std::string& first_name, const std::string& last_name,
						const std::string& adress,const std::string& phone);
		void setID(int ID);
		void setFirstName(const std::string& first_name);	
		void setLastName(const std::string& last_name);
		void setAdress(const std::string& adress);
		void setPhone(const std::string& phone);
		
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

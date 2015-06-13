#ifndef __USERS_H
#define __USERS_H

#include "table.h"
#include "user.h"
#include "vector.h"

class Users : public Table<User>
{
  public:
    Users() = default;
    Users(const BinaryTree<User>& data) : Table<User>(data) {}
    Users(BinaryTree<User>&& data) : Table<User>(std::move(data)) {}
    Users(const std::string& file_path) : Table<User>(file_path) {}

    void AddIndexOnFirstName();
    void AddIndexOnLastName();
    void AddIndexOnAdress();
    void AddIndexOnTelephone();
    User& GetUser(int);                                  //!< Get user by ID
    sp::vector<User*> GetUsersByFirstName(const std::string&);        
    sp::vector<User*> GetUsersByLastName(const std::string&);
    const User& GetUser(int) const;
    const sp::vector<const User*> GetUsersByFirstName(const std::string&) const;
    const sp::vector<const User*> GetUsersByLastName(const std::string&) const;
    void printIndex(int) const;
    
    bool RemoveElement(const User&);
    void AddElement(User&);

  private:
    using usersindex=Table<User>::index<std::string*,User*>;
    sp::vector<BinaryTree<usersindex>> _indexes;
    int _IndexOnFirstName=-1;
    int _IndexOnLastName=-1;
    int _IndexOnAdress=-1;
    int _IndexOnTelephone=-1;
    int count = 0;
};

#endif

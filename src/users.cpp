#include "users.h"

using std::string; using sp::vector;
using std::cout; using std::endl;
using std::invalid_argument;
using std::move;

void Users::AddIndexOnFirstName()
{
  BinaryTree<usersindex> index;
  vector<User*> vecp;
  _data.TreeToVectorPointers(vecp);
  for(auto i=0;i<vecp.size();++i)
  {
    usersindex indice;
    indice.key = &(vecp[i]->FirstName());
    indice.pointers.push(vecp[i]);
    try
    {
      index.push(indice);
    }
    catch (...)
    {
      index.get(indice).pointers.push(vecp[i]);
    }
  }
  index.BalanceTree();
  _indexes.push(std::move(index));
  _IndexOnFirstName = _indexes.size() - 1;
}

void Users::AddIndexOnLastName()
{
  BinaryTree<usersindex> index;
  vector<User*> vecp;
  _data.TreeToVectorPointers(vecp);
  for(auto i=0;i<vecp.size();++i)
  {
    usersindex indice;
    indice.key = &(vecp[i]->LastName());
    indice.pointers.push(vecp[i]);
    try
    {
      index.push(indice);
    }
    catch (...)
    {
      index.get(indice).pointers.push(vecp[i]);
    }
  }
  index.BalanceTree();
  _indexes.push(std::move(index));
  _IndexOnLastName = _indexes.size() - 1;
}

void Users::AddIndexOnAdress()
{
  BinaryTree<usersindex> index;
  vector<User*> vecp;
  _data.TreeToVectorPointers(vecp);
  for(auto i=0;i<vecp.size();++i)
  {
    usersindex indice;
    indice.key = &(vecp[i]->Adress());
    indice.pointers.push(vecp[i]);
    try
    {
      index.push(indice);
    }
    catch (...)
    {
      index.get(indice).pointers.push(vecp[i]);
    }
  }
  index.BalanceTree();
  _indexes.push(std::move(index));
  _IndexOnAdress = _indexes.size() - 1;
}

void Users::AddIndexOnTelephone()
{
  BinaryTree<usersindex> index;
  vector<User*> vecp;
  _data.TreeToVectorPointers(vecp);
  for(auto i=0;i<vecp.size();++i)
  {
    usersindex indice;
    indice.key = &(vecp[i]->FirstName());
    indice.pointers.push(vecp[i]);
    try
    {
      index.push(indice);
    }
    catch (...)
    {
      index.get(indice).pointers.push(vecp[i]);
    }
  }
  index.BalanceTree();
  _indexes.push(std::move(index));
  _IndexOnTelephone = _indexes.size() - 1;
}

User& Users::GetUser(int ID)
{
  return getElement(User(ID));
}

vector<User*> Users::GetUsersByFirstName(const string& name)
{
  User user(name, "","","");
  vector<User*> res;
  if(_IndexOnFirstName==-1)
  {
    vector<User*> vecp;
    _data.TreeToVectorPointers(vecp);
    for(auto i=0;i<vecp.size();++i)
    {
      if(vecp[i]->FirstName() == user.FirstName())
      {
        res.push(vecp[i]);
      }
    }
  }
  else
  {
    string nme = name;
    usersindex indice;
    indice.key = &nme;
    try
    {
      indice = _indexes[_IndexOnFirstName].get(indice);
    }
    catch (invalid_argument err)
    {
      cout<<err.what()<<endl;
      return res;
    }
    for(auto i=0;i<indice.pointers.size();++i)
    {
      res.push(indice.pointers[i]);
    }
  }
  return res;
}

vector<User*> Users::GetUsersByLastName(const string& name)
{
  User user("",name,"","");
  vector<User*> res;
  if(_IndexOnLastName==-1)
  {
    vector<User*> vecp;
    _data.TreeToVectorPointers(vecp);
    for(auto i=0;i<vecp.size();++i)
    {
      if(vecp[i]->LastName() == user.LastName())
      {
        res.push(vecp[i]);
      }
    }
  }
  else
  {
    string nme = name;
    usersindex indice;
    indice.key = &nme;
    try
    {
      indice = _indexes[_IndexOnLastName].get(indice);
    }
    catch (invalid_argument err)
    {
      cout<<err.what()<<endl;
      return res;
    }
    for(auto i=0;i<indice.pointers.size();++i)
    {
      res.push(indice.pointers[i]);
    }
  }
  return res;
}

const User& Users::GetUser(int ID) const
{
  return getElement(User(ID));
}

const vector<const User *> Users::GetUsersByFirstName(const string& name) const
{
  User user(name, "","","");
  vector<const User*> res;
  if(_IndexOnFirstName==-1)
  {
    vector<User*> vecp;
    _data.TreeToVectorPointers(vecp);
    for(auto i=0;i<vecp.size();++i)
    {
      if(vecp[i]->FirstName() == user.FirstName())
      {
        res.push(vecp[i]);
      }
    }
  }
  else
  {
    string nme = name;
    usersindex indice;
    indice.key = &nme;
    try
    {
      indice = _indexes[_IndexOnFirstName].get(indice);
    }
    catch (invalid_argument err)
    {
      cout<<err.what()<<endl;
      return res;
    }
    for(auto i=0;i<indice.pointers.size();++i)
    {
      res.push(indice.pointers[i]);
    }
  }
  return res;
}

const vector<const User *> Users::GetUsersByLastName(const string& name) const
{
  vector<const User*> res;
  if(_IndexOnLastName==-1)
  {
    vector<User*> vecp;
    _data.TreeToVectorPointers(vecp);
    for(auto i=0;i<vecp.size();++i)
    {
      if(vecp[i]->LastName() == name)
      {
        res.push(vecp[i]);
      }
    }
  }
  else
  {
    string nme = name;
    usersindex indice;
    indice.key = &nme;
    usersindex& Indice = indice;
    try
    {
      Indice = _indexes[_IndexOnLastName].get(indice);
    }
    catch (invalid_argument err)
    {
      cout<<err.what()<<endl;
      return res;
    }
    for(auto i=0;i<indice.pointers.size();++i)
    {
      res.push(Indice.pointers[i]);
    }
  }
  return res;
}

bool Users::RemoveElement(const User& user)
{
  if(!_data.find(user))
  {
    return false;
  }
  User& usrRef = _data.get(user);
  count++;
  if(_IndexOnFirstName!=-1)
  {
    usersindex indice;
    indice.key = &(usrRef.FirstName());
    auto Indice = _indexes[_IndexOnFirstName].get(indice);
    auto vecUs = Indice.pointers;
    vector<User*> newVec;
    for(auto i=0;i<vecUs.size();++i)
    {
      if(vecUs[i]->ID()!=usrRef.ID())
      {
        newVec.push(vecUs[i]);
      }
    }
    if(newVec.size()==0)
    {
      _indexes[_IndexOnFirstName].remove(indice);
    }
    Indice.pointers=move(newVec);
  }
  if(_IndexOnLastName!=-1)
  {
    usersindex indice;
    indice.key = &(usrRef.LastName());
    auto Indice = _indexes[_IndexOnLastName].get(indice);
    auto vecUs = Indice.pointers;
    vector<User*> newVec;
    for(auto i=0;i<vecUs.size();++i)
    {
      if(vecUs[i]->ID()!=usrRef.ID())
      {
        newVec.push(vecUs[i]);
      }
    }
    if(newVec.size()==0)
    {
      _indexes[_IndexOnLastName].remove(indice);
    }
    Indice.pointers=move(newVec);
  }
  if(_IndexOnAdress!=-1)
  {
    usersindex indice;
    indice.key = &(usrRef.Adress());
    auto Indice = _indexes[_IndexOnAdress].get(indice);
    auto vecUs = Indice.pointers;
    vector<User*> newVec;
    for(auto i=0;i<vecUs.size();++i)
    {
      if(vecUs[i]->ID()!=usrRef.ID())
      {
        newVec.push(vecUs[i]);
      }
    }
    if(newVec.size()==0)
    {
      _indexes[_IndexOnAdress].remove(indice);
    }
    Indice.pointers=move(newVec);
  }
  if(_IndexOnTelephone!=-1)
  {
    usersindex indice;
    indice.key = &(usrRef.Phone());
    auto Indice = _indexes[_IndexOnTelephone].get(indice);
    auto vecUs = Indice.pointers;
    vector<User*> newVec;
    for(auto i=0;i<vecUs.size();++i)
    {
      if(vecUs[i]->ID()!=usrRef.ID())
      {
        newVec.push(vecUs[i]);
      }
    }
    if(newVec.size()==0)
    {
      _indexes[_IndexOnTelephone].remove(indice);
    }
    Indice.pointers=move(newVec);
  }
  _data.remove(user);
  return true;
}

void Users::AddElement(User& user)
{
  Table<User>::AddElement(user);
  User& usr = getElement(user);
  if(_IndexOnFirstName!=-1)
  {
    usersindex indice;
    indice.key = &(usr.FirstName());
    indice.pointers.push(&usr);
    try
    {
      _indexes[_IndexOnFirstName].push(indice);
    }
    catch (invalid_argument err)
    {
      _indexes[_IndexOnFirstName].get(indice).pointers.push(&usr);
    }
  }
  if(_IndexOnLastName!=-1)
  {
    usersindex indice;
    indice.key = &(usr.FirstName());
    indice.pointers.push(&usr);
    try
    {
      _indexes[_IndexOnLastName].push(indice);
    }
    catch (invalid_argument err)
    {
      _indexes[_IndexOnLastName].get(indice).pointers.push(&usr);
    }
  }
  if(_IndexOnAdress!=-1)
  {
    usersindex indice;
    indice.key = &(usr.FirstName());
    indice.pointers.push(&usr);
    try
    {
      _indexes[_IndexOnAdress].push(indice);
    }
    catch (invalid_argument err)
    {
      _indexes[_IndexOnAdress].get(indice).pointers.push(&usr);
    }
  }
  if(_IndexOnTelephone!=-1)
  {
    usersindex indice;
    indice.key = &(usr.FirstName());
    indice.pointers.push(&usr);
    try
    {
      _indexes[_IndexOnTelephone].push(indice);
    }
    catch (invalid_argument err)
    {
      _indexes[_IndexOnTelephone].get(indice).pointers.push(&usr);
    }
  }
}

void Users::printIndex(int ind) const
{
  _indexes[ind].printBST();
}

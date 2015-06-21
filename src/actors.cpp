#include "actors.h"

using std::string; using sp::vector;
using std::cout; using std::endl;
using std::invalid_argument;
using std::move;

void Actors::AddIndexOnFirstName()
{
  BinaryTree<actorsindex> index;
  vector<Actor*> vecp;
  _data.TreeToVectorPointers(vecp);
  for(auto i=0;i<vecp.size();++i)
  {
    actorsindex indice;
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

void Actors::AddIndexOnLastName()
{
  BinaryTree<actorsindex> index;
  vector<Actor*> vecp;
  _data.TreeToVectorPointers(vecp);
  for(auto i=0;i<vecp.size();++i)
  {
    actorsindex indice;
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

void Actors::AddIndexOnBirthDate()
{
  BinaryTree<actorsindex> index;
  vector<Actor*> vecp;
  _data.TreeToVectorPointers(vecp);
  for(auto i=0;i<vecp.size();++i)
  {
    actorsindex indice;
    indice.key = &(vecp[i]->BirthDate());
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
  _IndexOnBirthDate = _indexes.size() - 1;
}

void Actors::AddIndexOnBirthPlace()
{
  BinaryTree<actorsindex> index;
  vector<Actor*> vecp;
  _data.TreeToVectorPointers(vecp);
  for(auto i=0;i<vecp.size();++i)
  {
    actorsindex indice;
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
  _IndexOnBirthPlace = _indexes.size() - 1;
}

Actor& Actors::GetActor(int ID)
{
  return getElement(Actor(ID));
}

vector<Actor*> Actors::GetActorsByFirstName(const string& name)
{
  Actor actor(name, "","","");
  vector<Actor*> res;
  if(_IndexOnFirstName==-1)
  {
    vector<Actor*> vecp;
    _data.TreeToVectorPointers(vecp);
    for(auto i=0;i<vecp.size();++i)
    {
      if(vecp[i]->FirstName() == actor.FirstName())
      {
        res.push(vecp[i]);
      }
    }
  }
  else
  {
    string nme = name;
    actorsindex indice;
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

vector<Actor*> Actors::GetActorsByLastName(const string& name)
{
  Actor actor("",name,"","");
  vector<Actor*> res;
  if(_IndexOnLastName==-1)
  {
    vector<Actor*> vecp;
    _data.TreeToVectorPointers(vecp);
    for(auto i=0;i<vecp.size();++i)
    {
      if(vecp[i]->LastName() == actor.LastName())
      {
        res.push(vecp[i]);
      }
    }
  }
  else
  {
    string nme = name;
    actorsindex indice;
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

const Actor& Actors::GetActor(int ID) const
{
  return getElement(Actor(ID));
}

const vector<const Actor *> Actors::GetActorsByFirstName(const string& name) const
{
  Actor actor(name, "","","");
  vector<const Actor*> res;
  if(_IndexOnFirstName==-1)
  {
    vector<Actor*> vecp;
    _data.TreeToVectorPointers(vecp);
    for(auto i=0;i<vecp.size();++i)
    {
      if(vecp[i]->FirstName() == actor.FirstName())
      {
        res.push(vecp[i]);
      }
    }
  }
  else
  {
    string nme = name;
    actorsindex indice;
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

const vector<const Actor *> Actors::GetActorsByLastName(const string& name) const
{
  vector<const Actor*> res;
  if(_IndexOnLastName==-1)
  {
    vector<Actor*> vecp;
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
    actorsindex indice;
    indice.key = &nme;
    actorsindex& Indice = indice;
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

bool Actors::RemoveElement(const Actor& actor)
{
  if(!_data.find(actor))
  {
    return false;
  }
  Actor& actRef = _data.get(actor);
  count++;
  if(_IndexOnFirstName!=-1)
  {
    actorsindex indice;
    indice.key = &(actRef.FirstName());
    auto Indice = _indexes[_IndexOnFirstName].get(indice);
    auto vecUs = Indice.pointers;
    vector<Actor*> newVec;
    for(auto i=0;i<vecUs.size();++i)
    {
      if(vecUs[i]->ID()!=actRef.ID())
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
    actorsindex indice;
    indice.key = &(actRef.LastName());
    auto Indice = _indexes[_IndexOnLastName].get(indice);
    auto vecUs = Indice.pointers;
    vector<Actor*> newVec;
    for(auto i=0;i<vecUs.size();++i)
    {
      if(vecUs[i]->ID()!=actRef.ID())
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
  if(_IndexOnBirthDate!=-1)
  {
    actorsindex indice;
    indice.key = &(actRef.BirthDate());
    auto Indice = _indexes[_IndexOnBirthDate].get(indice);
    auto vecUs = Indice.pointers;
    vector<Actor*> newVec;
    for(auto i=0;i<vecUs.size();++i)
    {
      if(vecUs[i]->ID()!=actRef.ID())
      {
        newVec.push(vecUs[i]);
      }
    }
    if(newVec.size()==0)
    {
      _indexes[_IndexOnBirthDate].remove(indice);
    }
    Indice.pointers=move(newVec);
  }
  if(_IndexOnBirthPlace!=-1)
  {
    actorsindex indice;
    indice.key = &(actRef.BirthPlace());
    auto Indice = _indexes[_IndexOnBirthPlace].get(indice);
    auto vecUs = Indice.pointers;
    vector<Actor*> newVec;
    for(auto i=0;i<vecUs.size();++i)
    {
      if(vecUs[i]->ID()!=actRef.ID())
      {
        newVec.push(vecUs[i]);
      }
    }
    if(newVec.size()==0)
    {
      _indexes[_IndexOnBirthPlace].remove(indice);
    }
    Indice.pointers=move(newVec);
  }
  _data.remove(actor);
  return true;
}

void Actors::AddElement(Actor& actor)
{
  Table<Actor>::AddElement(actor);
  Actor& act = getElement(actor);
  if(_IndexOnFirstName!=-1)
  {
    actorsindex indice;
    indice.key = &(act.FirstName());
    indice.pointers.push(&act);
    try
    {
      _indexes[_IndexOnFirstName].push(indice);
    }
    catch (invalid_argument err)
    {
      _indexes[_IndexOnFirstName].get(indice).pointers.push(&act);
    }
  }
  if(_IndexOnLastName!=-1)
  {
    actorsindex indice;
    indice.key = &(act.FirstName());
    indice.pointers.push(&act);
    try
    {
      _indexes[_IndexOnLastName].push(indice);
    }
    catch (invalid_argument err)
    {
      _indexes[_IndexOnLastName].get(indice).pointers.push(&act);
    }
  }
  if(_IndexOnBirthPlace!=-1)
  {
    actorsindex indice;
    indice.key = &(act.FirstName());
    indice.pointers.push(&act);
    try
    {
      _indexes[_IndexOnBirthPlace].push(indice);
    }
    catch (invalid_argument err)
    {
      _indexes[_IndexOnBirthPlace].get(indice).pointers.push(&act);
    }
  }
  if(_IndexOnBirthDate!=-1)
  {
    actorsindex indice;
    indice.key = &(act.FirstName());
    indice.pointers.push(&act);
    try
    {
      _indexes[_IndexOnBirthDate].push(indice);
    }
    catch (invalid_argument err)
    {
      _indexes[_IndexOnBirthDate].get(indice).pointers.push(&act);
    }
  }
}

void Actors::printIndex(int ind) const
{
  _indexes[ind].printBST();
}

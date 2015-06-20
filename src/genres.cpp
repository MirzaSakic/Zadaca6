#include "genres.h"

using std::string; using sp::vector;
using std::cout; using std::endl;
using std::invalid_argument;
using std::move;

void Genres::AddIndexOnGenre_name()
{
  BinaryTree<genresindex> index;
  vector<Genre*> vecp;
  _data.TreeToVectorPointers(vecp);
  for(auto i=0;i<vecp.size();++i)
  {
    genresindex indice;
    indice.key = &(vecp[i]->genre_name());
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
  _IndexOnGenre_name = _indexes.size() - 1;
}


Genre& Genres::GetGenre(int ID)
{
  return getElement(Genre(ID));
}

vector<Genre*> Genres::GetGenresByGenre_name(const string& name)
{
  Genre genre(name);
  vector<Genre*> res;
  if(_IndexOnGenre_name==-1)
  {
    vector<Genre*> vecp;
    _data.TreeToVectorPointers(vecp);
    for(auto i=0;i<vecp.size();++i)
    {
      if(vecp[i]->genre_name() == genre.genre_name())
      {
        res.push(vecp[i]);
      }
    }
  }
  else
  {
    string nme = name;
    genresindex indice;
    indice.key = &nme;
    try
    {
      indice = _indexes[_IndexOnGenre_name].get(indice);
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



const Genre& Genres::GetGenre(int ID) const
{
  return getElement(Genre(ID));
}

const vector<const Genre *> Genres::GetGenresByGenre_name(const string& name) const
{
  Genre genre(name);
  vector<const Genre*> res;
  if(_IndexOnGenre_name==-1)
  {
    vector<Genre*> vecp;
    _data.TreeToVectorPointers(vecp);
    for(auto i=0;i<vecp.size();++i)
    {
      if(vecp[i]->genre_name() == genre.genre_name())
      {
        res.push(vecp[i]);
      }
    }
  }
  else
  {
    string nme = name;
    genresindex indice;
    indice.key = &nme;
    try
    {
      indice = _indexes[_IndexOnGenre_name].get(indice);
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


bool Genres::RemoveElement(const Genre& genre)
{
  if(!_data.find(genre))
  {
    return false;
  }
  Genre& actRef = _data.get(genre);
  count++;
  if(_IndexOnGenre_name!=-1)
  {
    genresindex indice;
    indice.key = &(actRef.genre_name());
    auto Indice = _indexes[_IndexOnGenre_name].get(indice);
    auto vecUs = Indice.pointers;
    vector<Genre*> newVec;
    for(auto i=0;i<vecUs.size();++i)
    {
      if(vecUs[i]->ID()!=actRef.ID())
      {
        newVec.push(vecUs[i]);
      }
    }
    if(newVec.size()==0)
    {
      _indexes[_IndexOnGenre_name].remove(indice);
    }
    Indice.pointers=move(newVec);
  }
 
  _data.remove(genre);
  return true;
}

void Genres::AddElement(Genre& genre)
{
  Table<Genre>::AddElement(genre);
  Genre& act = getElement(genre);
  if(_IndexOnGenre_name!=-1)
  {
    genresindex indice;
    indice.key = &(act.genre_name());
    indice.pointers.push(&act);
    try
    {
      _indexes[_IndexOnGenre_name].push(indice);
    }
    catch (invalid_argument err)
    {
      _indexes[_IndexOnGenre_name].get(indice).pointers.push(&act);
    }
  }
}

void Genres::printIndex(int ind) const
{
  _indexes[ind].printBST();
}

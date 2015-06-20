#include "films.h"

using std::string;using sp::vector;
using std::cout;using std::endl;
using std::invalid_argument;
using std::move;

/*
void Films::AddIndexOnReleaseYear()
{
  BinaryTree<filmsidx> index;
  vector<Film*> vecp;
  _data.TreeToVectorPointers(vecp);
  for(auto i=0;i<vecp.size();++i)
  {
    filmsidx indice;
    indice.key = &(vecp[i]->release_year());
    indice.pointers.push(vecp[i]);
    try
    {
      index.push(indice);
    }
    catch(...)
    {
      index.get(indice).pointers.push(vecp[i]);
    }
  }
  index.BalanceTree();
  _indexes_int.push(std::move(index));
  _IndexOnReleaseYear = _indexes.size() -1;
}
*/

void Films::AddIndexOnTitle()
{
  BinaryTree<filmsindex> index;
  vector<Film*> vecp;
  _data.TreeToVectorPointers(vecp);
  for(auto i=0;i<vecp.size();++i)
  {
    filmsindex indice;
    indice.key = &(vecp[i]->title());
    indice.pointers.push(vecp[i]);
    try
    {
      index.push(indice);
    }
    catch(...)
    {
      index.get(indice).pointers.push(vecp[i]);
    }
  }
  index.BalanceTree();
  _indexes.push(std::move(index));
  _IndexOnTitle = _indexes.size() -1;
}

Film& Films::GetFilm(int ID)
{
  return getElement(Film(ID));
}

const Film& Films::GetFilm(int ID) const
{
  return getElement(Film(ID));
}

/*
vector<Film*> Films::GetFilmsByReleaseYear(int release)
{
  Film film(0,release,"");
  vector<Film*> res;
  if(_IndexOnReleaseYear == -1)
  {
    vector<Film*> vecp;
    _data.TreeToVectorPointers(vecp);
    for(auto i=0;i<vecp.size();++i)
    {
      if(vecp[i]->release_year() == film.release_year())
      {
        res.push(vecp[i]);
      }
    }
  }
  else
  {
    int rel = release;
    filmsidx indice;
    indice.key = &rel;
    try
    {
      indice = _indexes_int[_IndexOnReleaseYear].get(indice);
    }
    catch(invalid_argument err)
    {
     cout<<err.what()<<endl;
    }
   for(auto i = 0;i<indice.pointers.size();++i)
   {
     res.push(indice.pointers[i]);
   }
  }
  return res;
}
*/

vector<Film*> Films::GetFilmsByTitle(const std::string& title)
{
  Film film(0,0,title);
  vector<Film*> res;
  if(_IndexOnTitle == -1)
  {
    vector<Film*> vecp;
    _data.TreeToVectorPointers(vecp);
    for(auto i=0;i<vecp.size();++i)
    {
      if (vecp[i]->title() == film.title());
      {
        res.push(vecp[i]);
      }
    }
  }
  else 
  {
    string tit = title;
    filmsindex indice;
    indice.key = &tit;
    try
    {
      indice = _indexes[_IndexOnTitle].get(indice);
    }
    catch(invalid_argument err)
    {
      cout<<err.what()<<endl;
      return res;
    }
    for(auto i = 0;i<indice.pointers.size();++i)
    {
      res.push(indice.pointers[i]);
    }
  }
  return res;
}

/*
const vector<const Film*>GetFilmsByReleaseYear(int release) const 
{
  Film film(0,release,"");
  vector<const Film*> res;
  if(_IndexOnReleaseYear == -1)
  {
    vector<Film*> vecp;
    _data.TreeToVectorPointers(vecp);
    for(auto i=0;i<vecp.size();++i)
    {
      if(vecp[i]->release_year() ==  film.release_year())
      {
        res.push(vecp[i]);
      }
    }
  }
  else
  {
    int rel = release;
    filmsidx indice;
    indice.key = &rel;
    try
    {
      indice = _indexes_int[_IndexOnReleaseYear].get(indice);
    }
    catch(invalid_argument err)
    {
     cout<<err.what()<<endl;
     return res;
    }
   for(auto i = 0;i<indice.pointers.size();++i)
   {
     res.push(indice.pointers[i]);
   }
  }
  return res;
}
*/

const vector<const Film*> Films::GetFilmsByTitle(const std::string& title) const 
{
  Film film(0,0,title);
  vector< const Film*> res;
  if(_IndexOnTitle == -1)
  {
    vector<Film*> vecp;
    _data.TreeToVectorPointers(vecp);
    for(auto i=0;i<vecp.size();++i)
    {
      if(vecp[i]->title() == film.title())
      {
        res.push(vecp[i]);
      }
    }
  }
  else 
  {
    string tit = title;
    filmsindex indice;
    indice.key = &tit;
    try
    {
      indice = _indexes[_IndexOnTitle].get(indice);
    }
    catch(invalid_argument err)
    {
      cout<<err.what()<<endl;
      return res;
    }
    for(auto i = 0;i<indice.pointers.size();++i)
    {
      res.push(indice.pointers[i]);
    }
  }
  return res;
}

bool Films::RemoveElement (const Film& film)
{
  if(! _data.find(film))
  {
    return false;
  }

  Film& filmRef = _data.get(film);
  count++;

/*  
  if(_IndexOnReleaseYear != -1)
  {
    filmsidx indice;
    indice.key = &(filmRef.release_year());
    auto Indice =_indexes_int[_IndexOnReleaseYear].get(indice);
    auto vecFm = Indice.pointers;
    vector<Film*> newVec;
    for(auto i=0;i<vecFm.size();++i)
    {
      if(vecFm[i]->ID() != filmRef.ID())
      {
        newVec.push(vecFm[i]);
      }
    }
    if(newVec.size() == 0)
    {
      _indexes_int[_IndexOnReleaseYear].remove(indice);
    }
    Indice.pointers=move(newVec);
  }
*/
  if(_IndexOnTitle != -1)
  {
    filmsindex indice;
    indice.key = &(filmRef.title());
    auto Indice =_indexes[_IndexOnTitle].get(indice);
    auto vecFm = Indice.pointers;
    vector<Film*> newVec;
    for(auto i=0;i<vecFm.size();++i)
    {
      if(vecFm[i]->ID() != filmRef.ID())
      {
        newVec.push(vecFm[i]);
      }
    }
    if(newVec.size() == 0)
    {
     _indexes[_IndexOnReleaseYear].remove(indice);
    }
    Indice.pointers=move(newVec);
  }

  _data.remove(film);
  return true;
}

void Films::AddElement (Film& film)
{
  Table<Film>::AddElement(film);
  Film& fm =getElement(film);
  
  if(_IndexOnTitle == -1)
  {
    filmsindex indice;
    indice.key = &(fm.title());
    indice.pointers.push(&fm);
    try
    {
      _indexes[_IndexOnTitle].push(indice);
    }
    catch (invalid_argument err)
    {
      _indexes[_IndexOnTitle].get(indice).pointers.push(&fm);
    }
  }
}

void Films::printIndex(int id) const 
{
  _indexes[id].printBST();
}


      







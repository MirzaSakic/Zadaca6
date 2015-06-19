#include "filmsactors.h"

using sp::vector; using std::cout;
using std::endl; using std::invalid_argument;
using std::move; using std::string;

void FilmsActors::AddIndexOnActors()
{
  vector<FilmActor*> vecp;
  _data.TreeToVectorPointers(vecp);
  for(auto i=0;i<vecp.size();++i)
  {
    tableindex indice;
    indice.key = &(vecp[i]->IDActor());
    indice.pointers.push(vecp[i]);
    try
    {
      _IndexOnActors.push(indice);
    }
    catch( invalid_argument err )
    {
      _IndexOnActors.get(indice).pointers.push(vecp[i]);
    }
  }
  _IndexOnFilms.BalanceTree();
}

FilmActor& FilmsActors::GetBorrowedRecord(int IDFilm, int IDActor)
{
  FilmActor temp(IDFilm, IDActor);
  vector<FilmActor*> tmpfilms = _data.getAll<FilmActor*>(temp);
  vector<FilmActor*> Films;
  for(auto i=0;i<tmpfilms.size();++i)
  {
    if(tmpfilms[i]->IDActor() == IDActor)
    {
      Films.push(tmpfilms[i]);
    }
  }
  for(auto i=0;i<Films.size();++i)
  {
    
      return *Films[i];
  }
  throw invalid_argument("Record does not exist.");
}

const FilmActor& FilmsActors::GetBorrowedRecord(int IDFilm, int IDActor) const
{
  FilmActor temp(IDFilm ,IDActor );
  vector<FilmActor*> tmpfilms = _data.getAll<FilmActor*>(temp);
  vector<FilmActor*> Films;
  for(auto i=0;i<tmpfilms.size();++i)
  {
    if(tmpfilms[i]->IDActor() == IDActor)
    {
      Films.push(tmpfilms[i]);
    }
  }
  for(auto i=0;i<Films.size();++i)
  {
   
      return *Films[i];
  }
  throw invalid_argument("Record does not exist.");
}

sp::vector<FilmActor*> FilmsActors::GetBorrowedRecords(int IDFilm, int IDActor)
{
  FilmActor temp(IDFilm, IDActor);
  vector<FilmActor*> tmpfilms = _data.getAll<FilmActor*>(temp);
  vector<FilmActor*> Films;
  for(auto i=0;i<tmpfilms.size();++i)
  {
    if(tmpfilms[i]->IDActor() == IDActor )
    {
      Films.push(tmpfilms[i]);
    }
  }
  return move(Films);
}

const sp::vector<const FilmActor*> FilmsActors::GetBorrowedRecords(int IDFilm, int IDActor){
  FilmActor temp(IDFilm, IDActor);
  vector<FilmActor*> tmpfilms = _data.getAll<FilmActor*>(temp);
  vector<const FilmActor*> Films;
  for(auto i=0;i<tmpfilms.size();++i)
  {
    if(tmpfilms[i]->IDActor() == IDActor)
    {
      Films.push(tmpfilms[i]);
    }
  }
  return move(Films);
}

sp::vector<FilmActor*> FilmsActors::GetRecordsForUser(int IDUser)
{
  FilmActor temp(0, IDActor);
 // cout<<"aab\n";
  vector<FilmActor*> Records = _data.getAll<FilmActor*>(temp);
 // cout<<"aac\n";
  return move(Records);
}

const sp::vector<const FilmActor*> FilmsActors::GetRecordsForActor(int IDActor) const
{
  FilmActor temp(0, IDActor);
  const vector<const FilmActor*> Records = _data.getAll<const FilmActor*>(temp);
  return move(Records);
}

sp::vector<FilmActor*> FilmsActors::GetRecordsForFilm(int IDFilm)
{
  FilmActor temp(IDFilm, 0);
  tableindex indice;
  indice.key = &IDFilm;
  vector<FilmActor*> Films = _IndexOnFilms.get(indice).pointers;
  return move(Films);
}

const sp::vector<const FilmActor*> FilmsActors::GetRecordsForFilm(int IDFilm) const
{
  FilmActor temp(IDFilm, 0);
  tableindex indice;
  indice.key = &IDFilm;
  vector<FilmActor*> tempmvs = _IndexOnFilms.get(indice).pointers;
  vector<const FilmActor*> Films;
  for(auto i=0;i<tempmvs.size();++i)
  {
    Films.push(move(tempmvs[i]));
  }
  return move(Films);
}

sp::vector<FilmActor*> FilmsActors::GetBorrowedRecordsForActor(int IDActor)
{
 // cout<<"aa\n";
  vector<FilmActor*> all = GetRecordsForActor(IDActor);
  vector<FilmActor*> res;
  for(auto i=0;i<all.size();++i)
  {
  //  if(all[i]->DateOfReturning().empty())
      res.push(all[i]);
  }
  return move(res);
}

const sp::vector<const FilmActor*> FilmsActors::GetBorrowedRecordsForActor(int IDActor) const
{
  vector<const FilmActor*> all = GetRecordsForActor(IDActor);
  vector<const FilmActor*> res;
  for(auto i=0;i<all.size();++i)
  {
    //if(all[i]->DateOfReturning().empty())
      res.push(all[i]);
  }
  return move(res);
}

vector<FilmActor*> FilmsActors::GetBorrowedRecordsForFilm(int IDFilm)
{
  vector<FilmActor*> all = GetRecordsForFilm(IDFilm);
  vector<FilmActor*> res;
  for(auto i=0;i<all.size();++i)
  {
   // if(all[i]->DateOfReturning().empty())
      res.push(all[i]);
  }
  return move(res);
}

const vector<const FilmActor*> FilmsActors::GetBorrowedRecordsForFilm(int IDFilm) const
{
  vector<const FilmActor*> all = GetRecordsForFilm(IDFilm);
  vector<const FilmActor*> res;
  for(auto i=0;i<all.size();++i)
  {
      res.push(all[i]);
  }
  return move(res);
}

void FilmsActors::LoadFromFile()
{
  sp::vector<FilmActor> values;
  std::ifstream input(_file_path);
  if(!input.is_open())
    throw invalid_argument("File does not exist");
  string line;
  string t = "1,3";
  FilmActor temp1(t);
  while(1)
  {
    getline(input,line);
    if((!input) || line[0] == '\n') break;
    cout<<line<<endl;
    FilmActor temp(line);
    values.push(temp);
  }
  _data.BalanceTree(values);
  AddIndexOnMovies();
}

void FilmsActors::AddElement(FilmActor& element)
{
  _data.push(element);
  tableindex indice;
  indice.key = &(element.IDActor());
  indice.pointers.push(&element);
  try
  {
    _IndexOnActors.push(indice);
  }
  catch(invalid_argument err)
  {
    _IndexOnActors.get(indice).pointers.push(&element);
  }
}

void FilmsActors::AddElement(const FilmActor& element)
{
  _data.push(element);
  FilmActor& record = getElement(element);
  tableindex indice;
  indice.key = &(record.IDActor());
  indice.pointers.push(&record);
  try
  {
    _IndexOnActors.push(indice);
  }
  catch(invalid_argument err)
  {
    _IndexOnActors.get(indice).pointers.push(&record);
  }
}

bool FilmsActors::RemoveElement(const FilmActor& element)
{
  tableindex indice;
  int IDActor = element.IDActor();
  indice.key = &(IDActor);
  tableindex& ind = indice;
  try
  {
    ind = _IndexOnActors.get(indice);
  }
  catch( invalid_argument err )
  {
    return false;
  }
  auto vecUs = ind.pointers;
  vector<FilmActor*> newVec;
  for(auto i=0;i<vecUs.size();++i)
  {
    if(vecUs[i]->IDActor() != element.IDActor() || vecUs[i]->IDFilm() != element.IDFilm())
    {
      newVec.push(vecUs[i]);
    }
  }
  if(newVec.size()==0)
  {
    _IndexOnActors.remove(indice);
  }
  ind.pointers = move(newVec);
  _data.remove(element);
  return true;
}

void FilmsActors::printActorsIndexed() const
{
  _IndexOnActors.printBST();
}


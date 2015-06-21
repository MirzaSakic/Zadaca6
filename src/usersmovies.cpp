#include "usersmovies.h"

using sp::vector; using std::cout;
using std::endl; using std::invalid_argument;
using std::move; using std::string;

void UsersMovies::AddIndexOnMovies()
{
  vector<FilmBorrowed*> vecp;
  _data.TreeToVectorPointers(vecp);
  for(auto i=0;i<vecp.size();++i)
  {
    tableindex indice;
    indice.key = &(vecp[i]->IDFilm());
    indice.pointers.push(vecp[i]);
    try
    {
      _IndexOnMovies.push(indice);
    }
    catch( invalid_argument err )
    {
      _IndexOnMovies.get(indice).pointers.push(vecp[i]);
    }
  }
  _IndexOnMovies.BalanceTree();
}

FilmBorrowed& UsersMovies::GetBorrowedRecord(int IDUser, int IDMovie)
{
  FilmBorrowed temp(IDUser, IDMovie, Date(0,0,0));
  vector<FilmBorrowed*> tmpusers = _data.getAll<FilmBorrowed*>(temp);
  vector<FilmBorrowed*> Users;
  for(auto i=0;i<tmpusers.size();++i)
  {
    if(tmpusers[i]->IDFilm() == IDMovie)
    {
      Users.push(tmpusers[i]);
    }
  }
  for(auto i=0;i<Users.size();++i)
  {
    if(Users[i]->DateOfReturning().empty())
      return *Users[i];
  }
  throw invalid_argument("Record does not exist.");
}

const FilmBorrowed& UsersMovies::GetBorrowedRecord(int IDUser, int IDMovie) const
{
  FilmBorrowed temp(IDUser, IDMovie, Date(0,0,0));
  vector<FilmBorrowed*> tmpusers = _data.getAll<FilmBorrowed*>(temp);
  vector<FilmBorrowed*> Users;
  for(auto i=0;i<tmpusers.size();++i)
  {
    if(tmpusers[i]->IDFilm() == IDMovie)
    {
      Users.push(tmpusers[i]);
    }
  }
  for(auto i=0;i<Users.size();++i)
  {
    if(Users[i]->DateOfReturning().empty())
      return *Users[i];
  }
  throw invalid_argument("Record does not exist.");
}

sp::vector<FilmBorrowed*> UsersMovies::GetBorrowedRecords(int IDUser, int IDMovie)
{
  FilmBorrowed temp(IDUser, IDMovie, Date(0,0,0));
  vector<FilmBorrowed*> tmpusers = _data.getAll<FilmBorrowed*>(temp);
  vector<FilmBorrowed*> Users;
  for(auto i=0;i<tmpusers.size();++i)
  {
    if(tmpusers[i]->IDFilm() == IDMovie && tmpusers[i]->DateOfReturning().empty())
    {
      Users.push(tmpusers[i]);
    }
  }
  return move(Users);
}

const sp::vector<const FilmBorrowed*> UsersMovies::GetBorrowedRecords(int IDUser, int IDMovie) const
{
  FilmBorrowed temp(IDUser, IDMovie, Date(0,0,0));
  vector<FilmBorrowed*> tmpusers = _data.getAll<FilmBorrowed*>(temp);
  vector<const FilmBorrowed*> Users;
  for(auto i=0;i<tmpusers.size();++i)
  {
    if(tmpusers[i]->IDFilm() == IDMovie && tmpusers[i]->DateOfReturning().empty())
    {
      Users.push(tmpusers[i]);
    }
  }
  return move(Users);
}

sp::vector<FilmBorrowed*> UsersMovies::GetRecordsForUser(int IDUser)
{
  FilmBorrowed temp(IDUser, 0, Date(0,0,0));
  //cout<<"aab\n";
  vector<FilmBorrowed*> Records = _data.getAll<FilmBorrowed*>(temp);
  //cout<<"aac\n";
  return move(Records);
}

const sp::vector<const FilmBorrowed*> UsersMovies::GetRecordsForUser(int IDUser) const
{
  FilmBorrowed temp(IDUser, 0, Date(0,0,0));
  const vector<const FilmBorrowed*> Records = _data.getAll<const FilmBorrowed*>(temp);
  return move(Records);
}

sp::vector<FilmBorrowed*> UsersMovies::GetRecordsForMovie(int IDMovie)
{
  FilmBorrowed temp(0, IDMovie, Date(0,0,0));
  tableindex indice;
  indice.key = &IDMovie;
  vector<FilmBorrowed*> Movies = _IndexOnMovies.get(indice).pointers;
  return move(Movies);
}

const sp::vector<const FilmBorrowed*> UsersMovies::GetRecordsForMovie(int IDMovie) const
{
  FilmBorrowed temp(0, IDMovie, Date(0,0,0));
  tableindex indice;
  indice.key = &IDMovie;
  vector<FilmBorrowed*> tempmvs = _IndexOnMovies.get(indice).pointers;
  vector<const FilmBorrowed*> Movies;
  for(auto i=0;i<tempmvs.size();++i)
  {
    Movies.push(move(tempmvs[i]));
  }
  return move(Movies);
}

sp::vector<FilmBorrowed*> UsersMovies::GetBorrowedRecordsForUser(int IDUser)
{
  //cout<<"aa\n";
  vector<FilmBorrowed*> all = GetRecordsForUser(IDUser);
  vector<FilmBorrowed*> res;
  for(auto i=0;i<all.size();++i)
  {
    if(all[i]->DateOfReturning().empty())
      res.push(all[i]);
  }
  return move(res);
}

const sp::vector<const FilmBorrowed*> UsersMovies::GetBorrowedRecordsForUser(int IDUser) const
{
  vector<const FilmBorrowed*> all = GetRecordsForUser(IDUser);
  vector<const FilmBorrowed*> res;
  for(auto i=0;i<all.size();++i)
  {
    if(all[i]->DateOfReturning().empty())
      res.push(all[i]);
  }
  return move(res);
}

vector<FilmBorrowed*> UsersMovies::GetBorrowedRecordsForMovie(int IDMovie)
{
  vector<FilmBorrowed*> all = GetRecordsForMovie(IDMovie);
  vector<FilmBorrowed*> res;
  for(auto i=0;i<all.size();++i)
  {
    if(all[i]->DateOfReturning().empty())
      res.push(all[i]);
  }
  return move(res);
}

const vector<const FilmBorrowed*> UsersMovies::GetBorrowedRecordsForMovie(int IDMovie) const
{
  vector<const FilmBorrowed*> all = GetRecordsForMovie(IDMovie);
  vector<const FilmBorrowed*> res;
  for(auto i=0;i<all.size();++i)
  {
    if(all[i]->DateOfReturning().empty())
      res.push(all[i]);
  }
  return move(res);
}

void UsersMovies::LoadFromFile()
{
  sp::vector<FilmBorrowed> values;
  std::ifstream input(_file_path);
  if(!input.is_open())
    throw invalid_argument("File does not exist");
  string line;
  string t = "1,3,10,6,2015,,,";
  FilmBorrowed temp1(t);
  while(1)
  {
    getline(input,line);
    if((!input) || line[0] == '\n') break;
    //cout<<line<<endl;
    FilmBorrowed temp(line);
    values.push(temp);
  }
  _data.BalanceTree(values);
  AddIndexOnMovies();
}

void UsersMovies::AddElement(FilmBorrowed& element)
{
  _data.push(element);
  tableindex indice;
  indice.key = &(element.IDFilm());
  indice.pointers.push(&element);
  try
  {
    _IndexOnMovies.push(indice);
  }
  catch(invalid_argument err)
  {
    _IndexOnMovies.get(indice).pointers.push(&element);
  }
}

void UsersMovies::AddElement(const FilmBorrowed& element)
{
  _data.push(element);
  FilmBorrowed& record = getElement(element);
  tableindex indice;
  indice.key = &(record.IDFilm());
  indice.pointers.push(&record);
  try
  {
    _IndexOnMovies.push(indice);
  }
  catch(invalid_argument err)
  {
    _IndexOnMovies.get(indice).pointers.push(&record);
  }
}

bool UsersMovies::RemoveElement(const FilmBorrowed& element)
{
  tableindex indice;
  int IDMovie = element.IDFilm();
  indice.key = &(IDMovie);
  tableindex& ind = indice;
  try
  {
    ind = _IndexOnMovies.get(indice);
  }
  catch( invalid_argument err )
  {
    return false;
  }
  auto vecUs = ind.pointers;
  vector<FilmBorrowed*> newVec;
  for(auto i=0;i<vecUs.size();++i)
  {
    if(vecUs[i]->IDFilm() != element.IDFilm() || vecUs[i]->IDUser() != element.IDUser())
    {
      newVec.push(vecUs[i]);
    }
  }
  if(newVec.size()==0)
  {
    _IndexOnMovies.remove(indice);
  }
  ind.pointers = move(newVec);
  _data.remove(element);
  return true;
}

void UsersMovies::printMoviesIndexed() const
{
  _IndexOnMovies.printBST();
}

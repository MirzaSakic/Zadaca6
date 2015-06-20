#include "filmsgenres.h"

using sp::vector; using std::cout;
using std::endl; using std::invalid_argument;
using std::move; using std::string;

void FilmsGenres::AddIndexOnGenres()
{
  vector<FilmGenre*> vecp;
  _data.TreeToVectorPointers(vecp);
  for(auto i=0;i<vecp.size();++i)
  {
    tableindex indice;
    indice.key = &(vecp[i]->IDFilm());
    indice.pointers.push(vecp[i]);
    try
    {
      _IndexOnGenres.push(indice);
    }
    catch( invalid_argument err )
    {
      _IndexOnGenres.get(indice).pointers.push(vecp[i]);
    }
  }
  _IndexOnGenres.BalanceTree();
}

/*
FilmGenre& FilmsGenres::GetFilmOfGenre(int IDFilm, int IDGenre)
{
  FilmGenre temp(IDFilm, IDGenre);
  vector<FilmGenre*> filmgen = _data.getAll<FilmGenre*>(temp);
  vector<FilmGenre*> fms;
  for(auto i=0;i<filmgen.size();++i)
  {
    if(filmgen[i]->IDFilm() == IDFilm)
    {
      fms.push(filmgen[i]);
    }
  }
}

const FilmGenre& FilmsGenres::GetFilmOfGenre(int IDFilm, int IDGenre) const
{
  FilmGenre temp(IDFilm, IDGenre);
  vector<FilmGenre*> filmgen = _data.getAll<FilmGenre*>(temp);
  vector<FilmGenre*> fms;
  for(auto i=0;i<filmgen.size();++i)
  {
    if(filmgen[i]->IDFilm() == IDFilm)
    {
      fms.push(filmgen[i]);
    }
  }
}
*/

sp::vector<FilmGenre*> FilmsGenres::GetFilmsOfGenre(int IDGenre)
{
  FilmGenre temp(0, IDGenre);
  vector<FilmGenre*> tmpgen = _data.getAll<FilmGenre*>(temp);
  vector<FilmGenre*> Gen;
  for(auto i=0;i<tmpgen.size();++i)
  {
    if(tmpgen[i]->IDGenre() == IDGenre)
    {
      Gen.push(tmpgen[i]);
    }
  }
  return move(Gen);
}

const sp::vector<const FilmGenre*> FilmsGenres::GetFilmsOfGenre(int IDGenre) const
{
  FilmGenre temp(0, IDGenre);
  vector<FilmGenre*> tmpgen = _data.getAll<FilmGenre*>(temp);
  vector<const FilmGenre*> Gen;
  for(auto i=0;i<tmpgen.size();++i)
  {
    if(tmpgen[i]->IDGenre() == IDGenre )
    {
      Gen.push(tmpgen[i]);
    }
  }
  return move(Gen);
}

sp::vector<FilmGenre*> FilmsGenres::GetGenresOfFilm(int IDFilm)
{
  FilmGenre temp(IDFilm,0);
  vector<FilmGenre*> tmpgen = _data.getAll<FilmGenre*>(temp);
  vector<FilmGenre*> Gen;
  for(auto i=0;i<tmpgen.size();++i)
  {
    if(tmpgen[i]->IDFilm() == IDFilm )
    {
      Gen.push(tmpgen[i]);
    }
  }
  return move(Gen);
}

const sp::vector<const FilmGenre*> FilmsGenres::GetGenresOfFilm(int IDFilm) const 
{
  FilmGenre temp(IDFilm,0);
  vector<FilmGenre*> tmpgen = _data.getAll<FilmGenre*>(temp);
  vector<const FilmGenre*> Gen;
  for(auto i=0;i<tmpgen.size();++i)
  {
    if(tmpgen[i]->IDFilm() == IDFilm )
    {
      Gen.push(tmpgen[i]);
    }
  }
  return move(Gen);
}

void FilmsGenres::LoadFromFile()
{
  sp::vector<FilmGenre> values;
  std::ifstream input(_file_path);
  if(!input.is_open())
    throw invalid_argument("File does not exist");
  string line;
  //string t = "1,3,10,6,2015,,,";
 // FilmGenre temp1(t);
  while(1)
  {
    getline(input,line);
    if((!input) || line[0] == '\n') break;
   // cout<<line<<endl;
    FilmGenre temp(line);
    values.push(temp);
  }
  _data.BalanceTree(values);
  AddIndexOnGenres();
}

void FilmsGenres::AddElement(FilmGenre& element)
{
  _data.push(element);
  tableindex indice;
  indice.key = &(element.IDFilm());
  indice.pointers.push(&element);
  try
  {
    _IndexOnGenres.push(indice);
  }
  catch(invalid_argument err)
  {
    _IndexOnGenres.get(indice).pointers.push(&element);
  }
}

void FilmsGenres::AddElement(const FilmGenre& element)
{
  _data.push(element);
  FilmGenre& record = getElement(element);
  tableindex indice;
  indice.key = &(record.IDFilm());
  indice.pointers.push(&record);
  try
  {
    _IndexOnGenres.push(indice);
  }
  catch(invalid_argument err)
  {
    _IndexOnGenres.get(indice).pointers.push(&record);
  }
}

bool FilmsGenres::RemoveElement(const FilmGenre& element)
{
  tableindex indice;
  int IDFilm = element.IDFilm();
  indice.key = &(IDFilm);
  tableindex& ind = indice;
  try
  {
    ind = _IndexOnGenres.get(indice);
  }
  catch( invalid_argument err )
  {
    return false;
  }
  auto vecUs = ind.pointers;
  vector<FilmGenre*> newVec;
  for(auto i=0;i<vecUs.size();++i)
  {
    if(vecUs[i]->IDFilm() != element.IDFilm() || vecUs[i]->IDGenre() != element.IDGenre())
    {
      newVec.push(vecUs[i]);
    }
  }
  if(newVec.size()==0)
  {
    _IndexOnGenres.remove(indice);
  }
  ind.pointers = move(newVec);
  _data.remove(element);
  return true;
}

void FilmsGenres::printGenresIndexed() const
{
  _IndexOnGenres.printBST();
}

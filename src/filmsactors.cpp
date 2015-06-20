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
  _IndexOnActors.BalanceTree();
}

FilmActor& FilmsActors::GetRecord(int IDFilm, int IDActor)
{
  FilmActor temp(IDFilm, 0);
  vector<FilmActor*> tmpfilms = _data.getAll<FilmActor*>(temp);
  for(auto i=0;i<tmpfilms.size();++i)
  {
    if(tmpfilms[i]->IDActor() == IDActor)
     return *(tmpfilms[i]);
  }
  throw invalid_argument("Record does not exits.");
}

const FilmActor& FilmsActors::GetRecord(int IDFilm, int IDActor) const
{
  FilmActor temp(IDFilm, 0);
  vector<FilmActor*> tmpfilms = _data.getAll<FilmActor*>(temp);
  for(auto i=0;i<tmpfilms.size();++i)
  {
    if(tmpfilms[i]->IDActor() == IDActor)
     return *(tmpfilms[i]); 
  }
  throw invalid_argument("Record does not exist.");
}

sp::vector<FilmActor*> FilmsActors::GetRecordsForActor(int IDActor) 
{
  FilmActor temp(0, IDActor);
  tableindex indice;
  indice.key = &IDActor;
  vector<FilmActor*> Records = _IndexOnActors.get(indice).pointers;
  return move(Records);

}


const sp::vector<const FilmActor*> FilmsActors::GetRecordsForActor(int IDActor) const
{
  FilmActor temp(0, IDActor);
  tableindex indice;
  indice.key = &IDActor;
  vector<FilmActor*> temprcs = _IndexOnActors.get(indice).pointers;
  vector<const FilmActor*> Records;
  for(auto i=0;i<temprcs.size();++i)
  {
    Records.push(move(temprcs[i]));
  }
  return move(Records);

}

sp::vector<FilmActor*> FilmsActors::GetRecordsForFilm(int IDFilm)
{
  FilmActor temp(IDFilm, 0);
  vector<FilmActor*> Records = _data.getAll<FilmActor*>(temp);
  return move(Records);
}

const sp::vector<const FilmActor*> FilmsActors::GetRecordsForFilm(int IDFilm) const
{
  FilmActor temp(IDFilm, 0);
  const vector<const FilmActor*> Records = _data.getAll<const FilmActor*>(temp);
  return move(Records);
}



void FilmsActors::LoadFromFile()
{
  sp::vector<FilmActor> values;
  std::ifstream input(_file_path);
  if(!input.is_open())
    throw invalid_argument("File does not exist");
  string line;
  while(1)
  {
    getline(input,line);
    if((!input) || line[0] == '\n') break;
    //cout<<line<<endl;
    FilmActor temp(line);
    values.push(temp);
  }
  _data.BalanceTree(values);
  AddIndexOnActors();
}

void FilmsActors::AddElement(FilmActor& element)
{
	//cout<<"aa\n";
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
	//cout<<"bb\n";
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


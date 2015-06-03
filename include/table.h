#ifndef _TABLE_H_
#define _TABLE_H_

#include <iostream>
#include <utility>
#include <functional>
#include <fstream>
#include "binarytree.h"
#include "vector.h"
#include <stdexcept>

template<typename T>
class Table
{
  using func = std::function<bool(const T&, const T&)>;
  public:
    Table() = default;
    Table(func gT,func lT,func eq) : _data(gT,lT,eq) {}
    Table(const BinaryTree<T>& data) : _data(data) {}
    Table(BinaryTree<T>&& data) : _data(std::move(data)) {}
    Table(const std::string& file_path) : _file_path(file_path) { LoadFromFile(); }

    template<typename U>
      void setTree(U&&);
    void setFilePath(const std::string& file_path) { _file_path = file_path; }

    const BinaryTree<T>& getTree() const { return _data; }
    std::string& getFilePath() { return _file_path; }
    const std::string& getFilePath() const { return _file_path; }
    
    virtual void LoadFromFile();
    virtual void ExportToFile() const; 

    virtual T& getElement(const T&);
    virtual const T& getElement(const T&) const;

    virtual bool CheckElement(const T&) const;

    friend std::ostream& operator<<(std::ostream& out, const Table& table)
    {
      table._data.inOrder(out);
      return out;
    }

  private:
    int _IDCounter{0};

  protected:
    BinaryTree<T> _data;
    std::string _file_path;
    template<typename U, typename Z>
      struct index;
};

template<typename T>
template<typename U>
void Table<T>::setTree(U&& tree)
{
  _data = std::forward<U>(tree);
}

template<typename T>
void Table<T>::LoadFromFile()
{
  sp::vector<T> values;
  std::ifstream input(_file_path);
  if(!input.is_open())
    throw std::invalid_argument("File does not exist");
  std::string line;
  while(1)
  {
    getline(input, line);
    if((!input) || line[0] == '\n') break;
    T temp(line);
    values.push(temp);
  }
}

template<typename T>
void Table<T>::ExportToFile() const
{
  std::ofstream out(_file_path);
  if(!out.is_open())
    throw std::invalid_argument("Could not open file");
  _data.inOrder(out);
}

template<typename T>
T& Table<T>::getElement(const T& element)
{
  return _data.get(element);
}

template<typename T>
const T& Table<T>::getElement(const T& element) const
{
  return _data.get(element);
}

template<typename T>
bool Table<T>::CheckElement(const T& element) const
{
  return _data.find(element);
}

template<typename T>
template<typename U, typename Z>
struct Table<T>::index
{ 
  U key;
  sp::vector<Z> pointers;
  bool operator<(const index& indice) const { return *key<*(indice.key); }
  bool operator>(const index& indice) const { return *key>*(indice.key); }
  bool operator==(const index& indice) const { return *key == *(indice.key); }
  friend std::ostream& operator<<(std::ostream& out, const index& indice)
  {
    for(auto i=0;i<indice.pointers.size();++i)
      out<<*(indice.pointers[i])<<' ';
    return out;
  }
};

#endif

#ifndef __FILMS_H
#define __FILMS_H

#include "table.h"
#include "film.h"
#include "vector.h"

class Films : public Table<Film> 
{
  private:
    using filmsindex =  Table<Film>::index<std::string*, Film*>;
 //   using filmsidx = Table<Film>::index<int*, Film*>;
    sp::vector<BinaryTree<filmsindex>>  _indexes;
 //   sp::vector<BinaryTree<filmsidx>  _indexes_int;
    int _IndexOnReleaseYear = -1;
    int _IndexOnTitle = -1;
    int count = 0;

  public:
    Films() = default;
    Films(const BinaryTree<Film>& data) : Table<Film>(data) {};
    Films(BinaryTree<Film>&& data) : Table<Film>(std::move(data)) {};
    Films(const std::string& file_path) : Table<Film>(file_path) {};
 //   void AddIndexOnReleaseYear();
    void AddIndexOnTitle();
    Film& GetFilm(int);
 //   sp::vector<Film*> GetFilmsByReleaseYear(const int&);
    sp::vector<Film*> GetFilmsByTitle(const std::string&);
    const Film& GetFilm (int) const;
 //   const sp::vector<const Film*> GetFilmsByReleaseYear(const int&) const;
    const sp::vector<const Film*> GetFilmsByTitle(const std::string&) const;
    void printIndex (int) const;

    bool RemoveElement(const Film&);
    void AddElement(Film&);
};

#endif 





#ifndef __GENRES_H
#define __GENRES_H

#include "table.h"
#include "genre.h"
#include "vector.h"

class Genres : public Table<Genre>
{
  public:
    Genres() = default;
    Genres(const BinaryTree<Genre>& data) : Table<Genre>(data) {}
    Genres(BinaryTree<Genre>&& data) : Table<Genre>(std::move(data)) {}
    Genres(const std::string& file_path) : Table<Genre>(file_path) {}

    void AddIndexOnGenre_name();
    
    Genre& GetGenre(int);                                  //!< Get Genre by ID
    sp::vector<Genre*> GetGenresByGenre_name(const std::string&);        
    const Genre& GetGenre(int) const;
    const sp::vector<const Genre*> GetGenresByGenre_name(const std::string&) const;
    void printIndex(int) const;
    
    bool RemoveElement(const Genre&);
    void AddElement(Genre&);

  private:
    using genresindex=Table<Genre>::index<std::string*,Genre*>;
    sp::vector<BinaryTree<genresindex>> _indexes;
    int _IndexOnGenre_name=-1;
    int count = 0;
};

#endif

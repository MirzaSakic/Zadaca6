#ifndef __FILMS_GENRES
#define __FILMS_GENRES

#include "table.h"
#include "filmgenre.h"

class FilmsGenres : public Table<FilmGenre>
{
  public:
    FilmsGenres() { _data.setLessThan(lte); }
    FilmsGenres(const BinaryTree<FilmGenre>& data) : Table<FilmGenre>(data) {AddIndexOnGenres();}
    FilmsGenres(BinaryTree<FilmGenre>&& data) : Table<FilmGenre>(std::move(data)) {AddIndexOnGenres();}
    FilmsGenres(const std::string& file_path) : Table<FilmGenre>(file_path) {_data.setLessThan(lte); }

   //  FilmGenre& GetFilmOfGenre (int,int);
    sp::vector<FilmGenre*> GetFilmsOfGenre(int);
    sp::vector<FilmGenre*> GetGenresOfFilm(int);

   // const FilmGenre& GetFilmOfGenre(int,int) const;
    const sp::vector<const FilmGenre*> GetFilmsOfGenre(int) const;
    const sp::vector<const FilmGenre*> GetGenresOfFilm(int) const;

    void LoadFromFile();
    void AddElement(FilmGenre&);
    void AddElement(const FilmGenre&);
    bool RemoveElement(const FilmGenre&);

    void printGenresIndexed() const;

    
  private:
    using tableindex = Table<FilmGenre>::index<int*, FilmGenre*>;
    BinaryTree<tableindex> _IndexOnGenres;
    void AddIndexOnGenres();   
    Table<FilmGenre>::func lte = static_cast<Table<FilmGenre>::func>([](const FilmGenre& first, const FilmGenre& second) { return first<=second; });
};

#endif

#ifndef __USERS_MOVIES
#define __USERS_MOVIES

#include "table.h"
#include "film_borrowed.h"

class UsersMovies : public Table<FilmBorrowed>
{
  public:
    UsersMovies() { _data.setLessThan(lte); }
    UsersMovies(const BinaryTree<FilmBorrowed>& data) : Table<FilmBorrowed>(data) {AddIndexOnMovies();}
    UsersMovies(BinaryTree<FilmBorrowed>&& data) : Table<FilmBorrowed>(std::move(data)) {AddIndexOnMovies();}
    UsersMovies(const std::string& file_path) : Table<FilmBorrowed>(file_path) {_data.setLessThan(lte); }

    FilmBorrowed& GetBorrowedRecord(int,int);
    sp::vector<FilmBorrowed*> GetBorrowedRecords(int,int);
    sp::vector<FilmBorrowed*> GetRecordsForUser(int);
    sp::vector<FilmBorrowed*> GetRecordsForMovie(int);
    sp::vector<FilmBorrowed*> GetBorrowedRecordsForUser(int);
    sp::vector<FilmBorrowed*> GetBorrowedRecordsForMovie(int);

    const FilmBorrowed& GetBorrowedRecord(int,int) const;
    const sp::vector<const FilmBorrowed*> GetBorrowedRecords(int,int) const;
    const sp::vector<const FilmBorrowed*> GetRecordsForUser(int) const;
    const sp::vector<const FilmBorrowed*> GetRecordsForMovie(int) const;
    const sp::vector<const FilmBorrowed*> GetBorrowedRecordsForUser(int) const;
    const sp::vector<const FilmBorrowed*> GetBorrowedRecordsForMovie(int) const;

    void LoadFromFile();
    void AddElement(FilmBorrowed&);
    void AddElement(const FilmBorrowed&);
    bool RemoveElement(const FilmBorrowed&);

    void printMoviesIndexed() const;

    
  private:
    using tableindex = Table<FilmBorrowed>::index<int*, FilmBorrowed*>;
    BinaryTree<tableindex> _IndexOnMovies;
    void AddIndexOnMovies();   
    Table<FilmBorrowed>::func lte = static_cast<Table<FilmBorrowed>::func>([](const FilmBorrowed& first, const FilmBorrowed& second) { return first<=second; });
};

#endif

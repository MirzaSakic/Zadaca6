#ifndef __FILMS_ACTORS
#define __FILMS_ACTORS

#include "table.h"
#include "filmactor.h"

class FilmsActors : public Table<FilmActor>
{
  public:
    FilmsActors() { _data.setLessThan(lte); }
    FilmsActors(const BinaryTree<FilmActor>& data) : Table<FilmActor>(data) {AddIndexOnActors();}
    FilmsActors(BinaryTree<FilmActor>&& data) : Table<FilmActor>(std::move(data)) {AddIndexOnActors();}
    FilmsActors(const std::string& file_path) : Table<FilmActor>(file_path) {_data.setLessThan(lte); }

    FilmActor& GetBorrowedRecord(int,int);
    sp::vector<FilmActor*> GetBorrowedRecords(int,int);
    sp::vector<FilmActor*> GetRecordsForActor(int);
    sp::vector<FilmActor*> GetRecordsForFilm(int);
    sp::vector<FilmActor*> GetBorrowedRecordsForActor(int);
    sp::vector<FilmActor*> GetBorrowedRecordsForFilm(int);

    const FilmActor& GetBorrowedRecord(int,int) const;
    const sp::vector<const FilmActor*> GetBorrowedRecords(int,int) const;
    const sp::vector<const FilmActor*> GetRecordsForActor(int) const;
    const sp::vector<const FilmActor*> GetRecordsForFilm(int) const;
    const sp::vector<const FilmActor*> GetBorrowedRecordsForActor(int) const;
    const sp::vector<const FilmActor*> GetBorrowedRecordsForFilm(int) const;

    void LoadFromFile();
    void AddElement(FilmActor&);
    void AddElement(const FilmActor&);
    bool RemoveElement(const FilmActor&);

    void printActorsIndexed() const;

    
  private:
    using tableindex = Table<FilmActor>::index<int*, FilmActor*>;
    BinaryTree<tableindex> _IndexOnActors;
    void AddIndexOnActors();   
    Table<FilmActor>::func lte = static_cast<Table<FilmActor>::func>([](const FilmActor& first, const FilmActor& second) { return first<=second; });
};

#endif


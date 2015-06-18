#ifndef __ACTORS_H
#define __ACTORS_H

#include "table.h"
#include "actor.h"
#include "vector.h"

class Actors : public Table<Actor>
{
  public:
    Actors() = default;
    Actors(const BinaryTree<Actor>& data) : Table<Actor>(data) {}
    Actors(BinaryTree<Actor>&& data) : Table<Actor>(std::move(data)) {}
    Actors(const std::string& file_path) : Table<Actor>(file_path) {}

    void AddIndexOnFirstName();
    void AddIndexOnLastName();
    void AddIndexOnBirthDate();
    void AddIndexOnBirthPlace();
    Actor& GetActor(int);                                  //!< Get Actor by ID
    sp::vector<Actor*> GetActorsByFirstName(const std::string&);        
    sp::vector<Actor*> GetActorsByLastName(const std::string&);
    const Actor& GetActor(int) const;
    const sp::vector<const Actor*> GetActorsByFirstName(const std::string&) const;
    const sp::vector<const Actor*> GetActorsByLastName(const std::string&) const;
    void printIndex(int) const;
    
    bool RemoveElement(const Actor&);
    void AddElement(Actor&);

  private:
    using actorsindex=Table<Actor>::index<std::string*,Actor*>;
    sp::vector<BinaryTree<actorsindex>> _indexes;
    int _IndexOnFirstName=-1;
    int _IndexOnLastName=-1;
    int _IndexOnBirthDate=-1;
    int _IndexOnBirthPlace=-1;
    int count = 0;
};

#endif

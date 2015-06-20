#include <iostream>
#include <fstream>
#include "film.h"
#include "user.h"
#include "genre.h"
#include "actor.h"
#include "table.h"
#include "users.h"
#include "usersmovies.h"
#include "films.h"
#include "actors.h"
#include "genres.h"
#include "filmsactors.h"
#include "filmgenre.h"
#include "filmsgenres.h"

using namespace std;

int printMenu();
int AddUser(Users&);
int AddMovie(Films&, Actors&, Genres&, FilmsActors&, FilmsGenres&);
int AddActor(Actors&);
int AddGenre(Genres&);
bool RentAMovie(UsersMovies&,User&);
bool ReturnAMovie(UsersMovies&,User&);


const string file_users="database/users.zad6";
const string file_actors="database/actors.zad6";
const string file_movies="database/movies.zad6";
const string file_genres="database/genres.zad6";
const string file_users_movies="database/user_has_movies.zad6";
const string file_movies_actors="database/movies_have_actors.zad6";
const string file_movies_genres="database/movies_have_genres.zad6";

int main(int argc, char *argv[])
{
  Users users;
  ifstream input(file_users);
  if(!input)
  {
    ofstream out(file_users);
    if(!out)
    {
      cout<<"Users data file not found! Could not create users.zad6 file\n\nAborted!"<<endl;
      return 0;
    }
    cout<<"Users data file not found! Empty users.zad6 file created"<<endl;
    out.close();
  }
  input.close();
  Films movies;
  input.open(file_movies);
  if(!input.is_open())
  {
    ofstream out(file_movies);
    if(!out)
    {
      cout<<"Movies data file not found! Could not create movies.zad6 file\n\nAborted!"<<endl;
      return 0;
    }
    cout<<"Movies data file not found! Empty movies.zad6 file created"<<endl;
    out.close();
  }
  input.close();
  Actors actors;
  input.open(file_actors);
  if(!input.is_open())
  {
    ofstream out(file_actors);
    if(!out)
    {
      cout<<"Actors data file not found! Could not create actors.zad6 file\n\nAborted!"<<endl;
      return 0;
    }
    cout<<"Actors data file not found! Empty actors.zad6 file created"<<endl;
    out.close();
  }
  input.close();
  Genres genres;
  input.open(file_genres);
  if(!input.is_open())
  {
    ofstream out(file_genres);
    if(!out)
    {
      cout<<"Genres data file not found! Could not create genres.zad6 file\n\nAborted!"<<endl;
      return 0;
    }
    cout<<"Genres data file not found! Empty genres.zad6 file created"<<endl;
    out.close();
  }
  input.close();
  UsersMovies UserHasMovie;
  input.open(file_users_movies);
  if(!input.is_open())
  {
    ofstream out(file_users_movies);
    if(!out)
    {
      cout<<"User-Movies data file not found! Could not create user_has_movies.zad6 file\n\nAborted!"<<endl;
      return 0;
    }
    cout<<"User-Movies data file not found! Empty user_has_movies.zad6 file created"<<endl;
    out.close();
  }
  input.close();
  FilmsActors FilmHasActors;
  input.open(file_movies_actors);
  if(!input.is_open())
  {
    ofstream out(file_movies_actors);
    if(!out)
    {
      cout<<"Movies-Actors data file not found! Could not create movies_have_actors.zad6 file\n\nAborted!"<<endl;
      return 0;
    }
    cout<<"Movies-Actors data file not found! Empty movies_have_actors.zad6 file created"<<endl;
    out.close();
  }
  input.close();
  FilmsGenres FilmHasGenres;
  input.open(file_movies_genres);
  if(!input.is_open())
  {
    ofstream out(file_movies_genres);
    if(!out)
    {
      cout<<"Movies-Genres data file not found! Could not create movies_have_genres.zad6 file\n\nAborted!"<<endl;
      return 0;
    }
    cout<<"Movies-Genres data file not found! Empty movies_have_genre.zad6 file created"<<endl;
    out.close();
  }
  input.close();
  users.setFilePath(file_users);
  users.LoadFromFile();
  cout<<"Users loaded!\n";
//  users.SetVerbose(true);
 // cout<<users.getElement(temp)<<endl;
  //temp.ID() = 11;
  //cout<<users.getElement(temp)<<endl;
  //users.printTree();
  users.AddIndexOnFirstName();
  users.AddIndexOnLastName();
  //users.RemoveElement(temp);
  //users.printIndex(0);
  
  UserHasMovie.setFilePath(file_users_movies);
  UserHasMovie.LoadFromFile();
  cout<<"UserHasMovie loaded\n";
  
  movies.setFilePath(file_movies);
  movies.LoadFromFile();
  cout<<"Movies loaded\n";
  movies.AddIndexOnTitle();
  
  actors.setFilePath(file_actors);
  actors.LoadFromFile();
  cout<<"Actors loaded\n";
  actors.AddIndexOnFirstName();
  actors.AddIndexOnLastName();

  genres.setFilePath(file_genres);
  genres.LoadFromFile();
  cout<<"Genres loaded\n";
  genres.AddIndexOnGenre_name();
  

/*users.printTree();
  UserHasMovie.printTree();
  movies.printTree();
  actors.printTree();
  genres.printTree();*/
  int choice=7;
  while(choice)
  {
    choice = printMenu();
    switch(choice)
    {
      case 0:
        break;
      case 1:
        {
          cout<<"New users ID: "<<AddUser(users)<<endl;
          users.printTree();
          break;
        }
      case 2:
        {
          cout<<"New movies ID: "<<AddMovie(movies, actors, genres, FilmHasActors, FilmHasGenres)<<endl;
          break;
        }
      case 3:
        {
          cout<<"New actors ID: "<<AddActor(actors)<<endl;
          break;
        }
      case 4:
        {
          cout<<"New genres ID: "<<AddGenre(genres)<<endl;
          break;
        }
      default:
        {
          cout<<"Wrong choice\n";
          break;
        }
    }
  }
  return 0;
}

int printMenu()
{
  int choice;
  cout<<"Please choose one of the following options:"<<endl;
  cout<<"1 Add new user to videostore"<<endl;
  cout<<"2 Add new movie"<<endl;
  cout<<"3 Add new actor"<<endl;
  cout<<"4 Add new genre"<<endl;
  cout<<"5 Rent a movie"<<endl;
  cout<<"6 Return a movie"<<endl;
  cout<<"0 End program"<<endl;
  cin>>choice;
  cin.ignore();
  return choice;
}

int AddUser(Users& users)
{
  string firstName,lastName,adress,phone;
  cout<<"Enter your first name: ";
  getline(cin,firstName);
  cout<<"Enter your last name: ";
  getline(cin,lastName);
  cout<<"Enter your adress: ";
  getline(cin,adress);
  cout<<"Enter your phone number: ";
  getline(cin,phone);
  User user(firstName,lastName,adress,phone);
  users.AddElement(user);
  cout<<"User successfully added."<<endl; 
  return user.ID();
}


int AddActor(Actors& actors)
{
  string firstName,lastName,birthDate,birthPlace;
  cout<<"Enter actors first name: ";
  getline(cin,firstName);
  cout<<"Enter actors last name: ";
  getline(cin,lastName);
  cout<<"Enter actors birth date: ";
  getline(cin,birthDate);
  cout<<"Enter actors birth place : ";
  getline(cin,birthPlace);
  Actor actor(firstName,lastName,birthDate,birthPlace);
  actors.AddElement(actor);
  cout<<"Actor successfully added."<<endl;
  return actor.ID();
}

int AddGenre(Genres& genres)
{
  string name;
  cout<<"Enter movie's genre: ";
  getline(cin,name);
  Genre genre(name);
  genres.AddElement(genre);
  cout<<"Movie's genre successfully added."<<endl;
  return genre.ID();
}

int AddMovie(Films& movies, Actors& actors, Genres& genres, FilmsActors& filmactors, FilmsGenres& filmsgenres)
{
  string name;
  int year;
  cout<<"Enter movie's name: ";
  getline(cin,name);
  cout<<"Enter movie's release year: ";
  cin>>year;
  cin.ignore();
  Film movie(year,name);
  movies.AddElement(movie);
  cout<<"Enter number of actors: \n";
  int NumOfActors;
  cin>>NumOfActors;
  cin.ignore();
  string line;
  for(auto i=0;i<NumOfActors;++i)
  {
    cout<<"Enter actors name: ";
    getline(cin,line);
    sp::vector<Actor*> found = actors.GetActorsByFirstName(line);
    if(found.size()==0)
    {
      cout<<"Actor not found!\n";
      int IDActor = AddActor(actors);
      FilmActor tempInter(movie.ID(), IDActor);
      filmactors.AddElement(move(tempInter));
    }
    else
    {
      cout<<"Found actors: \n";
      for(auto j=0;j<found.size();++j)
      {
        cout<<*found[j]<<endl;
      }
      cout<<"Enter actors ID: (if your actor is not in the list type 0)";
      int tempID;
      cin>>tempID;
      cin.ignore();
      if(!tempID)
      {
        tempID=AddActor(actors);
      } 
      FilmActor tempInter(movie.ID(), tempID);
      filmactors.AddElement(tempInter);
    }
  }
  cout<<"Enter number of genres: \n";
  int NumOfGenres;
  cin>>NumOfGenres;
  cin.ignore();
  for(auto i=0;i<NumOfGenres;++i)
  {
    cout<<"Enter genres name: ";
    getline(cin,line);
    sp::vector<Genre*> found = genres.GetGenresByGenre_name(line);
    if(found.size()==0)
    {
      cout<<"Genre not found!\n";
      Genre tempGenre(line);
      genres.AddElement(tempGenre);
      FilmGenre tempInter(movie.ID(), tempGenre.ID());
      filmsgenres.AddElement(move(tempInter));
    }
    else
    {
      FilmActor tempInter(movie.ID(), found[0]->ID());
      filmactors.AddElement(tempInter);
    }
  } 
  return movie.ID();
}

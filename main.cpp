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
#include "film_borrowed.h"

using namespace std;

int printMenu();
int AddUser(Users&);
int AddMovie(Films&, Actors&, Genres&, FilmsActors&, FilmsGenres&);
int AddActor(Actors&);
int AddGenre(Genres&);
bool RentAMovie(UsersMovies&,Films&);
bool ReturnAMovie(UsersMovies&);
void SaveChanges(bool*,Users&,Films&,Actors&,Genres&,UsersMovies&,FilmsActors&,FilmsGenres&);
void RentedMovies(UsersMovies&,Users&,Films&);
void RentHistory(UsersMovies&,Users&,Films&);
void SearchForMovie(Films&,Actors&,Genres&,FilmsActors&,FilmsGenres&);


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
  users.setFilePath(file_users);
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
    input.close();
  }
  else
  {
    input.close();
    users.LoadFromFile();
    users.AddIndexOnFirstName();
    users.AddIndexOnLastName();
    cout<<"Users table loaded!\n";
  }
  Films movies;
  input.open(file_movies);
  movies.setFilePath(file_movies);
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
    input.close();
  }
  else
  {
    input.close();
    movies.LoadFromFile();
    movies.AddIndexOnTitle();
    cout<<"Movies table loaded!\n";
  }
  Actors actors;
  input.open(file_actors);
  actors.setFilePath(file_actors);
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
    input.close();
  }
  else
  {
    input.close();
    actors.LoadFromFile();
    actors.AddIndexOnFirstName();
    actors.AddIndexOnLastName();
    cout<<"Actors table loaded!\n";
  }
  Genres genres;
  input.open(file_genres);
  genres.setFilePath(file_genres);
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
    input.close();
  }
  else
  {
    input.close();
    genres.LoadFromFile();
    genres.AddIndexOnGenre_name();
    cout<<"Genres table loaded!\n";
  }
  UsersMovies UserHasMovie;
  input.open(file_users_movies);
  UserHasMovie.setFilePath(file_users_movies);
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
    input.close();
  }
  else
  {
    input.close();
    UserHasMovie.LoadFromFile();
    cout<<"UsersMovies table loaded!\n";
  }
  FilmsActors FilmHasActors;
  input.open(file_movies_actors);
  FilmHasActors.setFilePath(file_movies_actors);
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
    input.close();
  }
  else
  {
    input.close();
    FilmHasActors.LoadFromFile();
    cout<<"MoviesActors table loaded!\n";
  }
  FilmsGenres FilmHasGenres;
  input.open(file_movies_genres);
  FilmHasGenres.setFilePath(file_movies_genres);
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
    input.close();
  }
  else
  {
    input.close();
    FilmHasGenres.LoadFromFile();
    cout<<"MoviesGenres table loaded!\n";
  }


  int choice=-1;
  bool save[7] = {0};
  while(choice)
  {
    choice = printMenu();
    switch(choice)
    {
      case 0:
		  {
		    char temp;
        for(auto i=0;i<7;++i)
        {
          if(save[i])
          {
            cout<<"Do you want to save changes? (Y/N): ";
            cin>>temp;
            cin.ignore();
            if(temp=='Y'||temp=='y')
            {
              SaveChanges(save,users,movies,actors,genres,UserHasMovie,FilmHasActors,FilmHasGenres);
              cout<<"Changes successfully saved."<<endl;
            }
            return 0;
          }
        }
        break;
		  }
      case 1:
        {
          cout<<"New users ID: "<<AddUser(users)<<endl;
          //users.printTree();
          save[0]=true;
          break;
        }
      case 2:
        {
          cout<<"New movies ID: "<<AddMovie(movies, actors, genres, FilmHasActors, FilmHasGenres)<<endl;
          save[1]=true;
          save[2]=true;
          save[6]=true;
          save[3]=true;
          save[5]=true;
          FilmHasGenres.printTree();
          
          break;
        }
      case 3:
        {
          cout<<"New actors ID: "<<AddActor(actors)<<endl;
          save[2]=true;
          break;
        }
      case 4:
        {
          cout<<"New genres ID: "<<AddGenre(genres)<<endl;
          save[3]=true;
          break;
        }
      case 5:
        {
          if(RentAMovie(UserHasMovie, movies))
          {
            cout<<"Movie successfully rented.\n";
            save[1]=true;
            save[4]=true;
          }
          else
          {
            cout<<"Error while renting a movie.\n";
          }
          break;
        }
      case 6:
      {
        ReturnAMovie(UserHasMovie);
        save[4]=true;
        break;
      }
      case 7:
      {
        RentedMovies(UserHasMovie,users,movies);
        break;
      }
      case 8:
      {
        RentHistory(UserHasMovie,users,movies);
        break;
      }
      case 9:
      {
        SearchForMovie(movies,actors,genres,FilmHasActors,FilmHasGenres);
        break;
      }
      case 10:
      {
        SaveChanges(save,users,movies,actors,genres,UserHasMovie,FilmHasActors,FilmHasGenres);
        cout<<"Changes successfully saved."<<endl;
        std::fill(save,save+7,0);
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
  cout<<"\nPlease choose one of the following options:"<<endl;
  cout<<"\t1 Add new user to videostore"<<endl;
  cout<<"\t2 Add new movie"<<endl;
  cout<<"\t3 Add new actor"<<endl;
  cout<<"\t4 Add new genre"<<endl;
  cout<<"\t5 Rent a movie"<<endl;
  cout<<"\t6 Return a movie"<<endl;
  cout<<"\t7 Rented movies of user"<<endl;
  cout<<"\t8 Rent history of user"<<endl;
  cout<<"\t9 Search for a movie\n";
  cout<<"\t10 Save changes"<<endl;
  cout<<"\t0 End program"<<endl;
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
      FilmGenre tempInter(movie.ID(), found[0]->ID());
      filmsgenres.AddElement(tempInter);
    }
  } 
  return movie.ID();
}
bool ReturnAMovie(UsersMovies& usermovies)
{
	int IDUser,IDMovie;
	cout<<"Enter user's ID: ";
	cin>>IDUser;
	cin.ignore();
	cout<<"Enter movie's ID: ";
	cin>>IDMovie;
	cin.ignore();
	try
	{
		int day,month,year;
		cout<<"Enter day of returning: ";
		cin>>day;
		cin.ignore();
		cout<<"Enter month of returning: ";
		cin>>month;
		cin.ignore();
		cout<<"Enter year of returning: ";
		cin>>year;
		cin.ignore();
		Date date(day,month,year);
		usermovies.GetBorrowedRecord(IDUser,IDMovie).DateOfReturning()=date;
		cout<<"Movie successfully returned."<<endl;
		return true;
	}
	catch(invalid_argument err)
	{
	  cout<<"User never borrowed movie with id "<<IDMovie<<endl;
	}
	return false;
}

void SaveChanges(bool *save,Users& users,Films& movies,Actors& actors,Genres& genres,
						UsersMovies& UserHasMovie,FilmsActors& FilmHasActors,FilmsGenres& FilmHasGenres)
{
	for(int i=0;i<7;++i)
		if(save[i]==true){
			if(i==0)
				users.ExportToFile();
			if(i==1)
				movies.ExportToFile();
			if(i==2)
				actors.ExportToFile();
			if(i==3)
				genres.ExportToFile();
			if(i==4)
				UserHasMovie.ExportToFile();
			if(i==5)
				FilmHasActors.ExportToFile();
			if(i==6)
				FilmHasGenres.ExportToFile();
		}
			
}


bool RentAMovie(UsersMovies& usersMovies,Films& films)
{
  
  string moviename;
  int Id;
  cout<<"Enter users ID: ";
  cin>>Id;
  cin.ignore();
  //films.printTree();
  cout<<"Enter movie's name: ";
  getline(cin,moviename);
  sp::vector<Film*> found = films.GetFilmsByTitle(moviename);
  if(found.size()==0)
  {
    cout<<"Movie not found!\n";
    return false;
  }
  else
  {
    cout<<"Found movies: \n";
    for(auto j=0;j<found.size();++j)
    {
      cout<<*found[j]<<endl;
    }
    cout<<"Enter movie ID:";
    int tempID;
    cin>>tempID;
    cin.ignore();
    int day,month,year;
    cout<<"Enter date (day month year): ";
    cin>>day>>month>>year;
    cin.ignore();
    Date date(day,month,year);
    FilmBorrowed usermovie(Id,tempID,date);
    usersMovies.AddElement(usermovie);
	}
return true;
}


void RentedMovies(UsersMovies& usermovies,Users& users,Films& movies)
{
  int userID;
  cout<<"Enter the ID of the user: ";
  cin>>userID;
  User user(userID);
  
  try
  {
    user = users.GetUser(userID);
  }
  catch(invalid_argument err)
  {
    cout<<err.what()<<endl;
    return;
  }
  
  sp::vector<FilmBorrowed*> vecp;

  try
  {
    vecp=usermovies.GetBorrowedRecordsForUser(userID);
  }
  
  catch(invalid_argument err)
  {
    cout<<err.what()<<endl;
    return;
  }
  
  if (vecp.size() == 0)
  {
    cout<<"The listed user has no rented movies"<<endl;
  }

  for(int i=0;i<vecp.size();i++)
  {
    cout<<endl;
    cout<<(movies.GetFilm( vecp[i]->IDFilm() ))<<endl;
    cout<<"Date of Borrowing: "<<vecp[i]->DateOfBorrowing()<<endl<<endl;
  }
}


void RentHistory(UsersMovies& usermovies,Users& users,Films& movies) 
{
  int userID;
  cout<<"Enter the ID of the user: ";
  cin>>userID;
  User user(userID);
  try
  {
    user = users.GetUser(userID);
  }
  catch(invalid_argument err)
  {
    cout<<err.what()<<endl;
    return;
  }

  sp::vector<FilmBorrowed*> vecp;
  
  try
  {
  vecp = usermovies.GetRecordsForUser(userID);
  }

  catch(invalid_argument err)
  {
    cout<<err.what();
    return;
  }

  if(vecp.size() == 0)
  {
    cout<<"The listed user has never rented any movies"<<endl;
    return;
  }

  for(int i = 0;i<vecp.size();++i)
  {
    cout<<endl;
    cout<<(movies.GetFilm( vecp[i]->IDFilm() ))<<endl;
    cout<<"Date of Borrowing: "<<(vecp[i]->DateOfBorrowing())<<endl;
    if(vecp[i]->DateOfReturning() != Date(0,0,0))
      cout<<"Date of Returning: "<<(vecp[i]->DateOfReturning())<<endl<<endl;
    else 
      cout<<"User has not yet returned this movie"<<endl<<endl;
  }
}


void SearchForMovie(Films& films, Actors& actors, Genres& genres, FilmsActors& fa, FilmsGenres& fg)
{
  cout<<"Enter movies name: ";
  string searchq;
  getline(cin, searchq);
  sp::vector<Film*> found = films.GetFilmsByTitle(searchq);
  if(!found.size())
  {
    cout<<"\n\nNo results\n\n";
  }
  else
  {
    cout<<"\n\nSearch results:\n\n";
    for(auto i=0;i<found.size();++i)
    {
      cout<<*found[i]<<endl<<endl;
      cout<<"Actors:\n";
      sp::vector<FilmActor*> mvac = fa.GetRecordsForFilm(found[i]->ID());
      for(auto j=0;j<mvac.size();++j)
      {
        cout<<actors.GetActor(mvac[j]->IDActor())<<endl;
      }
      sp::vector<FilmGenre*> mvge = fg.GetGenresOfFilm(found[i]->ID());
      cout<<"Genre ";
      auto j=0;
      for(j=0;j<mvge.size()-1;++j)
      {
        cout<<genres.GetGenre(mvge[j]->IDGenre()).genre_name()<<"/";
      }
      cout<<genres.GetGenre(mvge[j]->IDGenre()).genre_name()<<endl;
    }
  }
}

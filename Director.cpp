#include "Movie.h"
#include "Director.h"
#include "Movie.cpp"
#include <unordered_map>


// constructors
Director::Director()
{
    Director("", 0);
}
Director::Director(string n)
{
    Director(n, 0);
}

Director::Director(string n, int likes)
{
    name = n;
    fbLikesForDirector = likes;
}

// setters
void Director::setName(string n)
{
    name = n;
}

void Director::setLikes(int likes)
{
    fbLikesForDirector = likes;
}

void Director::addMovie(Movie *m)
{
    movieList.emplace_front(m);
}

// getters
string Director::getName()
{
    return name;
}
int Director::getLikes()
{
    return fbLikesForDirector;
}
forward_list<Movie *> Director::getMovies()
{
    return movieList;
}

// add to main map of directors
void Director::addDirector(Director *d)
{
}

Director *Director::searchDir(string name, unordered_map<string, DirectorAVL> allDirectors) {

    auto itr =allDirectors.find(name.substr(0,2));// search by key as first 2 letters of name 


   // itr->second will take into the value of the key which is avl in this case
    Director* dir =itr->second.search(name);// search the name in avl and return a director node
     
    // obtain the list of movies the director has directed from the director node
    forward_list <Movie *> directedMovies=dir->getMovies();


   cout<<"---The movies directed by director "<<name<<" are: ----- "<<endl;
    // display the list of movies 
    for (auto j=directedMovies.begin();j!= directedMovies.end();++j){
        cout<<(*j)->getTitle()<<endl;
    }


}

void Director::getDirectorOfGenre(string g,unordered_map<Genre, map<string, forward_list<Movie *>, greater<string>>> moviesByGenre) {
 Genre genre = convert(g);

    map<string, forward_list<Movie *>, greater<string>> moviesOfGen = moviesByGenre[genre]; // finding genre

    cout << "----------- " << g << " -----------" << endl;



    map<string, forward_list<Movie *>, greater<string>>::iterator it;

    for (it = moviesOfGen.begin(); it != moviesOfGen.end(); it++) // iterating over nested map

    {

        std::cout << "----------- " << it->first << " -----------"; // Rating

        forward_list<Movie *> movies = it->second;

        for (auto it = movies.begin(); it != movies.end(); ++it) // printing all movies of given genre

            cout << (*it)->getDirector() << endl;

    }
}

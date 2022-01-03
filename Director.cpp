#include "Director.h"

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

void Director::displayDirector() // display the details of director
{
    cout << "Director: " << getName() << endl;
    cout << "Fb Likes: " << getLikes() << endl;
    displayMovies();
}

void Director::displayMovies() // display the movie list the director has directed
{
    cout << "Movies Directed: ";
    for (auto it = getMovies().begin(); it != getMovies().end(); ++it) // traversing through forward list
        cout << (*it)->getTitle() << ", ";
}

Director *Director::searchDir(string name, unordered_map<string, DirectorAVL> allDirectors, bool display)
{
    Director *director = NULL;

    if (allDirectors.find(name.substr(0, 2)) != allDirectors.end()) // if key exists, search for director in ActorAVL
        director = allDirectors[name.substr(0, 2)].search(name);    // find director in avl

    if (display)
    {
        if (!director) //if director is not in the records
            cout << "Actor not found. Try Again" << endl;
        else // if director is present, print the details of director
            director->displayDirector();
    }

    return director;
}

void Director::getDirectorOfGenre(string g, unordered_map<Genre, map<string, forward_list<Movie *>, greater<string>>> moviesByGenre)
{
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

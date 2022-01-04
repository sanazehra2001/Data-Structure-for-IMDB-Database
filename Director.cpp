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

void Director::displayDirector() // display the details of director
{
    /*
    Method that will display the details of director such as name of director,facebook likes 
    and names of movies he has directed ( call displayMovies method)
    */
    cout << "Director: " << getName() << endl;
    cout << "Fb Likes: " << getLikes() << endl;
    displayMovies();
}

void Director::displayMovies()
{
    /*
    Method that will traverse and display the movies in the forward list of movies directed by each director
    */
    cout << "Movies Directed: ";
    for (auto it = getMovies().begin(); it != getMovies().end(); ++it) // traversing through forward list
        cout << (*it)->getTitle() << ", ";
}

Director *Director::searchDir(string name, unordered_map<string, DirectorAVL> allDirectors, bool display)
{
    /*
    The method will search for the director in the unordered map,'allDirectors', with key as the first two alphabets of name
    of the director and value contain an avl of pointers to director nodes named as 'DirectorAVL'.

    this method will search for the input director name by searching the first two alphabets of the name 
    in key if the key exist it will find the director in the avl . if the director is found the details 
    of director will be display. 
    */

    Director *director = NULL;

    if (allDirectors.find(name.substr(0, 2)) != allDirectors.end()) // search for key
        director = allDirectors[name.substr(0, 2)].search(name);    // search in avl

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
    /*
    The method will search for the director in the unordered map,'moviesByGenre', with key as genre
    and value contain another map with key as rating and value as a forward list of pointers to movie node

    this method will take the genre and convert this string into object then search for it in 
    the key of outer map and  will  iterating over inner map and display the movies 
    names of the given genre and the display of movies name will be sorted on rating as the key is 
    rating and contain a forward list of movie * as value
    */

    Genre genre = convert(g);

    if (genre == Genre::Invalid) // if string is not a valud genre
    {
        cout << "Invalid Genre" << endl;
        return;
    }
    map<string, forward_list<Movie *>, greater<string>> moviesOfGen = moviesByGenre[genre]; // finding genre
    cout << "----------- " << g << " -----------" << endl;
    map<string, forward_list<Movie *>, greater<string>>::iterator it;

    for (it = moviesOfGen.begin(); it != moviesOfGen.end(); it++) // iterating over nested map

    {
        std::cout << "----------- " << it->first << " -----------" << endl; // Rating
        forward_list<Movie *> movies = it->second;
        for (auto it = movies.begin(); it != movies.end(); ++it) // printing all movies of given genre
            cout << (*it)->getDirector()->getName() << endl;
    }
}

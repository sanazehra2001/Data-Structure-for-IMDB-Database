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

Director *Director::searchDir(string name) {}
void Director::getDirectorOfGenre(string genre) {}

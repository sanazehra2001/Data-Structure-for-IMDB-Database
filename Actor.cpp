#include "Actor.h"

// constructors
Actor::Actor()
{
    Actor("", 0);
}

Actor::Actor(string n)
{
    Actor(n, 0);
}

Actor::Actor(string n, int fb)
{
    name = n;
    fbLikesForActor = fb;
}

//setters
void Actor::setName(string n)
{
    name = n;
}
void Actor::setLikes(int likes)
{
    fbLikesForActor = likes;
}
void Actor::addMovie(Movie *m)
{
    //to be implemented
}

// getters
string Actor::getName()
{
    return name;
}

int Actor::getLikes()
{
    return fbLikesForActor;
}
map<string, forward_list<Movie *>> Actor::getMovie()
{
    return movieList;
}

int Actor::getCountOfMovies()
{
    int count = 0;
    map<string, forward_list<Movie *>>::iterator it;

    for (it = movieList.begin(); it != movieList.end(); it++)
    {
        forward_list<Movie *> movies = it->second;
        count += distance(movies.begin(), movies.end());
    }
    return count;
}

// add to main map
void Actor::addActor(Actor *a)
{
    //allActors.insert(a.name, a);
}

void Actor::display()
{
}

// methods related to actors specified in document provided
Actor *Actor::searchActor(string name, bool display)
{
}

void Actor::displayActorProfile(Actor *a) {}

//second method of the list
void Actor::getCoActors(string name) {}

void Actor::getUniqueCoActors(string name)
{
    //create AVL of unique coactors
}

void Actor::getCoActorsOfCoActors(string name) {} // return type has to be decided
bool Actor::isCoActor(string nameA, string nameB) {}

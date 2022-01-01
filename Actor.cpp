#include "Actor.h"


Actor::Actor(string n)
{
    Actor(n, 0);
}

Actor::Actor(string n, int fb)
{
    name = n;
    fbLikesForActor = fb;
}

string Actor::getName()
{
    return name;
}

void Actor::addActor(Actor *a)
{
    //allActors.insert(a.name, a);
}

void Actor::addToMovieMap(Movie *m) {}

//for first method in the list
Actor *Actor::searchActor(string name, bool display)
{
    //return pointer if found
    //return null if not
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


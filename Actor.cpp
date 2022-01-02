#include "Actor.h"
#include <iterator>

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

// helper functions
void Actor::displayAllMovies()
{

    // actor found: traverse thorugh the map of movies and find coactors
    map<string, forward_list<Movie *>>::iterator it; //iterator

    // traversing through the map of movies of given actor (movieList)
    for (it = this->movieList.begin(); it != this->movieList.end(); it++)
    {
        cout << "----------- " << it->first << " -----------" <<endl;   //  year
        forward_list<Movie *> movies = it->second;               // all movies of certain year
        for (auto it = movies.begin(); it != movies.end(); ++it) // traverse thorugh the forward_list of movies
        {
            Movie *m = (*it);              // pointer to movie
            cout << m->getTitle() << endl; // name of movie
        }
    }
}

void Actor::display()
{
    cout << "Name: " << name << endl;
    cout << "Total Movies: " << getCountOfMovies() << endl;
    displayAllMovies();
}

// methods related to actors specified in document provided
Actor *Actor::searchActor(string name, unordered_map<string, ActorAVL> allActors, bool display)
{
    Actor *actor = NULL;
    // finding actor by frst two letters of name in map of allActors, returns an avl of pointers to Actor
    ActorAVL actorsOfKey = allActors[name.substr(0, 2)];

    if (!actorsOfKey.isEmpty())           // if key exists, search for actor in ActorAVL
        actor = actorsOfKey.search(name); // find actor in avl

    if (display)
    {
        if (!actor) //if actor is not in the records
            cout << "Actor not found. Try Again" << endl;
        else // if actor is present, print the details of actor
            actor->display();
    }

    return actor;
}

//second method of the list
void Actor::getCoActors(string name)
{
    Actor *actor = searchActor(name, false); // finding the actor in allActors map

    // actor not found
    if (!actor)
    {
        cout << "Actor not found" << endl;
        return;
    }

    // actor found: traverse thorugh the map of movies and find coactors
    map<string, forward_list<Movie *>>::iterator it; //iterator

    // traversing through the map of movies of given actor (movieList)
    for (it = actor->movieList.begin(); it != actor->movieList.end(); it++)
    {
        forward_list<Movie *> movies = it->second;               // all movies of certain year
        for (auto it = movies.begin(); it != movies.end(); ++it) // traverse thorugh the forward_list of movies
        {
            Movie *m = (*it);              // pointer to movie
            cout << m->getTitle() << endl; // name of movie

            // finding coactors
            Actor **coActors = (*it)->getActor();         // all actors of this movie
            for (Actor **a = coActors; coActors + 3; ++a) //traversing through three actors of every movie
            {
                Actor *coAct = (*a);
                if (coAct->getName() != actor->getName()) // coActor is not the one we are searching coactors for
                {
                    cout << coAct->getName() << endl; //display names of coactor
                }
            }
        }
    }
}

void Actor::getUniqueCoActors(string name)
{
    //create AVL of unique coactors
}

void Actor::getCoActorsOfCoActors(string name) {} // return type has to be decided

bool Actor::isCoActor(string nameA, string nameB) {}

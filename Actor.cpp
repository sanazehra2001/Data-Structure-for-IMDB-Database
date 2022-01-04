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
    forward_list<Movie *> mov = movieList[m->getTitleYear()];
    mov.emplace_front(m);
    movieList[m->getTitleYear()] = mov;
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

map<short int, forward_list<Movie *>> Actor::getMovie()
{
    return movieList;
}

int Actor::getCountOfMovies()
{
    int count = 0;
    map<short int, forward_list<Movie *>>::iterator it;

    for (it = movieList.begin(); it != movieList.end(); it++)
    {
        forward_list<Movie *> movies = it->second;
        count += distance(movies.begin(), movies.end());
    }
    return count;
}

// helper method to display all actors
void Actor::displayAllActors(unordered_map<string, ActorAVL> allActors)
{
    unordered_map<string, ActorAVL>::iterator it; //iterator

    for (it = allActors.begin(); it != allActors.end(); it++)
    {
        cout << "----------- " << it->first << " -----------" << endl;
        ActorAVL avl = it->second;
        avl.traverse();
    }
}

// helper functions
void Actor::displayAllMovies()
{
    cout << "Movies: " << endl;
    map<short int, forward_list<Movie *>>::iterator it; //iterator

    // traversing through the map of movies of given actor (movieList)
    for (it = this->movieList.begin(); it != this->movieList.end(); it++)
    {
        if (it->first != 0)
            cout << "----------- " << it->first << " -----------" << endl; //  year
        forward_list<Movie *> movies = it->second;                         // all movies of certain year
        for (auto it = movies.begin(); it != movies.end(); ++it)           // traverse thorugh the forward_list of movies
        {
            Movie *m = (*it);              // pointer to movie
            cout << m->getTitle() << endl; // name of movie
        }
        cout << endl;
    }
    cout << endl;
}

void Actor::display()
{
    /*display all the details of the actor such as actor name , fb likes,total movies & 
    names of the movies actor has acted in */
    cout << "Name: " << name << endl;
    cout << "FB Likes: " << getLikes() << endl;
    cout << "Total Movies: " << getCountOfMovies() << endl
         << endl;
    displayAllMovies();
}

// methods related to actors specified in document provided
Actor *Actor::searchActor(string name, unordered_map<string, ActorAVL> allActors, bool display)
{
    /*
    The method will take the actor name as input and  search for the actor in the unordered map,
    'allActors', with key as the first two alphabets of actor name and value contain an avl
     of pointers to actor nodes named as 'ActorAVL'.

    this method will search for the input actor name by searching the first two alphabets of the name 
    in map if the key exist it will find the actor in the avl  and return the actor pointer if found 
    otherwise it will return null. if display parameter is true it will print the details of the actor.
    */

    Actor *actor = NULL;

    // finding actor, returns an avl of pointers to Actor
    if (allActors.find(name.substr(0, 2)) != allActors.end()) // if key exists, search for actor in ActorAVL
        actor = allActors[name.substr(0, 2)].search(name);    // find actor in avl

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
forward_list<Actor *> Actor::getCoActors(string name, unordered_map<string, ActorAVL> allActors)
{

    /*
    This method will take  the name of the actor as input and search for actor in the map ,'allActors',
    with key as the first two alphabets of actor name and value contain an avl of *Actor 
    named as 'ActorAVL'.

    In this method first we will search for the actor 
    case1: If actor not found then it will return an empty list of coactor
    case2: 
        1. If the actor is found in the map then we will traverse through the movies map 
           (that has year as key and values as forward list of pointer to Movie)
        2. For each movie traverse through the array of actors, these are the coactors.
        3. Add coactors to list of coactors
        4. Return the list of coactors 

    */

    forward_list<Actor *> coactorsList;                 // forward_list for storing coactors
    Actor *actor = searchActor(name, allActors, false); // finding the actor in allActors map

    // actor not found
    if (!actor)
    {
        cout << "Actor not found" << endl;
        return coactorsList;
    }

    // actor found: traverse thorugh the map of movies and find coactors
    map<short int, forward_list<Movie *>>::iterator it; //iterator

    // traversing through the map of movies of given actor (movieList)
    for (it = actor->movieList.begin(); it != actor->movieList.end(); it++)
    {
        forward_list<Movie *> movies = it->second;               // all movies of certain year
        for (auto it = movies.begin(); it != movies.end(); ++it) // traverse thorugh the forward_list of movies
        {
            Movie *m = (*it); // pointer to movie

            // finding coactors
            Actor **coActors = (*it)->getActor(); // all actors of this movie
            for (Actor **i = coActors; i < coActors + 3; i++)
            {
                if ((*(i))->getName() != actor->getName()) // if actor is not the actor itself
                    coactorsList.emplace_front(*(i));
            }
        }
    }

    return coactorsList;
}

//second method of the list
void Actor::displayCoActors(string name, unordered_map<string, ActorAVL> allActors)
{

    /*
    This method will take  the name of the actor as input and search for actor in the map ,'allActors',
    with key as the first two alphabets of actor name and value contain an avl of *actor 
    named as 'ActorAVL'.

    In this method first we will search for the actor 
    case1: If actor not found then it an error message is displayed
    case2: 
        1. If the actor is found in the map then we will traverse through the movies map 
           (that has year as key and values as forward list of pointer to Movie)
        2. For each movie traverse through the array of actors, these are the coactors.
        3. Print the name of coactors

    */

    Actor *actor = searchActor(name, allActors, false); // finding the actor in allActors map

    // actor not found
    if (!actor)
    {
        cout << "Actor not found" << endl;
        return;
    }

    // actor found: traverse thorugh the map of movies and find coactors
    map<short int, forward_list<Movie *>>::iterator it; //iterator

    // traversing through the map of movies of given actor (movieList)
    for (it = actor->movieList.begin(); it != actor->movieList.end(); it++)
    {
        forward_list<Movie *> movies = it->second;               // all movies of certain year
        for (auto it = movies.begin(); it != movies.end(); ++it) // traverse thorugh the forward_list of movies
        {
            Movie *m = (*it);                           // pointer to movie
            cout << "MOVIE: " << m->getTitle() << endl; // name of movie

            // finding coactors
            Actor **coActors = (*it)->getActor(); // all actors of this movie
            cout << "\tCoActors: ";

            for (Actor **i = coActors; i < coActors + 3; i++) // actors of this movie
            {
                if ((*(i))->getName() != actor->getName()) // if actor is not himself
                    cout << (*(i))->getName() << ", ";
            }
            cout << endl
                 << endl;
        }
    }
}

void Actor::getUniqueCoActors(string name, unordered_map<string, ActorAVL> allActors)
{
    /*   Note: This Method uses unordered_map<string, ActorAVL> allActors that stores all actors

        Print the name of all co-actors of an actor only once. For each co-actor,
        print title of the movies in which both acted in.

    Methodology:
    Implementaton using unordered map of Actor having movies as value
        1. find coactors
        2. insert name of coactor in map as a key, if not present
        3. add movie title to the forward_list of movies coresponding to this coactor (value of map)

    */

    Actor *actor = searchActor(name, allActors, false); // finding the actor in allActors map

    // actor not found
    if (!actor)
    {
        cout << "Actor not found" << endl;
        return;
    }

    // actor found: traverse thorugh the map of movies and find coactors
    // map for storing coactors and corresponding movies
    unordered_map<string, forward_list<string>> coactorsMap; // key: name of coactor, value: forward_list of title of movie

    map<short int, forward_list<Movie *>>::iterator it; //iterator

    // traversing through the map of movies of given actor (movieList)
    for (it = actor->movieList.begin(); it != actor->movieList.end(); it++)
    {
        forward_list<Movie *> movies = it->second;               // all movies of certain year
        for (auto it = movies.begin(); it != movies.end(); ++it) // traverse thorugh the forward_list of movies
        {
            Movie *m = (*it); // pointer to movie

            // finding coactors
            Actor **coActors = (*it)->getActor();             // all actors of this movie
            for (Actor **a = coActors; a < coActors + 3; a++) //traversing through three actors of every movie
            {
                Actor *coAct = (*a);
                if (coAct->getName() != actor->getName()) // coActor is not the one we are searching coactors for
                {
                    forward_list<string> movies = coactorsMap[coAct->getName()]; // get key
                    movies.emplace_front(m->getTitle());                         // insert to movies
                    coactorsMap[coAct->getName()] = movies;                      // insert to map
                }
            }
        }
    }

    // display
    unordered_map<string, forward_list<string>>::iterator itCoactors; //iterator

    // traversing through the map of coactors
    for (itCoactors = coactorsMap.begin(); itCoactors != coactorsMap.end(); itCoactors++)
    {
        cout << itCoactors->first << endl; // name of coactor
        cout << "Movies: ";
        forward_list<string> movies = itCoactors->second;           // all common movies
        for (auto mov = movies.begin(); mov != movies.end(); ++mov) // traverse thorugh the forward_list of movies
        {
            cout << (*mov) << "\t "; //print movie title
        }
        cout << endl
             << endl;
    }
}

bool inCoactors(forward_list<Actor *> coactors, string name)
// check if the given actor name is in coactor list or not
{
    for (auto it = coactors.begin(); it != coactors.end(); ++it) // traverse thorugh the forward_list of movies
    {
        if ((*it)->getName() == name)
            return true;
    }
    return false;
}

void Actor::getCoActorsOfCoActors(string name, unordered_map<string, ActorAVL> allActors)
{
    /*
    This method will take the actor name as input and 
        1) Find the list of coactors of given actor 
        2) Traverse the list and find the coactors of each coactor (subactors)
        3) Add to avl,'allCoactors', if subactor is not coactor of actor and actor itself
        4) Impelmentation of AVL is such that it does not take duplicates
        4) Traverse and print allCoactors  
    */

    forward_list<Actor *> coactors = getCoActors(name, allActors); // coactors of actor
    ActorAVL allCoactor; // avl to store coactors of coactors
    if (!coactors.empty())
    {
        for (auto it1 = coactors.begin(); it1 != coactors.end(); ++it1) // traverse thorugh the forward_list of movies
        {
            forward_list<Actor *> subCoactors = getCoActors((*it1)->name, allActors); // finding coactors of coactors
            for (auto it2 = subCoactors.begin(); it2 != subCoactors.end(); ++it2) // traverse thorugh the forward_list of coactors
            {
                Actor *subActor = *it2;
                // add to avl if subactor is not coactor of actor and actor itself
                if (subActor->getName() != name && !inCoactors(coactors, subActor->getName()))
                    allCoactor.insert(subActor);
            }
        }

        allCoactor.traverse(); // printing all coactors of coactors
    }
}

bool Actor::isCoActor(string nameA, string nameB, unordered_map<string, ActorAVL> allActors)
{

    /* check if the two actors( A & B) are coactors or not 
        1)find the coactors of A 
        2)if B is in list of coactors of A then both are coactors 
    */

    forward_list<Actor *> coactors = getCoActors(nameA, allActors); //coactors of A
    if (!coactors.empty())
    {
        for (auto it = coactors.begin(); it != coactors.end(); ++it) // traverse thorugh the forward_list of movies
        {
            if ((*it)->getName() == nameB) // B is present in list
                return true;
        }
    }
    return false; // if B not found in the list
}

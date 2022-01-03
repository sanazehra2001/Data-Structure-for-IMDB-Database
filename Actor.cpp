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
    if (movieList.find(m->getTitleYear()) != movieList.end()) // if key exists, add movie to the existing list of movies
        movieList.at(m->getTitleYear()).emplace_front(m);

    else // if key does not exists, make forward_list of Movie* and make new key for this year
    {
        forward_list<Movie *> moviesOfActor;
        moviesOfActor.emplace_front(m);
        movieList[m->getTitleYear()] = moviesOfActor;
    }
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

// add to main map
void Actor::addActor(Actor *a)
{
    //allActors.insert(a.name, a);
}

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

    // actor found: traverse thorugh the map of movies and find coactors
    map<short int, forward_list<Movie *>>::iterator it; //iterator

    // traversing through the map of movies of given actor (movieList)
    for (it = this->movieList.begin(); it != this->movieList.end(); it++)
    {
        cout << "----------- " << it->first << " -----------" << endl; //  year
        forward_list<Movie *> movies = it->second;                     // all movies of certain year
        for (auto it = movies.begin(); it != movies.end(); ++it)       // traverse thorugh the forward_list of movies
        {
            Movie *m = (*it);              // pointer to movie
            cout << m->getTitle() << endl; // name of movie
        }
    }
    cout << endl;
}

void Actor::display()
{
    cout << "Name: " << name << endl;
    cout << "FB Likes: " << getLikes() << endl;
    cout << "Total Movies: " << getCountOfMovies() << endl;
    displayAllMovies();
}

// methods related to actors specified in document provided
Actor *Actor::searchActor(string name, unordered_map<string, ActorAVL> allActors, bool display)
{
    Actor *actor = NULL;
    // finding actor by frst two letters of name in map of allActors, returns an avl of pointers to Actor

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
    forward_list<Actor *> coactorsList;
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
            Movie *m = (*it);                           // pointer to movie

            // finding coactors
            Actor **coActors = (*it)->getActor(); // all actors of this movie
            for (Actor **i = coActors; i < coActors + 3; i++)
            {
                if ((*(i))->getName() != actor->getName())
                    {
                        coactorsList.emplace_front(*(i));
                    }

            }

            // cout << (*(coActors))->getName() << ", ";
            // cout << (*(coActors + 1))->getName() << ", ";
            // cout << (*(coActors + 2))->getName() << endl <<endl;

            // for (Actor **a = coActors ;a<a+1; a++) //traversing through three actors of every movie
            // {
            //     cout << "for "<<endl;
            //     Actor *coAct = (*a);
            //     if (coAct->getName() != actor->getName()) // coActor is not the one we are searching coactors for
            //     {
            //         cout << coAct->getName() <<"coac"<< endl; //display names of coactor
            //         coactorsList.emplace_front(coAct);
            //     }
            // }
        }
    }

    return coactorsList;
}

//second method of the list
void Actor::displayCoActors(string name, unordered_map<string, ActorAVL> allActors)
{
    // forward_list<Actor *> coactorsList;
    Actor *actor = searchActor(name, allActors, false); // finding the actor in allActors map

    // actor not found
    if (!actor)
    {
        cout << "Actor not found" << endl;
        // return coactorsList;
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

            for (Actor **i = coActors; i < coActors + 3; i++)
            {
                if ((*(i))->getName() != actor->getName())
                    {
                        cout << (*(i))->getName() << ", ";
                        // coactorsList.emplace_front(*(i));
                    }

            }
            cout << endl
                 << endl;

            // cout << (*(coActors))->getName() << ", ";
            // cout << (*(coActors + 1))->getName() << ", ";
            // cout << (*(coActors + 2))->getName() << endl <<endl;

            // for (Actor **a = coActors ;a<a+1; a++) //traversing through three actors of every movie
            // {
            //     cout << "for "<<endl;
            //     Actor *coAct = (*a);
            //     if (coAct->getName() != actor->getName()) // coActor is not the one we are searching coactors for
            //     {
            //         cout << coAct->getName() <<"coac"<< endl; //display names of coactor
            //         coactorsList.emplace_front(coAct);
            //     }
            // }
        }
    }

    // return coactorsList;
}

void Actor::getUniqueCoActors(string name, unordered_map<string, ActorAVL> allActors)
{
    // implementaton using unordered map of coactors having movies as value
    // 1. find coactors
    // 2. insert name of coactor in map as a key, if not present
    // 3. add movie to the forward_list of movies coresponding to this coactor (value of map)

    Actor *actor = searchActor(name, allActors, false); // finding the actor in allActors map

    // actor not found
    if (!actor)
    {
        cout << "Actor not found" << endl;
        return;
    }
    // map for storing coactors and corresponsing movies
    unordered_map<string, forward_list<string>> coactorsMap; // key: name of coactor, value: title of movie

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
            Actor **coActors = (*it)->getActor();         // all actors of this movie
            for (Actor **a = coActors; a < coActors + 3; a++) //traversing through three actors of every movie
            {
                Actor *coAct = (*a);
                if (coAct->getName() != actor->getName()) // coActor is not the one we are searching coactors for
                {
                    forward_list<string> movies = coactorsMap[coAct->getName()]; // get key
                    movies.emplace_front(m->getTitle());                                      // insert to movies
                    coactorsMap[coAct->getName()] = movies;                       // insert to map
                    // if(coactorsMap.find(coAct->getName()) == coactorsMap.end()) // coactor alredy not present
                    // {
                    //     forward_list <string> mov;
                    //     mov.emplace_front(m->getTitle());
                    //     coactorsMap[coAct->getName()] = mov;
                    // }
                    // else{
                    //     coactorsMap.at(coAct->getName()).emplace_front(m->getTitle());
                    // }
                }
            }
        }
    }

    // display
    unordered_map<string, forward_list<string>>::iterator itCoactors; //iterator

    // traversing through the map of coactors
    for (itCoactors = coactorsMap.begin(); itCoactors != coactorsMap.end(); itCoactors++)
    {
        cout << itCoactors->first  <<endl; // name of coactor
        cout << "Movies: ";
        forward_list<string> movies = itCoactors->second;                               // all common movies
        for (auto mov = movies.begin(); mov != movies.end(); ++mov) // traverse thorugh the forward_list of movies
        {
            cout << (*mov) << "\t "; //print movie title
        }
        cout << endl<<endl;
    }
}

bool inCoactors(forward_list<Actor *> coactors, string name)
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
    // get coactors of actor
    // get coactors of coactors(subactors)
    forward_list<Actor *> coactors = getCoActors(name, allActors);
    ActorAVL allCoactor;
    if (!coactors.empty())
    {
        for (auto it1 = coactors.begin(); it1 != coactors.end(); ++it1) // traverse thorugh the forward_list of movies
        {
            forward_list<Actor *> subCoactors = getCoActors((*it1)->name, allActors);
            for (auto it2 = subCoactors.begin(); it2 != subCoactors.end(); ++it2) // traverse thorugh the forward_list of movies
            {
                Actor *subActor = *it2;
                // add to avl if subactor is not coactor of actor and actor itself
                if (subActor->getName() != name && !inCoactors(coactors, subActor->getName()))
                    allCoactor.insert(subActor);
            }
        }

        allCoactor.traverse();
    }
}

bool Actor::isCoActor(string nameA, string nameB, unordered_map<string, ActorAVL> allActors)
{
    forward_list<Actor *> coactors = getCoActors(nameA, allActors); //coactors of A
    if (!coactors.empty())
    {
        // if b is present in coactors then A and B are coactors
        for (auto it = coactors.begin(); it != coactors.end(); ++it) // traverse thorugh the forward_list of movies
        {
            if ((*it)->getName() == nameB) // B is present in list
                return true;
        }
    }
    return false;
}

#ifndef ACTOR_H
#define ACTOR_H

#include <iostream>
#include <string>
#include <forward_list>
#include <map>
#include <unordered_map>
#include "Movie.h"
#include "AVL.h"

// forward declaration
class Movie;
class ActorAVL;

using namespace std;
class Actor
{
public:
    string name;
    int fbLikesForActor;
    map<string, forward_list<Movie *>> movieList; //sorted chronologically key is year

    // static unordered_map<string, ActorAVL> allActors; // avl sorted on actor name

    //constructor
    Actor();
    Actor(string);
    Actor(string, int);

    //setters
    void setName(string);
    void setLikes(int);
    void addMovie(Movie *);

    //getters
    string getName();
    int getLikes();
    map<string, forward_list<Movie *>> getMovie();
    int getCountOfMovies();

    // add to main map
    void addActor(Actor *);

    // helper functions
    void displayAllMovies();
    void display();


    // methods related to actors specified in document provided
    static Actor *searchActor(string, unordered_map<string, ActorAVL>, bool = false);
    static void displayActorProfile(Actor *);
    forward_list<Actor*> getCoActors(string, unordered_map<string, ActorAVL>);
    void getUniqueCoActors(string, unordered_map<string, ActorAVL> );
    void getCoActorsOfCoActors(string, unordered_map<string, ActorAVL>);
    bool isCoActor(string, string, unordered_map<string, ActorAVL>);
};

#endif
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
    map<short int, forward_list<Movie *>> movieList; //sorted chronologically key is year

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
    map<short int, forward_list<Movie *>> getMovie();
    int getCountOfMovies();

    // helper functions
    void displayAllMovies();
    void display();
    static void displayAllActors(unordered_map<string, ActorAVL>);


    // methods related to actors specified in document provided
    static Actor *searchActor(string, unordered_map<string, ActorAVL>, bool = false);
    static forward_list<Actor *> getCoActors(string, unordered_map<string, ActorAVL>);
    static void displayCoActors(string, unordered_map<string, ActorAVL>);
    static void getUniqueCoActors(string, unordered_map<string, ActorAVL>);
    static void getCoActorsOfCoActors(string, unordered_map<string, ActorAVL>);
    static bool isCoActor(string, string, unordered_map<string, ActorAVL>);
};

#endif
#ifndef ACTOR_H
#define ACTOR_H

#include <iostream>
#include <string>
#include <forward_list>
#include <map>
#include "Movie.h"

class Movie;

using namespace std;
class Actor
{
public:
    string name;
    int fbLikesForActor;
    forward_list<Movie *> movieList;
    static map<string, Actor *> allActors;

    //constructor
    Actor(string);
    Actor(string, int);

    //setters
    void setName(string);
    void setLikes(int);
    void addToMovieMap(Movie *);

    //getters
    string getName();
    int getLikes();
    forward_list<Movie *> getMovie();
    void addActor(Actor *);

    // methods related to actors specified in document provided
    static Actor *searchActor(string, bool);
    static void displayActorProfile(Actor *);
    void getCoActors(string);
    void getUniqueCoActors(string);
    void getCoActorsOfCoActors(string);
    bool isCoActor(string, string);
};

#endif
#ifndef DIRECTOR_H
#define DIRECTOR_H

#include <iostream>
#include <string>
#include <forward_list>
#include <map>
#include "Movie.h"

// forward declaration
class Movie;

using namespace std;
class Director
{
public:
    string name;
    int fbLikesForDirector;
    forward_list<Movie *> movieList;

    static map<string, Director *> allDirectors; //to be converted to AVL

    // constructor
    Director();
    Director(string);
    Director(string, int);

    // setters
    void setName(string);
    void setLikes(int);
    void addMovie(Movie *);

    // getters
    string getName();
    int getLikes();
    forward_list<Movie*> getMovies();

    // add to main map of directors
    void addDirector(Director*);

    // methods related to director
    static Director *searchDir(string );
    void getDirectorOfGenre(string );
};

#endif
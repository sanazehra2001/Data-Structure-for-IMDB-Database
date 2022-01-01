#ifndef DIRECTOR_H
#define DIRECTOR_H

#include <iostream>
#include <string>
#include <forward_list>
#include <map>
#include "Movie.h"

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
    Director(string, int);

    // setters
    void setName(string);
    void setLikes(int);
    void addToMovieMap(Movie *);

    // getters
    string getName();
    int getLikes();
    forward_list<Movie> *getMovies();

    void addDirector(Director*);

    // methods related to director
    Director *searchDir(string );
    void getDirectorOfGenre(string );
};

#endif
#ifndef DIRECTOR_H
#define DIRECTOR_H

#include <iostream>
#include <string>
#include <forward_list>
#include <map>
#include "Movie.h"
#include <unordered_map>
#include "AVL.h"
#include "Genre.cpp"

// forward declaration
class Movie;
class DirectorAVL;
//enum Genre;
using namespace std;

class Director
{
public:
    string name;
    int fbLikesForDirector;
    forward_list<Movie *> movieList;

    //static unordered_map<string, DirectorAVL> allDirectors;  //avl sorted on name

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
    void static addDirector(Director*);

    // methods related to director
    static Director *searchDir(string, unordered_map<string, DirectorAVL>, bool = false);
    static void getDirectorOfGenre(string,unordered_map<Genre, map<string, forward_list<Movie *>, greater<string>>>);

    //utitlity methods
    void displayDirector();
    void displayMovies();
};

#endif
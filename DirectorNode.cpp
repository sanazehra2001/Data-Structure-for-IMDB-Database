#ifndef DirectorNode_H
#define DirectorNode_H

#include <iostream>
#include <string>
#include <map>
#include <forward_list>
//#include "AVL.cpp"
//#include "Movie.cpp"

using namespace std;

class Movie;

class DirectorNode
{
    string name;
    int fbLikesForDirector;
    forward_list<Movie *> movieList;


public:
    static map<string, DirectorNode *> allDirectors;

    DirectorNode(string n, int likes)
    {
        name = n;
        fbLikesForDirector = likes;
    }

    //getters
    string getName()
    {
        return name;
    }

    static DirectorNode *searchDir(string name) {}
    void getDirectorOfGenre(string genre) {}
};

#endif
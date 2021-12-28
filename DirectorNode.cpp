#include <iostream>
#include <string>
#include <map>
#include <forward_list>
#include "AVL.cpp"
#include "Movie.cpp"

using namespace std;

class DirectorNode{
    string name;
    int fbLikesForDirector;
    forward_list<Movie*> movieList;

    // static map<string, AVL<DirectorNode* >> allDirectors;

public:
    DirectorNode(string n, int likes){
        name = n;
        fbLikesForDirector = likes;
    }

    //getters
    string getName(){
        return name;
    }

    static DirectorNode* searchDir(string name){}                  
    void getDirectorOfGenre(string genre){}

};
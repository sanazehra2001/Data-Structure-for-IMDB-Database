#include <iostream>
#include <string>
#include <forward_list>
#include "MovieNode.cpp"
#include <map>
#include <string>

using namespace std;

class ActorNode{
    
    static map<string, AVL<ActorNode*>> allActors;  //convert to avl

    string name;
    int fbLikesForActor;
    forward_list<Movie*> movieList; // convert it to map
    

// count of list of movies

public:
    ActorNode(string name){}
    ActorNode(string name, int fbLikesForActor){}

    //for adding to avl tree
    void addActor(ActorNode* a){
        //allActors.insert(a.name, a);
    }

    void addToMovieMap(Movie* m){}

    //for first method in the list
    static ActorNode* searchActor(string name, bool display){
        //return pointer if found
        //return null if not
    }

    void static displayActorProfile(ActorNode* a){}

    //second method of the list
    void getCoActors(string name){}


    void getUniqueCoActors(string name){
        //create AVL of unique coactors
    }       

    
    void getCoActorsOfCoActors(string name){}   // return type has to be decided
    bool isCoActor(string nameA, string nameB){} 
};
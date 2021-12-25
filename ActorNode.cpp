#include <iostream>
#include <string>
#include <forward_list>
#include "MovieNode.cpp"

using namespace std;

class ActorNode{
    string name;
    int fbLikesForActor;

public:
    ActorNode(string name){}
    ActorNode(string name, int fbLikesForActor){}

    void searchActor(string name){}                  // return type has to be decided
    void getCoActors(string name){}             // return type has to be decided
    void getUniqueCoActors(string name){}       // return type has to be decided
    void getCoActorsOfCoActors(string name){}   // return type has to be decided
    bool isCoActor(string nameA, string nameB){} 
};
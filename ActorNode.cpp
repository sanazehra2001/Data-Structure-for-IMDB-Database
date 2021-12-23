#include <iostream>
#include <string>
using namespace std;

class ActorNode{

public:
    ActorNode(){}

    void searchActor(string name){}                  // return type has to be decided
    void getCoActors(string name){}             // return type has to be decided
    void getUniqueCoActors(string name){}       // return type has to be decided
    void getCoActorsOfCoActors(string name){}   // return type has to be decided
    bool isCoActor(string nameA, string nameB){} 
};
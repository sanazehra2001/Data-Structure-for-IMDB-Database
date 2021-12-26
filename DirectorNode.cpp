#include <iostream>
#include <string>
#include <map>
using namespace std;

class DirectorNode{
    string name;
    int fbLikesForDirector;    

    static map<string, AVL<DirectorNode* >> allDirectors;

public:
    DirectorNode(){}

    void searchDir(string name){}                  // return type has to be decided
    void getDirectorOfGenre(string genre){}     // return type has to be decided

};
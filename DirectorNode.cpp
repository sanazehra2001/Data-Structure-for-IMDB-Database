#include <iostream>
#include <string>
#include <map>
using namespace std;

class DirectorNode{
    string name;
    int fbLikesForDirector;    

    static map<string, AVL<DirectorNode* >> allDirectors;

public:
    DirectorNode(string n, int likes){
        name = n;
        fbLikesForDirector = likes;
    }

    void searchDir(string name){}                  
    void getDirectorOfGenre(string genre){}

};
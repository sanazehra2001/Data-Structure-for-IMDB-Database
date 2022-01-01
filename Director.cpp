#include "Director.h"

Director::Director()
{
    name = "";
    fbLikesForDirector = 0;
}

Director::Director(string n, int likes)
{
    name = n;
    fbLikesForDirector = likes;
}

//getters
string Director::getName()
{
    return name;
}

void Director::setName(string n)
{
    name = n;
}

Director *Director::searchDir(string name) {}
void Director::getDirectorOfGenre(string genre) {}

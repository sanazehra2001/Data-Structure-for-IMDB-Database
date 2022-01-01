#include <string>
using namespace std;

enum Genre
{
    Action,
    Adventure,
    Animation,
    Biography,
    Comedy,
    Documentary,
    Drama,
    Fantasy,
    Family,
    History,
    Horror,
    Musical,
    Mystery,
    Romance,
    SciFi,
    Sport,
    Thriller,
    Western,
    War
};

Genre convert(string g)
{
    if (g.compare("Action"))
        return Action;
    else if (g.compare("Adventure"))
        return Adventure;
    else if (g.compare("Animation"))
        return Animation;
    else if (g.compare("Biography"))
        return Biography;
    else if (g.compare("Comedy"))
        return Comedy;
    else if (g.compare("Documentary"))
        return Documentary;
    else if (g.compare("Drama"))
        return Drama;
    else if (g.compare("Fantasy"))
        return Fantasy;
    else if (g.compare("Family"))
        return Family;
    else if (g.compare("History"))
        return History;
    else if (g.compare("Horror"))
        return Horror;
    else if (g.compare("Musical"))
        return Musical;
    else if (g.compare("Mystery"))
        return Mystery;
    else if (g.compare("Romance"))
        return Romance;
    else if (g.compare("SciFi"))
        return SciFi;
    else if (g.compare("Sport"))
        return Sport;
    else if (g.compare("Thriller"))
        return Thriller;
    else if (g.compare("Western"))
        return Western;
    else if (g.compare("War"))
        return War;
}
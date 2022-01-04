#ifndef GENRE_CPP
#define GENRE_CPP

#include <string>
using namespace std;

enum Genre
{
    Action,
    Adventure,
    Animation,
    Biography,
    Comedy,
    Crime,
    Documentary,
    Drama,
    Fantasy,
    Family,
    FilmNoir,
    GameShow,
    History,
    Horror,
    Music,
    Musical,
    Mystery,
    News,
    RealityTV,
    Romance,
    SciFi,
    Short,
    Sport,
    Thriller,
    Western,
    War
};

Genre convert(string g)
{
    if (g == "Action")
        return Action;
    else if (g == "Adventure")
        return Adventure;
    else if (g == "Animation")
        return Animation;
    else if (g == "Biography")
        return Biography;
    else if (g == "Crime")
        return Crime;
    else if (g == "Comedy")
        return Comedy;
    else if (g == "Documentary")
        return Documentary;
    else if (g == "Drama")
        return Drama;
    else if (g == "Fantasy")
        return Fantasy;
    else if (g == "Family")
        return Family;
    else if (g == "Film-Noir")
        return FilmNoir;
    else if (g == "Game-Show")
        return GameShow;    
    else if (g == "History")
        return History;
    else if (g == "Horror")
        return Horror;
    else if (g == "Music")
        return Music;
    else if (g == "Musical")
        return Musical;
    else if (g == "Mystery")
        return Mystery;
    else if (g == "News")
        return News;
    else if (g == "Reality-TV")
        return RealityTV;
    else if (g == "Romance")
        return Romance;
    else if (g == "Sci-Fi")
        return SciFi;
    else if (g == "Short")
        return Short;
    else if (g == "Sport")
        return Sport;
    else if (g == "Thriller")
        return Thriller;
    else if (g == "Western")
        return Western;
    else if (g == "War")
        return War;
}

string toString(Genre g)
{
    switch (g)
    {
    case Action:
        return "Action";
    case Adventure:
        return "Adventure";
    case Animation:
        return "Animation";
    case Biography:
        return "Biography";
    case Crime:
        return "Crime";
    case Comedy:
        return "Comedy";
    case Documentary:
        return "Documentary";
    case Drama:
        return "Drama";
    case Fantasy:
        return "Fantasy";
    case Family:
        return "Family";
    case FilmNoir:
        return "Film-Noir";
    case GameShow:
        return "Game-Show";
    case History:
        return "History";
    case Horror:
        return "Horror";
    case Music:
        return "Music";
    case Musical:
        return "Musical";
    case Mystery:
        return "Mystery";
    case News:
        return "News";
    case RealityTV:
        return "Reality-TV";
    case Romance:
        return "Romance";
    case SciFi:
        return "Sci-Fi";
    case Short:
        return "Short";
    case Sport:
        return "Sport";
    case Thriller:
        return "Thriller";
    case Western:
        return "Western";
    case War:
        return "War";
    }
}

#endif
#include <iostream>
#include <string>
#include "DirectorNode.cpp"
#include "ActorNode.cpp"
#include "Genre.cpp"
#include <list>
#include <string>
#include "Color.cpp"
#include "AVL.cpp"
#include <map>

using namespace std;

class Movie
{

    string title;
    Genre genre;
    short int titleYear;
    float imdbScore;
    DirectorNode *director;
    int numOfCriticReviews;
    int duration;
    ActorNode *actor; // data structure to be decided    //1-M
    unsigned long int gross;
    unsigned int numOfVotes;
    int fbLikesForCast;
    short int faceNumInPoster;
    list<string> keywords; 
    string imdbLink;
    int numOfReviews;
    string language;
    string country;
    string contentRating; 
    unsigned long int budget;
    float aspectRatio;
    int fbLikesForMovie;
    MovieColor color;

    // priority to be implemented
    static map<string, AVL<Movie*>> moviesByTitle; 
    static map<string, AVL<Movie*>> moviesByYear;
    static map<Genre, AVL<Movie*>> moviesByGenre;
    

public:
    //return type of all of these methods have to be decided depending whether any of these functions
    //has to be used by somewhere else
    void searchMovie(string title) {} //not necessarily complete
    void getMoviesOfYear(short int year) {}
    void printMoviesChronologically(bool asc) {}
    void getMoviesOfGenre(string genre) {}
    void printMoviesByRating() {}
    void printMoviesByRating(string genre) {}
};
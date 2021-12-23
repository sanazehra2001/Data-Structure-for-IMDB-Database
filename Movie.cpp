#include <iostream>
#include <string>
using namespace std;

class Movie {

    string title;
    //genre                             data structure to be decided    //1-M   //enums
    short int titleYear;
    float imdbScore;
    string directorName;
    int fbLikesForDirector;
    int numOfCriticReviews;
    int duration;
    //actor name and facebook likes     data structure to be decided    //1-M
    unsigned long int gross;
    unsigned int numOfVotes;
    int fbLikesForCast;
    short int faceNumInPoster;
    //plot keywords                     data structure to be decided    //1-M   //enums
    string imdbLink;
    int numOfReviews;
    string language;
    string country;
    string contentRating;               //can be set as enum
    unsigned long int budget;
    float aspectRatio;
    int fbLikesForMovie;
    string colour;                      //can be set as enum


public:
    //return type of all of these methods have to be decided depending whether any of these functions
    //has to be used by somewhere else
    void searchMovie(string title){}    //not necessarily complete
    void getMoviesOfYear(short int year){}
    void printMoviesChronologically(bool asc){}
    void getMoviesOfGenre(string genre){}
    void printMoviesByRating(){}
    void printMoviesByRating(string genre){}
};
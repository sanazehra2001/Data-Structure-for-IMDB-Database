#include <iostream>
#include <string>
#include "DirectorNode.cpp"
#include "ActorNode.cpp"
//#include "Genre.cpp"
//#include "Colour.cpp"

using namespace std;

class Movie {

    string title;
    forward_list <Genre> genre;
    short int titleYear;
    float imdbScore;
    DirectorNode* director;
    int numOfCriticReviews;
    int duration;
    ActorNode* actor;                    // data structure to be decided    //1-M
    unsigned long int gross;
    unsigned int numOfVotes;
    int fbLikesForCast;
    short int faceNumInPoster;
    forward_list<string> plotKeywords;
    string imdbLink;
    int numOfReviews;
    string language;
    string country;
    string contentRating;
    unsigned long int budget;
    float aspectRatio;
    int fbLikesForMovie;
    //Colour colour;


public:
    // setters
    void setTitle(string t){
        title = t;
    }

    void setGenre(string g){
        genre.emplace_front(g);        
    }

    void setTitleYear(short int year){
        titleYear = year;
    }

    void setImdbScore(float score){
        imdbScore = score;
    }
    



    // methods
    void searchMovie(string title){}    //not necessarily complete
    void getMoviesOfYear(short int year){}
    void printMoviesChronologically(bool asc){}
    void getMoviesOfGenre(string genre){}
    void printMoviesByRating(){}
    void printMoviesByRating(string genre){}
};
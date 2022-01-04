#ifndef MOVIE_H
#define MOVIE_H

#include <iostream>
#include <string>
#include "Actor.h"
#include "Director.h"
#include "Genre.cpp"
#include "MovieColor.cpp"
#include "AVL.h"
#include <unordered_map>

//forward declarations
class Actor;
class Director;

using namespace std;
class Movie
{
    string title;
    forward_list<Genre> genre;
    short int titleYear;
    float imdbScore;
    Director *director;
    int numOfCriticReviews;
    int duration;
    Actor *actors[3];
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
    unsigned long long int budget;
    float aspectRatio;
    int fbLikesForMovie;
    MovieColor color;

    // static map<string, MovieAVL> moviesByTitle;                                                     // avl sorted by title
    // static map<short int, forward_list<Movie *>> moviesByYear;                                      // keys sorted by year
    // static map<string, forward_list<Movie *>, greater<string>> moviesByRating;                      // keys sorted by rating
    // static unordered_map<Genre, map<string, forward_list<Movie *>, greater<string>>> moviesByGenre; // nested maps' keys sorted on rating

public:
    // setters
    void setTitle(string);
    void setGenre(string);
    void setTitleYear(short int);
    void setImdbScore(float);
    void setDirector(Director *);
    void setNumOfCriticReviews(int);
    void setDuration(int);
    void setActor(Actor **);
    void setGross(unsigned long int);
    void setNumOfVotes(unsigned int);
    void setFbLikesForCast(int);
    void setFaceNumInPoster(short int);
    void setPlotKeywords(string);
    void setImdbLink(string);
    void setNumOfReviews(int);
    void setLanguage(string);
    void setCountry(string);
    void setContentRating(string);
    void setBudget(unsigned long long int);
    void setAspectRatio(float);
    void setFbLikesForMovie(int);
    void setColor(string);

    //getters
    string getTitle();
    forward_list<Genre> getGenre();
    short int getTitleYear();
    float getImdbScore();
    Director *getDirector();
    int getNumOfCriticReviews();
    int getDuration();
    Actor ** getActor();
    unsigned long int getGross();
    unsigned int getNumOfVotes();
    int getFbLikesForCast();
    short int getFaceNumInPoster();
    forward_list<string> getPlotKeywords();
    string getImdbLink();
    int getNumOfReviews();
    string getLanguage();
    string getCountry();
    string getContentRating();
    unsigned long long int getBudget();
    float getAspectRatio();
    int getFbLikesForMovie();
    string getColor();

    //display functions
    void displayKeywords();
    void displayActors();
    void displayGenre();
    void display();
    void displayDirector();

    //helper
    static string formatStr(string);

    static Movie *searchMovieByTitle(string , map<string, MovieAVL>);
    static Movie *searchMovieByYear(Movie *, map<short int, forward_list<Movie *>>);
    static Movie *searchMovieByRating(Movie* , map<string, forward_list<Movie *>, greater<string>>);
    static Movie *searchMovieByGenre(Movie *, Genre, unordered_map<Genre, map<string, forward_list<Movie *>, greater<string>>>);

    static void searchMovie(string, map<string, MovieAVL>); //not necessarily complete
    static void getMoviesOfYear(short int, map<short int, forward_list<Movie *>>);
    static void printMoviesChronologically(bool, map<short int, forward_list<Movie *>>);
    static void getMoviesOfGenre(string, unordered_map<Genre, map<string, forward_list<Movie *>, greater<string>>>);
    static void printMoviesByRating(map<string, forward_list<Movie *>, greater<string>>);
};

#endif
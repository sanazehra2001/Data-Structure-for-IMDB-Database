#ifndef MOVIE_H
#define MOVIE_H

#include <iostream>
#include <string>
#include "Actor.h"
#include "Director.h"
#include "Genre.cpp"
#include "MovieColor.cpp"

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
    unsigned long int budget;
    float aspectRatio;
    int fbLikesForMovie;
    MovieColor color;

    // priority to be implemented
    // static map<string, AVL<Movie *>> moviesByTitle;
    // static map<string, AVL<Movie *>> moviesByYear;
    // static map<Genre, AVL<Movie *>> moviesByGenre;

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
    void setBudget(unsigned long int);
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
    Actor **getActor();
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
    unsigned long int getBudget();
    float getAspectRatio();
    int getFbLikesForMovie();
    MovieColor getColor();

    // methods
    void searchMovie(string); //not necessarily complete
    void getMoviesOfYear(short int);
    void printMoviesChronologically(bool);
    void getMoviesOfGenre(string);
    void printMoviesByRating();
    void printMoviesByRating(string);
};

#endif
#include <iostream>
#include <string>
#include "DirectorNode.cpp"
#include "ActorNode.cpp"
#include "Genre.cpp"
#include <list>
#include <string>
#include "MovieColor.cpp"
// #include "AVL.cpp"
#include <map>

using namespace std;

class Movie
{
    string title;
    forward_list<Genre> genre;
    short int titleYear;
    float imdbScore;
    DirectorNode *director;
    int numOfCriticReviews;
    int duration;
    ActorNode* actors[3];
    unsigned long int gross;
    unsigned int numOfVotes;
    int fbLikesForCast;
    short int faceNumInPoster;
    forward_list plotKeywords;
    string imdbLink;
    int numOfReviews;
    string language;
    string country;
    string contentRating;
    unsigned long int budget;
    float aspectRatio;
    int fbLikesForMovie;
    bool color;

    // priority to be implemented
    // static map<string, AVL<Movie *>> moviesByTitle;
    // static map<string, AVL<Movie *>> moviesByYear;
    // static map<Genre, AVL<Movie *>> moviesByGenre;

public:
    // setters
    void setTitle(string t){
        this->title = t;
    }

    void setGenre(string g){
        genre.emplace_front(convert(g));
    }

    void setTitleYear(short int year){
        titleYear = year;
    }

    void setImdbScore(float score){
        imdbScore = score;
    }

    void setDirectorNode(DirectorNode *d){
        director = d;
    }

    void setNumOfCriticReviews(int reviews){
        numOfCriticReviews = reviews;
    }

    void setDuration(int d){
        duration = d;
    }

    void setActor(ActorNode *a){
        actor.emplace_front(a);
    }

    void setGross(unsigned long int g){
        gross = g;
    }

    void setNumOfVotes(unsigned int votes){
        numOfVotes = votes;
    }

    void setFbLikesForCast(int likes){
        fbLikesForCast = likes;
    }

    void setFaceNumInPoster(short int faces){
        faceNumInPoster = faces;
    }
    
    void setPlotKeywords(string word){
        plotKeywords.emplace_front(word);
    }

    void setImdbLink(string link){
        imdbLink = link;
    }

    void setNumOfReviews(int reviews){
        numOfReviews = reviews;
    }
    
    void setLanguage(string lang){
        language = lang;
    }

    void setCountry(string c){
        country = c;
    }

    void setContentRating(string rating){
        contentRating = rating;
    }

    void setBudget(unsigned long int bud){
        budget = bud;
    }

    void setAspectRatio(float ratio){
        aspectRatio = ratio;
    }

    void setFbLikesForMovie(int likes){
        fbLikesForMovie = likes;
    }

    void setColor(bool col){
        color = col;
    }

    string getTitle(){
        return title;
    }

    short int getTitleYear(){
        return titleYear;
    };

    string getContentRating(){
        return contentRating;
    }



    // methods
    void searchMovie(string title) {} //not necessarily complete
    void getMoviesOfYear(short int year) {}
    void printMoviesChronologically(bool asc) {}
    void getMoviesOfGenre(string genre) {}
    void printMoviesByRating() {}
    void printMoviesByRating(string genre) {}
};
#include "Movie.h"

void Movie::setTitle(string t)
{
    title = t;
}

void Movie::setGenre(string g)
{
    genre.emplace_front(convert(g));
}

void Movie::setTitleYear(short int year)
{
    titleYear = year;
}

void Movie::setImdbScore(float score)
{
    imdbScore = score;
}

void Movie::setDirector(Director *d)
{
    director = d;
}

void Movie::setNumOfCriticReviews(int reviews)
{
    numOfCriticReviews = reviews;
}

void Movie::setDuration(int d)
{
    duration = d;
}

void Movie::setActor(Actor *a[3])
{
    for (int i = 0; i < 3; i++)
    {
        actors[i] = a[i];
    }
}

void Movie::setGross(unsigned long int g)
{
    gross = g;
}

void Movie::setNumOfVotes(unsigned int votes)
{
    numOfVotes = votes;
}

void Movie::setFbLikesForCast(int likes)
{
    fbLikesForCast = likes;
}

void Movie::setFaceNumInPoster(short int faces)
{
    faceNumInPoster = faces;
}

void Movie::setPlotKeywords(string word)
{
    plotKeywords.emplace_front(word);
}

void Movie::setImdbLink(string link)
{
    imdbLink = link;
}

void Movie::setNumOfReviews(int reviews)
{
    numOfReviews = reviews;
}

void Movie::setLanguage(string lang)
{
    language = lang;
}

void Movie::setCountry(string c)
{
    country = c;
}

void Movie::setContentRating(string rating)
{
    contentRating = rating;
}

void Movie::setBudget(unsigned long int bud)
{
    budget = bud;
}

void Movie::setAspectRatio(float ratio)
{
    aspectRatio = ratio;
}

void Movie::setFbLikesForMovie(int likes)
{
    fbLikesForMovie = likes;
}

void Movie::setColor(string col)
{
    // color = MovieColor.convert(col);
}

//getters
 string getTitle();
    forward_list<Genre> Movie::getGenre(){
        return genre;
    }
    short int Movie::getTitleYear(){
        return titleYear;
    }
    float Movie::getImdbScore(){
        return imdbScore;
    }
    Director *Movie::getDirector(){
        return director;
    }
    int Movie::getNumOfCriticReviews(){
        return numOfCriticReviews;
    }
    int Movie::getDuration(){
        return duration;
    }
    Actor **Movie::getActor(){
        return actors;
    }
    unsigned long int Movie::getGross(){
        return gross;
    }
    unsigned int Movie::getNumOfVotes(){
        return numOfVotes;
    }
    int Movie::getFbLikesForCast(){
        return fbLikesForCast;
    }

    short int Movie::getFaceNumInPoster(){
        return faceNumInPoster;
    }

    forward_list<string> Movie::getPlotKeywords(){
        return plotKeywords;
    }
    string Movie::getImdbLink(){
        return imdbLink;
    }
    int Movie::getNumOfReviews(){
        return numOfReviews;
    }
    string Movie::getLanguage(){
        return language;
    }
    string Movie::getCountry(){
        return country;
    }
    string Movie::getContentRating(){
        return contentRating;
    }
    unsigned long int Movie::getBudget(){
        return budget;
    }
    float Movie::getAspectRatio(){
        return aspectRatio;
    }
    int Movie::getFbLikesForMovie(){
        return fbLikesForMovie;
    }
    MovieColor Movie::getColor(){
        return color;
    }


// methods
void Movie::searchMovie(string title) {} //not necessarily complete
void Movie::getMoviesOfYear(short int year) {}
void Movie::printMoviesChronologically(bool asc) {}
void Movie::getMoviesOfGenre(string genre) {}
void Movie::printMoviesByRating() {}
void Movie::printMoviesByRating(string genre) {}

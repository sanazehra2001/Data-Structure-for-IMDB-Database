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

void Movie::setColor(bool col)
{
    color = col;
}

string Movie::getTitle()
{
    return title;
}

short int Movie::getTitleYear()
{
    return titleYear;
};

string Movie::getContentRating()
{
    return contentRating;
}

// methods
void Movie::searchMovie(string title) {} //not necessarily complete
void Movie::getMoviesOfYear(short int year) {}
void Movie::printMoviesChronologically(bool asc) {}
void Movie::getMoviesOfGenre(string genre) {}
void Movie::printMoviesByRating() {}
void Movie::printMoviesByRating(string genre) {}

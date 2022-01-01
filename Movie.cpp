#include "Movie.h"
#include <cstring>

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
forward_list<Genre> Movie::getGenre()
{
    return genre;
}
short int Movie::getTitleYear()
{
    return titleYear;
}
float Movie::getImdbScore()
{
    return imdbScore;
}
Director *Movie::getDirector()
{
    return director;
}
int Movie::getNumOfCriticReviews()
{
    return numOfCriticReviews;
}
int Movie::getDuration()
{
    return duration;
}
Actor **Movie::getActor()
{
    return actors;
}
unsigned long int Movie::getGross()
{
    return gross;
}
unsigned int Movie::getNumOfVotes()
{
    return numOfVotes;
}
int Movie::getFbLikesForCast()
{
    return fbLikesForCast;
}

short int Movie::getFaceNumInPoster()
{
    return faceNumInPoster;
}

forward_list<string> Movie::getPlotKeywords()
{
    return plotKeywords;
}
string Movie::getImdbLink()
{
    return imdbLink;
}
int Movie::getNumOfReviews()
{
    return numOfReviews;
}
string Movie::getLanguage()
{
    return language;
}
string Movie::getCountry()
{
    return country;
}
string Movie::getContentRating()
{
    return contentRating;
}
unsigned long int Movie::getBudget()
{
    return budget;
}
float Movie::getAspectRatio()
{
    return aspectRatio;
}
int Movie::getFbLikesForMovie()
{
    return fbLikesForMovie;
}
MovieColor Movie::getColor()
{
    return color;
}

// methods
// displays contents of movie
void Movie::display()
{
}

// search movie by title not necessarily complete
void Movie::searchMovie(string title)
{
    // case1: string is of length one
    if (title.length() == 1)
    {
        for (auto it = moviesByTitle.lower_bound(string(1, toupper(title[0])));
             it != moviesByTitle.upper_bound(getNextLetter(title[0])); it++)
        {
            MovieAVL avl = it->second;
            avl.traverse();
        }
    }

    // case2: string of length two
    else if (title.length() == 2)
    {
        MovieAVL avl = moviesByTitle[title];
        if (avl.isEmpty())
            cout << "No matching movie" << endl;
        else
            avl.traverse();
    }

    // case3: string of length greater than 2
    else
    {
        MovieAVL avl = moviesByTitle[title]; // get avl of key
        if (avl.isEmpty())                   // if key is not present
            cout << "No matching movie." << endl;
        else
        {
            forward_list<Movie *> moviesOfKey = avl.search(title); // search movies that have title string in their title
            if (moviesOfKey.empty())                               // if no such movie is found
            {
                cout << "No matching movie." << endl;
            }
            else
            { // if movies are found, iterate over list of movies
                for (auto it = moviesOfKey.begin(); it != moviesOfKey.end(); ++it)
                    (*it)->display();
            }
        }
    }
}

string getNextLetter(char letter)
{
    string nextChar = "";
    if (letter == 'z')
        nextChar += 'a';
    else if (letter == 'Z')
        nextChar += 'A';
    else
        nextChar = (char)(((int)letter) + 1);
    nextChar += tolower(nextChar[0]);
    return nextChar;
}

void Movie::getMoviesOfYear(short int year)
{
    forward_list<Movie *> movies = moviesByYear[year];
    cout << "Following movies were released in " << year << ": " << endl;
    for (auto it = movies.begin(); it != movies.end(); ++it)
        cout << (*it)->getTitle() << endl;
}

void Movie::printMoviesChronologically(bool desc)
{
    // priniting reverse chronological order
    if (desc)
    {
        map<short int, forward_list<Movie *>>::reverse_iterator it;

        // rbegin() returns to the last value of map
        for (it = moviesByYear.rbegin(); it != moviesByYear.rend(); it++)
        {
            std::cout << "----------- " << it->first << " -----------"; // string (key)
            forward_list<Movie *> movies = it->second;
            for (auto it = movies.begin(); it != movies.end(); ++it)
                cout << (*it)->getTitle() << endl;
        }
    }

    // priniting in chronological order
    else
    {
        map<short int, forward_list<Movie *>>::iterator it;

        for (it = moviesByYear.begin(); it != moviesByYear.end(); it++)
        {
            std::cout << "----------- " << it->first << " -----------"; // string (key)
            forward_list<Movie *> movies = it->second;
            for (auto it = movies.begin(); it != movies.end(); ++it)
                cout << (*it)->getTitle() << endl;
        }
    }
}

void Movie::printMoviesByRating()
{
    map<string, forward_list<Movie *>, greater<string>>::iterator it;
    for (it = moviesByRating.begin(); it != moviesByRating.end(); it++)
    {
        std::cout << "----------- " << it->first << " -----------"; // string (key)
        forward_list<Movie *> movies = it->second;
        for (auto it = movies.begin(); it != movies.end(); ++it)
            cout << (*it)->getTitle() << endl;
    }
}

void Movie::getMoviesOfGenre(string g)
{
    Genre genre = convert(g);
    map<string, forward_list<Movie *>, greater<string>> moviesOfGen = moviesByGenre[genre];
    cout << "----------- " << g << " -----------" << endl;

    map<string, forward_list<Movie *>, greater<string>>::iterator it;
    for (it = moviesOfGen.begin(); it != moviesOfGen.end(); it++)
    {
        std::cout << "----------- " << it->first << " -----------"; // string (key)
        forward_list<Movie *> movies = it->second;
        for (auto it = movies.begin(); it != movies.end(); ++it)
            cout << (*it)->getTitle() << endl;
    }
}

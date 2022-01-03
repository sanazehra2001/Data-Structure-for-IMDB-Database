#include "Movie.h"
#include <cstring>

// setters
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

void Movie::setBudget(unsigned long long int bud)
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
    color = convertColor(col);
}

//getters
string Movie::getTitle()
{
    return title;
}
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
unsigned long long int Movie::getBudget()
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

// display methods
// displays contents of movie

void Movie::displayKeywords()
{
    cout << "Keywords: ";
    for (auto it = getPlotKeywords().begin(); it != getPlotKeywords().end(); ++it)
        cout << (*it) << ", ";
}

void Movie::displayActors()
{
    cout << "Actors: ";
    // finding actors
    Actor **coActors = getActor();                // all actors of this movie
    for (Actor **a = coActors; coActors + 3; ++a) //traversing through three actors of every movie
    {
        Actor *coAct = (*a);
        cout << coAct->getName() << ", "; //display names of coactor
    }
}

void Movie::displayGenre()
{
    cout << "Genre: ";
    for (auto it = getGenre().begin(); it != getGenre().end(); ++it) // traversing through
        cout << (*it) << ", ";
}

void Movie::display()
{
    string t = getTitle();
    t.pop_back();
    t.pop_back();
    cout << t << endl;
    displayGenre();
    cout << "Year: " << getTitleYear() << endl;
    cout << "IMDB Score: " << getImdbScore() << endl;
    cout << "Director: " << getDirector()->name << endl;
    cout << "Critic Reviews: " << getNumOfCriticReviews() << endl;
    cout << "Duration: " << getDuration() << endl;
    displayActors();
    cout << "Gross: " << getGross() << endl;
    cout << "Votes: " << getNumOfVotes() << endl;
    cout << "FB Likes for cast: " << getFbLikesForCast() << endl;
    cout << "Faces in poster: " << getFaceNumInPoster() << endl;
    displayKeywords();
    cout << "IMDB Link: " << getImdbLink() << endl;
    cout << "Reviews: " << getNumOfReviews() << endl;
    cout << "Language: " << getLanguage() << endl;
    cout << "Country: " << getCountry() << endl;
    cout << "Content Rating: " << getContentRating() << endl;
    cout << "Budget: " << getBudget() << endl;
    cout << "Aspect Ratio: " << getAspectRatio() << endl;
    cout << "Movie FB Likes: " << getFbLikesForMovie() << endl;
    cout << "Color: " << getColor() << endl;
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

Movie *Movie::searchMovieByTitle(string title, map<string, MovieAVL> moviesByTitle)
{
    MovieAVL avl = moviesByTitle[title]; // get avl of key
    if (avl.isEmpty())                   // if key is not present
        return NULL;
    else
    {
        forward_list<Movie *> moviesOfKey = avl.search(title); // search movies that have title string in their title
        if (moviesOfKey.empty())                               // if no such movie is found
        {
            return NULL;
        }
        else
        { // if movie is found
            return moviesOfKey.front();
        }
    }
}

Movie *Movie::searchMovieByYear(Movie *m, map<short int, forward_list<Movie *>> moviesByYear)
{
    forward_list<Movie *> movies = moviesByYear[m->getTitleYear()]; // movies of this year
    for (auto it = movies.begin(); it != movies.end(); ++it)        // iterating over movies
    {
        if ((*it)->getTitle() == m->getTitle())
        {
            return *it;
        }
    }
    return NULL;
}

Movie *Movie::searchMovieByRating(Movie *m, map<string, forward_list<Movie *>, greater<string>> moviesByRating)
{
    map<string, forward_list<Movie *>, greater<string>>::iterator it; // iterator

    for (it = moviesByRating.begin(); it != moviesByRating.end(); it++)
    {
        if (it->first == m->getContentRating())
        {
            forward_list<Movie *> movies = it->second;               // value is foward_list of Movie*
            for (auto it = movies.begin(); it != movies.end(); ++it) // iterating over movies
                if ((*it)->getTitle() == m->getTitle())
                {
                    return *it;
                }
        }
    }
    return NULL;
}

Movie *Movie::searchMovieByGenre(Movie *m, Genre g, unordered_map<Genre, map<string, forward_list<Movie *>, greater<string>>> moviesByGenre)
{
    map<string, forward_list<Movie *>, greater<string>> moviesOfGen = moviesByGenre[g]; // finding genre
    map<string, forward_list<Movie *>, greater<string>>::iterator it;

    for (it = moviesOfGen.begin(); it != moviesOfGen.end(); it++) // iterating over nested map
    {
        if (it->first == to_string(g))
        {
            forward_list<Movie *> movies = it->second;
            for (auto it = movies.begin(); it != movies.end(); ++it) // printing all movies of given genre
                if ((*it)->getTitle() == m->getTitle())
                {
                    return *it;
                }
        }
        return NULL;
    }
}

// search movie by title not necessarily complete
void Movie::searchMovie(string title, map<string, MovieAVL> moviesByTitle)
{
    // case1: string is of length one
    if (title.length() == 1)
    {
        for (auto it = moviesByTitle.lower_bound(string(1, toupper(title[0])));
             it != moviesByTitle.upper_bound(getNextLetter(title[0])); it++) //seaching for keys string with the given alphabet
        {
            MovieAVL avl = it->second; // avl of key
            avl.traverse();            // printing all movie title present in avl
        }
    }

    // case2: string of length two
    else if (title.length() == 2)
    {
        MovieAVL avl = moviesByTitle[title]; // searching for key
        if (avl.isEmpty())                   // if avl is empty then no movie with this key exists
            cout << "No matching movie" << endl;
        else
            avl.traverse(); // printing all movie title present in avl
    }

    // case3: string of length greater than 2
    else
    {
        cout << "case3"<<endl;
        MovieAVL avl = moviesByTitle[title.substr(0, 2)]; // get avl of key
        if (avl.isEmpty())                                // if key is not present
            cout << "No matching movie1." << endl;

        else
        {
            cout << "inside else"<<endl;
            forward_list<Movie *> moviesOfKey = avl.search(title); // search movies that have title string in their title
            cout << "after search"<<endl;
            if (moviesOfKey.empty())                               // if no such movie is found
                cout << "No matching movie2." << endl;
            else
            { // if movies are found, iterate over list of movies
            cout << "inside nested else"<<endl;
                for (auto it = moviesOfKey.begin(); it != moviesOfKey.end(); ++it)
                {
                    cout << "for" << endl;
                    (*it)->display();
                }
            }
        }
    }
}

void Movie::getMoviesOfYear(short int year, map<short int, forward_list<Movie *>> moviesByYear)
{
    forward_list<Movie *> movies = moviesByYear[year]; // movies of this year

    if (movies.empty())
    {
        cout << "No movies were released in " << year << endl;
        return;
    }

    cout << "Following movies were released in " << year << ": " << endl;
    for (auto it = movies.begin(); it != movies.end(); ++it) // iterating over movies
        cout << (*it)->getTitle() << endl;                   // title of movies
}

void Movie::printMoviesChronologically(bool desc, map<short int, forward_list<Movie *>> moviesByYear)
{
    // priniting reverse chronological order
    if (desc)
    {
        map<short int, forward_list<Movie *>>::reverse_iterator it;

        // rbegin() returns to the last value of map
        for (it = moviesByYear.rbegin(); it != moviesByYear.rend(); it++)
        {
            std::cout << "---------------- " << it->first << " -----------------" << endl
                      << endl;                                       // year
            forward_list<Movie *> movies = it->second;               // value is forward_list of Movie*
            for (auto it = movies.begin(); it != movies.end(); ++it) // iterating over movies
                cout << (*it)->getTitle() << endl;                   // printing title
            cout << endl
                 << endl;
        }
    }

    // priniting in chronological order
    else
    {
        map<short int, forward_list<Movie *>>::iterator it; // iterator

        for (it = moviesByYear.begin(); it != moviesByYear.end(); it++)
        {
            std::cout << "---------------- " << it->first << " ----------------" << endl; //year
            forward_list<Movie *> movies = it->second;                                    // value is foward_list of Movie*
            for (auto it = movies.begin(); it != movies.end(); ++it)                      // iterating over movies
                cout << (*it)->getTitle() << endl;                                        // printing title
            cout << endl
                 << endl;
        }
    }
}

void Movie::printMoviesByRating(map<string, forward_list<Movie *>, greater<string>> moviesByRating)
{
    map<string, forward_list<Movie *>, greater<string>>::iterator it; // iterator
    for (it = moviesByRating.begin(); it != moviesByRating.end(); it++)
    {
        std::cout << "-------------- " << it->first << " ---------------" << endl
                  << endl;                                       // rating
        forward_list<Movie *> movies = it->second;               // value is foward_list of Movie*
        for (auto it = movies.begin(); it != movies.end(); ++it) // iterating over movies
            cout << (*it)->getTitle() << endl;                   // printing title
        cout << endl
             << endl;
    }
}

void Movie::getMoviesOfGenre(string g, unordered_map<Genre, map<string, forward_list<Movie *>, greater<string>>> moviesByGenre)
{
    Genre genre = convert(g);
    map<string, forward_list<Movie *>, greater<string>> moviesOfGen = moviesByGenre[genre]; // finding genre
    cout << "----------- " << g << " -----------" << endl;

    map<string, forward_list<Movie *>, greater<string>>::iterator it;
    for (it = moviesOfGen.begin(); it != moviesOfGen.end(); it++) // iterating over nested map
    {
        std::cout << "----------- " << it->first << " -----------"; // Rating
        forward_list<Movie *> movies = it->second;
        for (auto it = movies.begin(); it != movies.end(); ++it) // printing all movies of given genre
            cout << (*it)->getTitle() << endl;
    }
}

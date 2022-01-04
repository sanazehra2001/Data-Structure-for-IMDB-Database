#include "Movie.h"
#include <cstring>
#include <cctype>

// setters
void Movie::setTitle(string t)
{
    title = t;
}

void Movie::setGenre(string g)
{
    Genre gen = convert(g);
    genre.emplace_front(gen);
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
        actors[i] = a[i];
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
string Movie::getColor()
{
    return toStringForColor(color);
}

// display methods
void Movie::displayKeywords()
{
    cout << "Keywords: ";
    for (string &a : getPlotKeywords())
        cout << a << ", ";
    cout << endl;
}

void Movie::displayActors()
{
    cout << "Actors: ";

    // finding actors
    Actor **coActors = getActor();                    // all actors of this movie
    for (Actor **a = coActors; a < coActors + 3; ++a) //traversing through three actors of every movie
    {
        Actor *coAct = (*a);
        if (coAct)                            // if actor is present
            cout << coAct->getName() << ", "; //display names of coactor
    }
    cout << endl;
}

void Movie::displayGenre()
{
    cout << "Genre: ";
    for (Genre &a : getGenre()) // looping over genre list
        cout << toString(a) << ",";
    cout << endl;
}

void Movie::displayDirector()
{
    if (getDirector()) // if movie's director is present in records
    {
        cout << "Director: ";
        cout << getDirector()->getName() << endl;
    }
}

void Movie::display()
{
    cout << getTitle() << endl;
    displayGenre();
    cout << "Year: " << getTitleYear() << endl;
    cout << "IMDB Score: " << getImdbScore() << endl;
    displayDirector();
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

// helper method to format the string to search for title
string Movie::formatStr(string str)
{
    /*
        Format:
        1. All letter are lower case expect inital letter of every word
        2. No spaces on the right or left.
    */

    // trimming spaces from start
    while (!str.empty() && std::isspace(*str.begin()))
        str.erase(str.begin());

    // trimming spaces from last
    while (!str.empty() && std::isspace(*str.rbegin()))
        str.erase(str.length() - 1);

    string result;
    for (int i = 0; i < str.length(); i++) // looping over string
    {
        result += tolower(str[i]); // lower case all letters
        if (isspace(str[i]))
        {
            result += toupper(str[i + 1]); // initial letter of every word is in upper case
            i++;
        }
    }
    result[0] = toupper(result[0]); // first letter is upper case
    return result;
}

// Implementation of methods for Movie
/* Search movie by title not necessarily complete */
void Movie::searchMovie(string title, map<string, MovieAVL> moviesByTitle)
{
    /*
    Note :All the cases will be implemented using map<string, MovieAVL> moviesByTitle, 
    that contains pointers to all movies

        Three Cases:
            Case1 : input string is of lenght 1 
            Methodology:
            1. Find all the keys in map of movie starting with this letter 
            2. If key(s) exists,traverse through the corresponding MovieAVL(s)

            Case2: input is of lenght 2
            Methodology: 
            1. Format input string.
            2. Find key in map of movies 
            3. If key exists traverse through corresponding MovieAVL

            Case 3: input of lenght greater than 2
            Methodology:
            1. Format input string.
            2. Find key by first two letters
            3. If found search string in corresponding MovieAVL. 
            The MovieAVL's search method is implemented such that it returns list of movies starting with input string.
            4. If movies of given title are found, traverse thorugh this list of movies and display them.

    */


    title = formatStr(title); // format input string

    // case1: string is of length one
    if (title.length() == 1)
    {
        title = string(1, toupper(title[0])); // first letter of key in map is capital
        string upperB = title + "z";          // upper bound for searching key

        for (auto it = moviesByTitle.lower_bound(title);
             it != moviesByTitle.upper_bound(upperB); it++) //seaching for keys starting with the given alphabet
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
        else                // if AVL is not empty
            avl.traverse(); // printing all movie title present in avl
    }

    // case3: string of length greater than 2
    else
    {
        MovieAVL avl = moviesByTitle[title.substr(0, 2)]; // get avl of key
        if (avl.isEmpty())                                // if key is not present
            cout << "No matching movie." << endl;

        else // if key is present
        {
            forward_list<Movie *> moviesOfKey = avl.search(title); // list of movies whose title is starting with input string
            if (moviesOfKey.empty())                               // if no such movie is found
                cout << "No matching movie." << endl;
            else
            { // if movies are found, iterate over list of movies
                for (auto it = moviesOfKey.begin(); it != moviesOfKey.end(); ++it)
                {
                    (*it)->display(); // calling display method of Movie class
                    cout << endl
                         << endl;
                }
            }
        }
    }
}

// function prints the title of all Movies released in the given year
void Movie::getMoviesOfYear(short int year, map<short int, forward_list<Movie *>> moviesByYear)
{
    /*
        Note: Methods will be implemented using map<short int, forward_list<Movie *>> moviesByYear,
        that has year as a key and forward_list of pointer to all movies released in the corresponding year.

        Methodology:
        1. Search for the given year in map.
        2. If key is present, it returns a forward_list of pointer to movies.
        3. Traverse through this list and print the title of each movie.
    */

    forward_list<Movie *> movies = moviesByYear[year]; // movies of this year

    if (movies.empty()) // if year is not present in the map.
    {
        cout << "No movie was released in " << year << endl;
        return;
    }

    // if year is found in map
    cout << "Following movies were released in " << year << ": " << endl;
    for (auto it = movies.begin(); it != movies.end(); ++it) // iterating over movies of given year
        cout << (*it)->getTitle() << endl;                   // print title of movies
}

// Function prints movies in chronological order, increasing or decreasing specified by bool as first argument
void Movie::printMoviesChronologically(bool desc, map<short int, forward_list<Movie *>> moviesByYear)
{
    /*
        Note: Method will be implemented using map<short int, forward_list<Movie *>> moviesByYear,
        having year as a key, keys are sorted in increasing order.

        Cases:
        Case 1: desc is true (Years in decreasing order)
        Methodology:
            1. Traverse through moviesByYear from last key to first key i.e in reverse order,
            2. Traverse the lists of pointer to Movie corresponding to each key an print the title of movie.


        Case 2: desc is false (Years in increasing order) 
         Methodology:
            1. Traverse through moviesByYear.
            2. Traverse the lists of pointer to Movie corresponding to each key an print the title of movie.                
    */

    // printing reverse chronological order
    if (desc)
    {
        map<short int, forward_list<Movie *>>::reverse_iterator it; // iterator for map

        // rbegin() returns to the last value of map
        for (it = moviesByYear.rbegin(); it != moviesByYear.rend(); it++)
        {
            std::cout << "---------------- " << it->first << " -----------------" << endl
                      << endl;                                       // year (key)
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
        map<short int, forward_list<Movie *>>::iterator it; // iterator for map

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
    /*
        Note: This Method will be implemented using map<string, forward_list<Movie *>, greater<string>> moviesByRating,
        that has Rating as a key and forward_list of pointer to all movies having given rating. 
        The keys are sorted in increasing order of rating.

        Methodology:
        1. Traverse through the map, print key (Rating)
        2. For each key (Rating), traverse thorugh the forward_list of pointer to Movie and print the title
    */

    map<string, forward_list<Movie *>, greater<string>>::iterator it; // iterator
    for (it = moviesByRating.begin(); it != moviesByRating.end(); it++)
    {
        std::cout << "-------------- " << it->first << " ---------------" << endl
                  << endl;                                       // rating (key)
        forward_list<Movie *> movies = it->second;               // value is foward_list of Movie*
        for (auto it = movies.begin(); it != movies.end(); ++it) // iterating over movies
            cout << (*it)->getTitle() << endl;                   // printing title
        cout << endl
             << endl;
    }
}

void Movie::getMoviesOfGenre(string g, unordered_map<Genre, map<string, forward_list<Movie *>, greater<string>>> moviesByGenre)
{
    /*
        Note: This Method will be implemented using unordered_map<Genre, map<string, forward_list<Movie *>, greater<string>>> moviesByGenre,
        that has Genre as a key and nested map of rating with value of forward_list of pointer to Movie as value.

        Methodology:
        1. Traverse through the outer map, find genre
        2. If genre is valid, traverse through the nested map and print titles of all movies against each rating
    */

    Genre genre = convert(g); //convert string to Genre
    if (genre == Genre::Invalid) // if string is not a valud genre
    {
        cout << "Invalid Genre" << endl;
        return;
    }

    // for valid genre
    map<string, forward_list<Movie *>, greater<string>> moviesOfGen = moviesByGenre[genre]; // finding genre
    cout << "----------- " << g << " -----------" << endl;                                  // print genre

    map<string, forward_list<Movie *>, greater<string>>::iterator it; // iterator for nested map
    for (it = moviesOfGen.begin(); it != moviesOfGen.end(); it++)     // iterating over nested map
    {
        std::cout << "----------- " << it->first << " -----------" << endl; // Rating
        forward_list<Movie *> movies = it->second;                          // forward_list of rating
        for (Movie *&a : movies)                                            // iterating over forward_list of movies
            cout << a->getTitle() << endl;                                  // printing title
        cout << endl;
    }
    cout << endl;
}
#include <iostream>
#include <fstream>
#include <sstream>
#include <forward_list>

#include "Movie.cpp"
#include "Director.cpp"
#include "Actor.cpp"
#include "AVL.cpp"

using namespace std;

//maps of movies
map<string, MovieAVL> moviesByTitle;                                                     // avl sorted by title
map<short int, forward_list<Movie *>> moviesByYear;                                      // keys sorted by year
map<string, forward_list<Movie *>, greater<string>> moviesByRating;                      // keys sorted by rating
unordered_map<Genre, map<string, forward_list<Movie *>, greater<string>>> moviesByGenre; // nested maps' keys sorted on rating

//map of director
unordered_map<string, DirectorAVL> allDirectors; //avl sorted on name

//map of actor
unordered_map<string, ActorAVL> allActors; // avl sorted on actor name

void setMovieByTitle(Movie *m)
{
    /*
        Inserts the pointers of all non-duplicate movies to the map "moviesByTitle"
    */

    string name = m->getTitle();

    // key of the map contains two alphabets;
    // if length of the title is less than that, it is corrected
    while (name.length() < 2)
        name.append(" ");

    //two-alphabet key has been taken to avoid clustering/traffic
    string key = name.substr(0, 2);

    if (moviesByTitle.find(key) == moviesByTitle.end())
    { // if the key is not present in the map
        // insert the movie pointer in a new AVL and store that AVL in the map
        MovieAVL movAVL;
        movAVL.insert(m);
        moviesByTitle.insert({key, movAVL});
    }
    else
        // insert the movie pointer in the AVL of relevant key
        moviesByTitle.at(key).insert(m);
}

void setMovieByYear(Movie *m)
{
    /*
        Inserts the pointers of all movies that have their year specified to the map "moviesByYear"
    */

    // the key of the map is release year
    short int key = m->getTitleYear();

    if (moviesByYear.find(key) == moviesByYear.end())
    {
        // if the key is not present in the map
        // insert the movie pointer in a new linkedList and store that linkedList in the map
        forward_list<Movie *> movList;
        movList.emplace_front(m);
        moviesByYear.insert({key, movList});
    }
    else
    {
        // insert the movie pointer in the linkedList of relevant key
        moviesByYear.at(key).emplace_front(m);
    }
}

void setMovieByRating(Movie *m)
{
    /*
        Inserts the pointers of all movies that have their rating specified to the map "moviesByRating"
    */

    // the key of the map is content rating
    string key = m->getContentRating();

    if (moviesByRating.find(key) == moviesByRating.end())
    {
        // if the key is not present in the map
        // insert the movie pointer in a new linkedList and store that linkedList in the map
        forward_list<Movie *> movList;
        movList.emplace_front(m);
        moviesByRating.insert({key, movList});
    }

    else
    {
        // insert the movie pointer in the linkedList of relevant key
        moviesByRating.at(key).emplace_front(m);
    }
}

void setMovieByGenre(Movie *m, Genre g)
{
    /*
        Inserts the pointers of all movies that have their genre specified to the map "moviesByGenre"
    */

    // key of the map is genre
    Genre key = g;

    if (moviesByGenre.find(key) == moviesByGenre.end())
    {
        // if the key is not present in the unordered map
        // insert the movie pointer in a new linkedList and store that linkedList in the map sorted on rating
        // then store that map in the map for genre
        forward_list<Movie *> movList;
        movList.emplace_front(m);
        map<string, forward_list<Movie *>, greater<string>> sortedOnRating;
        sortedOnRating.insert({m->getContentRating(), movList});
        moviesByGenre.insert({g, sortedOnRating});
    }
    else
    {
        // insert the movie at appropriate key
        map<string, forward_list<Movie *>, greater<string>> map = moviesByGenre[key];
        forward_list<Movie *> list = map[m->getContentRating()];
        list.emplace_front(m);
        map[m->getContentRating()] = list;
        moviesByGenre[key] = map;
    }
}

char displayMenu()
{
    /*
        Repetitively allows the user to perform from one of the methods listed below
    */
    cout << "----------------------------MAIN MENU----------------------------\n";
    cout << " 1. Search profile of an actor\n";
    cout << " 2. Search coactors of an actor\n";
    cout << " 3. Search unique coactors\n";
    cout << " 4. All coactors of the coactors of an actor\n";
    cout << " 5. Check if A and B are coactors\n";
    cout << " 6. Search director\n";
    cout << " 7. Directors who have directed movies of a certain genre type\n";
    cout << " 8. Search a movie\n";
    cout << " 9. Search movies released in a given year\n";
    cout << "10. Print movies year-wise\n";
    cout << "11. Search movies based on genre\n";
    cout << "12. Print movies rating-wise\n";
    cout << "13. Print movies of a certain genre rating-wise\n";
    cout << endl;
    cout << "14. Exit\n";
    cout << endl
         << endl;
    cout << "Select an option: ";
    int choice;
    cin >> choice;
    cout << endl
         << endl;
    return choice;
}

int main()
{
    int index;
    string line;
    string word;
    float val;
    short int year;
    ifstream file("IMDB_Top5000-SEECS.csv");

    // to store 28 colms of each record
    string colmVals[28];

    // temp variables for director and actors
    string name;
    int likes;

    if (file.is_open())
    {
        // gets the row of column headings
        getline(file, line);

        // reads an entire row from file and stores it in line
        while (getline(file, line))
        {
            // create a new Movie, Director and array of Actors for each record
            Movie *m = new Movie();
            Director *d;
            Actor *actors[3];

            index = 0;
            int indexActor = 0;

            // breaks the line into words
            stringstream s(line);

            // the comma separated values are stored in the array
            while (getline(s, word, ','))
                colmVals[index++] = word;

            // setting attributes of each Movie

            // remove special character at the end of each title
            colmVals[0].pop_back();
            colmVals[0].pop_back();
            m->setTitle(Movie::formatStr(colmVals[0]));

            // get '|' separated genres and store them in a linked list
            stringstream genres(colmVals[1]);
            while (getline(genres, word, '|'))
                m->setGenre(word);

            // store the numerical values only if not blank
            if (colmVals[2] != "")
                m->setTitleYear(stoi(colmVals[2]));
            if (colmVals[3] != "")
                m->setImdbScore(stof(colmVals[3]));

            // if the Director has been specified in the dataset
            if ((colmVals[4] != "") && (colmVals[5] != ""))
            {
                name = colmVals[4];
                likes = stoi(colmVals[5]);

                // the key of the Director map is the first two alphabets of the name
                string key = name.substr(0, 2);

                // find if the director has already been added to the map
                d = Director::searchDir(name, allDirectors);

                if (d == NULL)
                {
                    // if director not found
                    // create a new director
                    d = new Director(name, likes);

                    if (allDirectors.find(key) == allDirectors.end())
                    {
                        // if the key is not present in the map
                        // create an AVL, store director pointer in the new AVL, and store this AVL in the map
                        DirectorAVL dirAVL;
                        dirAVL.insert(d);
                        allDirectors.insert({key, dirAVL});
                    }
                    else
                    {
                        // insert director pointer in the AVL of appropriate key
                        allDirectors.at(key).insert(d);
                    }
                }
                // set director of the movie
                // and add movie to list of directed movies of the Director
                d->addMovie(m);
                m->setDirector(d);
            }
            else
                m->setDirector(NULL);

            // store the numerical values only if not blank
            if (colmVals[6] != "")
                m->setNumOfCriticReviews(stoi(colmVals[6]));

            if (colmVals[7] != "")
                m->setDuration(stoi(colmVals[7]));

            // for the three actors in the dataset
            // step is set to 2 to skip the colm of likes
            for (int i = 8; i < 14; i += 2)
            {
                // if the actor has been specified
                if ((colmVals[i] != "") && (colmVals[i + 1] != ""))
                {
                    name = colmVals[i];
                    likes = stoi(colmVals[i + 1]);

                    // the key of the map is the first two alphabets of Actor name
                    string key = name.substr(0, 2);

                    // search if the actor is already part of Actor map
                    actors[indexActor] = Actor::searchActor(name, allActors);

                    if (actors[indexActor] == NULL)
                    {
                        // if actor is not found
                        actors[indexActor] = new Actor(name, likes);

                        if (allActors.find(key) == allActors.end())
                        {
                            // if the key is not present in the map
                            // create an AVL, store actor pointer in the new AVL, and store this AVL in the map
                            ActorAVL actAVL;
                            actAVL.insert(actors[indexActor]);
                            allActors.insert({key, actAVL});
                        }
                        else
                        {
                            // insert actor pointer in the AVL of appropriate key
                            allActors.at(key).insert(actors[indexActor]);
                        }
                    }
                    // add movie to the movie list of actor
                    actors[indexActor]->addMovie(m);
                }
                else
                {
                    actors[indexActor] = NULL;
                }
                indexActor++;
            }

            m->setActor(actors);

            // store the numerical values only if not blank
            if (colmVals[14] != "")
                m->setGross(stoul(colmVals[14]));

            if (colmVals[15] != "")
                m->setNumOfVotes(stoi(colmVals[15]));

            if (colmVals[16] != "")
                m->setFbLikesForCast(stoi(colmVals[16]));

            if (colmVals[17] != "")
                m->setFaceNumInPoster(stoi(colmVals[17]));

            // get '|' separated keywords and store them in a linked list
            if (colmVals[18] != "")
            {
                stringstream keywords(colmVals[18]);
                while (getline(keywords, word, '|'))
                    m->setPlotKeywords(word);
            }

            m->setImdbLink(colmVals[19]);

            if (colmVals[20] != "")
                m->setNumOfReviews(stoi(colmVals[20]));

            m->setLanguage(colmVals[21]);
            m->setCountry(colmVals[22]);

            if (colmVals[23] != "")
                m->setContentRating(colmVals[23]);
            else
                m->setContentRating("Unrated");

            if (colmVals[24] != "")
                m->setBudget(stoll(colmVals[24]));

            if (colmVals[25] != "")
                m->setAspectRatio(stof(colmVals[25]));

            if (colmVals[26] != "")
                m->setFbLikesForMovie(stoi(colmVals[26]));

            m->setColor(colmVals[27]);

            // insert movie pointers to relevant maps
            setMovieByTitle(m);

            if (m->getTitleYear() != 0)
                setMovieByYear(m);

            if (m->getContentRating() != "Unrated")
                setMovieByRating(m);

            if (!m->getGenre().empty())
            {
                for (Genre &a : m->getGenre())
                    setMovieByGenre(m, a);
            }
        }

        file.close();
    }

    else
    {
        cout << "Unable to open file";
    }

    // actor functions
    // Actor::displayAllActors(allActors); // tested
    // Actor::searchActor("Robert Downey Jr.", allActors, true); // tested
    // Actor::displayCoActors("Demi Moore", allActors); //tested
    // Actor::displayCoActors("David Keith", allActors); //tested
    // Actor::getUniqueCoActors("Jennifer Jason Leigh", allActors); //tested
    // Actor::getCoActorsOfCoActors("Vincent Schiavelli", allActors); //tested
    // cout << Actor::isCoActor("Vincent Schiavelli", "Judge Reinhold", allActors); //tested

    // director functions
    // Director::searchDir("Christopher Nolan", allDirectors, true); //tested
    // Director::getDirectorOfGenre("Action", moviesByGenre);

    // movie functions
    // Movie::searchMovie("Star Wars: Episode VII - The Force Awakens", moviesByTitle); //tested, provided genres are added properly
    // Movie::searchMovie("Iron Man 3", moviesByTitle); //tested, provided genres are added properly
    // Movie::getMoviesOfYear(20151, moviesByYear); //tested
    // Movie::printMoviesChronologically(true, moviesByYear); //tested
    // Movie::getMoviesOfGenre("Short", moviesByGenre);    //tested, to be tested for invalid genre
    // Movie::printMoviesByRating(moviesByRating); //tested
    //cout << "after" << endl;

    int choice = 0;
    while (choice != 14)
    {
        choice = displayMenu();
        string n;
        string name2;
        bool isCoactor;
        switch (choice)
        {
            // methods of Actor
        case 1:
            cout << "Enter the name of the actor: " << endl;
            cin.ignore();
            getline(cin, n);
            Actor::searchActor(n, allActors, true);
            break;

        case 2:
            cout << "Enter the name of the actor: " << endl;
            cin.ignore();
            getline(cin, n);
            Actor::displayCoActors(n, allActors);
            break;

        case 3:
            cout << "Enter the name of the actor: " << endl;
            cin.ignore();
            getline(cin, n);
            Actor::getUniqueCoActors(n, allActors);
            break;

        case 4:
            cout << "Enter the name of the actor: " << endl;
            cin.ignore();
            getline(cin, n);
            Actor::getCoActorsOfCoActors(n, allActors);
            break;

        case 5:
            cout << "Enter the name of the actor A: " << endl;
            cin.ignore();
            getline(cin, n);
            cout << "\nEnter the name of the actor B: " << endl;
            //cin.ignore();
            getline(cin, name2);
            cout << endl;
            isCoactor = Actor::isCoActor(n, name2, allActors);
            if (isCoactor)
                cout << n << " and " << name2 << " are coactors\n\n";
            else
                cout << n << " and " << name2 << " are not coactors\n\n";
            break;

            //methods of Director
        case 6:
            cout << "Enter the name of the director: " << endl;
            cin.ignore();
            getline(cin, n);
            Director::searchDir(n, allDirectors, true);
            cout << endl << endl;
            break;

        case 7:
            cout << "Enter genre: " << endl;
            cin.ignore();
            getline(cin, n);
            Director::getDirectorOfGenre(n, moviesByGenre);
            cout << endl << endl;
            break;

            //Methods of Movie
        case 8:
            cout << "Enter movie name: " << endl;
            cin.ignore();
            getline(cin, n);
            Movie::searchMovie(n, moviesByTitle);
            break;

        case 9:
            cout << "Enter year: " << endl;
            cin.ignore();
            getline(cin, n);
            Movie::getMoviesOfYear(stoi(n), moviesByYear);
            break;

        case 10:
            cout << "a. Ascending order\n";
            cout << "b. Descending order\n";
            cout << endl
                 << endl;

            char opt;
            cin >> opt;

            if (opt == 'a')
                Movie::printMoviesChronologically(false, moviesByYear);
            else if (opt == 'b')
                Movie::printMoviesChronologically(true, moviesByYear);
            else
            {
                cout << "Invalid! Please select a correct option." << endl;
                choice = 10;
            }
            break;

        case 11:
            cout << "Enter genre: " << endl;
            cin.ignore();
            getline(cin, n);
            Movie::getMoviesOfGenre(n, moviesByGenre);
            break;

        case 12:
            Movie::printMoviesByRating(moviesByRating);
            break;

        case 13:
            cout << "Enter genre: " << endl;
            cin.ignore();
            getline(cin, n);
            Movie::getMoviesOfGenre(n, moviesByGenre);
            break;

        case 14:
            exit(0);

        default:
            cout << "Invalid! Please select a correct option." << endl;
        }
    }
    return 0;
}

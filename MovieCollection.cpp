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
    Movie *moviePtr;
    string name = m->getTitle();
    string key = name.substr(0, 2);

    moviePtr = Movie::searchMovieByTitle(name, moviesByTitle);

    if (moviePtr == NULL)
    { //movies not found

        if (moviesByTitle.find(key) == moviesByTitle.end())
        { // if the key is not present in the hashmap
            MovieAVL movAVL;
            movAVL.insert(m);
            moviesByTitle.insert({key, movAVL});
        }

        else
        {
            moviesByTitle.at(key).insert(m);
        }
    }
}

void setMovieByYear(Movie *m)
{
    Movie *moviePtr;
    short int key = m->getTitleYear();

    moviePtr = Movie::searchMovieByYear(m, moviesByYear);

    if (moviePtr == NULL)
    { //movies not found

        if (moviesByYear.find(key) == moviesByYear.end())
        { // if the key is not present in the hashmap
            forward_list<Movie *> movList;
            movList.emplace_front(m);
            moviesByYear.insert({key, movList});
        }

        else
        {
            moviesByYear.at(key).emplace_front(m);
        }
    }
}

void setMovieByRating(Movie *m)
{
    Movie *moviePtr;
    string key = m->getContentRating();

    moviePtr = Movie::searchMovieByRating(m, moviesByRating);

    if (moviePtr == NULL)
    { //movies not found

        if (moviesByRating.find(key) == moviesByRating.end())
        { // if the key is not present in the hashmap
            forward_list<Movie *> movList;
            movList.emplace_front(m);
            moviesByRating.insert({key, movList});
        }

        else
        {
            moviesByRating.at(key).emplace_front(m);
        }
    }
}

void setMovieByGenre(Movie *m, Genre g)
{
    Movie *moviePtr;
    Genre key = g;

    moviePtr = Movie::searchMovieByGenre(m, g, moviesByGenre);

    if (moviePtr == NULL)
    { //movies not found

        if (moviesByGenre.find(key) == moviesByGenre.end())
        { // if the key is not present in the hashmap
            forward_list<Movie *> movList;
            movList.emplace_front(m);
            map<string, forward_list<Movie *>, greater<string>> sortedOnRating;
            sortedOnRating.insert({m->getContentRating(), movList});
            moviesByGenre.insert({g, sortedOnRating});
        }

        else
        {
            moviesByGenre.at(key).at(m->getContentRating()).emplace_front(m);
        }
    }
}

char displayMenu()
{
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
    cout << endl
         << endl;
    cout << "Select an option: ";
    char choice;
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
    string colmVals[28];
    ifstream file("IMDB_Top5000-SEECS.csv");

    string name;
    int likes;

    if (file.is_open())
    {
        getline(file, line); // gets the row of column headings

        while (getline(file, line)) // reads an entire row and stores it in line
        {
            index = 0;
            Movie *m = new Movie(); // create a new Movie node for each row
            Director *d;
            Actor *actors[3];

            stringstream s(line); // breaks the line into words

            while (getline(s, word, ',')) // the comma separated values are stored at consecutive array index
                colmVals[index++] = word;

            // setting attributes of each Movie
            colmVals[0].pop_back();
            colmVals[0].pop_back();
            m->setTitle(colmVals[0]);

            stringstream genres(colmVals[1]);
            while (getline(genres, word, '|')) // add genres to the list
            {

                m->setGenre(word);
                // cout << word<<endl;
            }

            if (colmVals[2] != "")
                m->setTitleYear(stoi(colmVals[2]));
            if (colmVals[3] != "")
                m->setImdbScore(stof(colmVals[3]));

            // cout << m->getTitle()<<", ";

            if ((colmVals[4] != "") && (colmVals[5] != ""))
            {
                name = colmVals[4];
                likes = stoi(colmVals[5]);
                string key = name.substr(0, 2);
                d = Director::searchDir(name, allDirectors);
                if (d == NULL)
                { // director not found

                    d = new Director(name, likes);

                    if (allDirectors.find(key) == allDirectors.end())
                    { // if the key is not present in the hashmap
                        DirectorAVL dirAVL;
                        dirAVL.insert(d);
                        allDirectors.insert({key, dirAVL});
                    }
                    else
                    {
                        allDirectors.at(key).insert(d);
                    }
                }
                d->addMovie(m);
                m->setDirector(d);
            }

            // cout << m.getDirector()->getName();

            if (colmVals[6] != "")
                m->setNumOfCriticReviews(stoi(colmVals[6]));

            if (colmVals[7] != "")
                m->setDuration(stoi(colmVals[7]));

            int indexActor = 0;
            for (int i = 8; i < 14; i += 2)
            {
                if ((colmVals[i] != "") && (colmVals[i + 1] != ""))
                {
                    name = colmVals[i];
                    likes = stoi(colmVals[i + 1]);
                    string key = name.substr(0, 2);
                    actors[indexActor] = Actor::searchActor(name, allActors);

                    if (actors[indexActor] == NULL)
                    { // if actor is not found
                        actors[indexActor] = new Actor(name, likes);

                        if (allActors.find(key) == allActors.end())
                        { // if key is not present in the hashmap
                            ActorAVL actAVL;
                            actAVL.insert(actors[indexActor]);
                            allActors.insert({key, actAVL});
                        }
                        else
                        {
                            allActors.at(key).insert(actors[indexActor]);
                        }
                    }
                    actors[indexActor]->addMovie(m);
                    indexActor++;
                }
            }
            m->setActor(actors);

            if (colmVals[14] != "")
                m->setGross(stoul(colmVals[14]));

            if (colmVals[15] != "")
                m->setNumOfVotes(stoi(colmVals[15]));

            if (colmVals[16] != "")
                m->setFbLikesForCast(stoi(colmVals[16]));

            if (colmVals[17] != "")
                m->setFaceNumInPoster(stoi(colmVals[17]));

            if (colmVals[18] != "")
            {
                stringstream keywords(colmVals[18]);
                while (getline(keywords, word, '|')) // | separated keywords are added to the list
                {
                    m->setPlotKeywords(word);
                }
            }

            m->setImdbLink(colmVals[19]);

            if (colmVals[20] != "")
                m->setNumOfReviews(stoi(colmVals[20]));

            m->setLanguage(colmVals[21]);
            m->setCountry(colmVals[22]);
            m->setContentRating(colmVals[23]);

            if (colmVals[24] != "")
                m->setBudget(stoll(colmVals[24]));

            if (colmVals[25] != "")
                m->setAspectRatio(stof(colmVals[25]));

            if (colmVals[26] != "")
                m->setFbLikesForMovie(stoi(colmVals[26]));

            m->setColor(colmVals[27]);

            // cout << "before isnertion"<<endl;
            //insert movie pointers to relevant maps
            setMovieByTitle(m);
            // cout << "after title"<<endl;
            setMovieByYear(m);
            // cout << "after year"<<endl;
            setMovieByRating(m);
            // cout << "after rating"<<endl;

            // for (auto it = m->getGenre().begin(); it != m->getGenre().end(); ++it)
            // {
            //     setMovieByGenre(m, (*it));
            //     cout << "genre"<<endl;
            // }
        }

        file.close();
        cout << "insertion completed" << endl;
    }

    else
    {
        cout << "Unable to open file";
    }

    // actor functions
    // Actor::displayAllActors(allActors); // tested
    // Actor::searchActor("Vincent Schiavelli", allActors, true); // tested
    // Actor::displayCoActors("Demi Moore", allActors); //tested
    // Actor::displayCoActors("Jennifer Jason Leig", allActors); //tested
    // Actor::getUniqueCoActors("Jennifer Jason Leigh", allActors); //tested
    // Actor::getCoActorsOfCoActors("Vincent Schiavelli", allActors); //tested
    // cout << Actor::isCoActor("Vincent Schiavelli", "Judge Reinhold", allActors); //tested
 
    // director functions
    // Director::searchDir("Christopher Nolan", allDirectors, true); //tested
    // Director::getDirectorOfGenre("Action", moviesByGenre);

    // movie functions
    // Movie::searchMovie("The", moviesByTitle);
    // Movie::getMoviesOfYear(20151, moviesByYear); //tested
    // Movie::printMoviesChronologically(true, moviesByYear); //tested
    // Movie::getMoviesOfGenre("Action", moviesByGenre);
    // Movie::printMoviesByRating(moviesByRating); //tested
    cout << "after" << endl;

    // char choice;
    // string name;
    // string name2;

    // choice = displayMenu();
    // switch (choice)
    // {
    //     // methods of Actor
    // case 1:
    //     cout << "Enter the name of the actor: ";
    //     cin >> name;
    //     Actor::searchActor(name, allActors, true);
    //     break;

    // case 2:
    //     cout << "Enter the name of the actor: ";
    //     cin >> name;
    //     Actor::getCoActors(name, allActors);
    //     break;

    // case 3:
    //     cout << "Enter the name of the actor: ";
    //     cin >> name;
    //     Actor::getUniqueCoActors(name);
    //     break;

    // case 4:
    //     cout << "Enter the name of the actor: ";
    //     cin >> name;
    //     Actor::getCoActorsOfCoActors(name);
    //     break;

    // case 5:
    //     cout << "Enter the name of the actor A: ";
    //     cin >> name;
    //     cout << "\nEnter the name of the actor B: ";
    //     cin >> name2;
    //     Actor::isCoActor(name, name2);
    //     break;

    //     //methods of Director
    // case 6:
    //     cout << "Enter the name of the director: ";
    //     cin >> name;
    //     Director::searchDir(name, allDirectors);
    //     break;

    // case 7:
    //     cout << "Enter genre: ";
    //     cin >> name;
    //     Director::getDirectorOfGenre(name);
    //     break;

    //     //Methods of Movie
    // case 8:
    //     cout << "Enter movie name: ";
    //     cin >> name;
    //     Movie::searchMovie(name, moviesByTitle);
    //     break;

    // case 9:
    //     cout << "Enter year: ";
    //     cin >> name;
    //     Movie::getMoviesOfYear(stoi(name), moviesByYear);
    //     break;

    // case 10:
    //     cout << "a. Ascending order\n";
    //     cout << "b. Descending order\n";
    //     cout << endl
    //          << endl;

    //     char opt;
    //     cin >> opt;

    //     if (opt == 'a')
    //         Movie::printMoviesChronologically(false, moviesByYear);
    //     else if (opt == 'b')
    //         Movie::printMoviesChronologically(true, moviesByYear);
    //     else
    //     {
    //         cout << "Invalid! Please select a correct option.";
    //         choice = 10;
    //     }
    //     break;

    // case 11:
    //     cout << "Enter genre: ";
    //     cin >> name;
    //     Movie::getMoviesOfGenre(name, moviesByGenre);
    //     break;

    // case 12:
    //     Movie::printMoviesByRating(moviesByRating);
    //     break;

    // case 13:
    //     cout << "Enter genre: ";
    //     cin >> name;
    //     Movie::getMoviesOfGenre(name, moviesByGenre);
    //     break;

    // default:
    //     cout << "Invalid! Please select a correct option.";
    // }

    // return 0;
}

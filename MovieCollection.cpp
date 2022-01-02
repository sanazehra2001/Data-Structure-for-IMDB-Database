#include <iostream>
#include <fstream>
#include <sstream>

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

//map od director
unordered_map<string, DirectorAVL> allDirectors; //avl sorted on name

//map of actor
unordered_map<string, ActorAVL> allActors; // avl sorted on actor name

Director *addDirector(string name, int likes, Movie *m)
{
    string key = name.substr(0, 2);
    Director *d;

    if (allDirectors.find(key) == allDirectors.end())
    {
        //key is not present, create key-avl pair
        Director dir(name, likes);       //create a new director
        DirectorAVL avl;                 //create an AVL for that key
        avl.insert(&dir);                //add the director to the AVL
        allDirectors.insert({key, avl}); //finally add this newly created AVL to the map

        d = &dir;
    }
    else
    { // the key already exists

        Director *dir = Director::searchDir(name, allDirectors); // pointer to the found dir or NULL otherwise
        d = dir;

        if (dir == NULL)
        { // if director is found
            Director dir(name, likes);
            allDirectors.at(key).insert(&dir);
            d = &dir;
        }
    }
    d->addMovie(m);
    return d;
}

Actor *addActor(string name, int likes, Movie *m)
{
    string key = name.substr(0, 2);
    Actor *a;

    if (allActors.find(key) == allActors.end())
    {
        //key is not present, create key-avl pair
        Actor actor(name, likes); //create a new actor
        ActorAVL avl;             //create an AVL for that key
        avl.insert(&actor);       //add the actor to the AVL
        allActors.insert({key, avl});

        a = &actor;
    }

    else
    {                                                       // the key already exists
        Actor *actor = Actor::searchActor(name, allActors); // pointer to the found actor or NULL otherwise
        a = actor;

        if (actor == NULL)
        { // if actor is found
            Actor actor(name, likes);
            allActors.at(key).insert(&actor);
            a = &actor;
        }
    }
    a->addMovie(m);
    return a;
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

    if (file.is_open())
    {
        getline(file, line); // gets the row of column headings

        while (getline(file, line)) // reads an entire row and stores it in line
        {
            index = 0;
            Movie m; // create a new Movie node for each row

            stringstream s(line); // breaks the line into words

            while (getline(s, word, ',')) // the comma separated values are stored at consecutive array index
            {
                colmVals[index++] = word;
            }

            // setting attributes of each Movie
            m.setTitle(colmVals[0]);

            stringstream genres(colmVals[1]);
            while (getline(genres, word, '|')) // add genres to the list
                m.setGenre(word);

            if (colmVals[2] != "")
                m.setTitleYear(stoi(colmVals[2]));
            if (colmVals[3] != "")
                m.setImdbScore(stof(colmVals[3]));

            if ((colmVals[4] != "") && (colmVals[5] != ""))
                m.setDirector(addDirector(colmVals[4], stoi(colmVals[5]), &m));

            if (colmVals[6] != "")
            {
                m.setNumOfCriticReviews(stoi(colmVals[6]));
            }

            if (colmVals[7] != "")
                m.setDuration(stoi(colmVals[7]));

            Actor *actors[3];
            int actorIndex = 0;
            for (int i = 8; i < 14; i += 2) // add actors to the array
            {
                if (colmVals[i] != "")
                {
                    actors[actorIndex++] = addActor(colmVals[i], stoi(colmVals[i + 1]), &m);
                }
            }

            m.setActor(actors);

            if (colmVals[14] != "")
                m.setGross(stoul(colmVals[14]));

            if (colmVals[15] != "")
                m.setNumOfVotes(stoi(colmVals[15]));

            if (colmVals[16] != "")
                m.setFbLikesForCast(stoi(colmVals[16]));

            if (colmVals[17] != "")
                m.setFaceNumInPoster(stoi(colmVals[17]));

            if (colmVals[18] != "")
            {
                stringstream keywords(colmVals[18]);
                while (getline(keywords, word, '|')) // | separated keywords are added to the list
                {
                    m.setPlotKeywords(word);
                }
            }

            m.setImdbLink(colmVals[19]);

            if (colmVals[20] != "")
                m.setNumOfReviews(stoi(colmVals[20]));

            m.setLanguage(colmVals[21]);
            m.setCountry(colmVals[22]);
            m.setContentRating(colmVals[23]);

            if (colmVals[24] != "")
                m.setBudget(stoll(colmVals[24]));

            if (colmVals[25] != "")
                m.setAspectRatio(stof(colmVals[25]));

            if (colmVals[26] != "")
                m.setFbLikesForMovie(stoi(colmVals[26]));

            m.setColor(colmVals[27]);
        }
        file.close();
    }

    else
    {
        cout << "Unable to open file";
    }

    return 0;
}
